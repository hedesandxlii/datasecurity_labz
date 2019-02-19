/*
 * Shows user info from local pwfile.
 *  
 * Usage: userinfo username
 */

#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>
#include "pwdblib.h"   /* include header declarations for pwdblib.c */

/* Define some constants. */
#define USERNAME_SIZE (32)
#define NOUSER (-1)


int login_user(const char *username)
{
  struct pwdb_passwd *p = pwdb_getpwnam(username);
  if (p != NULL) {
      char *password = malloc(20); // passwordsize 20. Why not?

      password = getpass("password: ");
      char *pwhash = malloc(20);

      pwhash = crypt(password, username);
      printf("%s", pwhash);
      if (strcmp(p->pw_passwd, pwhash) == 0) {
          printf("\nDucking success mate\n");
      } else {
          printf("\nDucking wrong mate\n");
      }

    // Släpp minnarne lös, det är vår!
    //free(password);
    //free(pwhash);
	return 0;
  } else {
    return NOUSER;
  }
}



void read_username(char *username)
{
  printf("login: ");
  fgets(username, USERNAME_SIZE, stdin);

  /* remove the newline included by getline() */
  username[strlen(username) - 1] = '\0';
}

int main(int argc, char **argv)
{
  char username[USERNAME_SIZE];
  
  /* 
   * Write "login: " and read user input. Copies the username to the
   * username variable.
   */
  read_username(username);

  if (login_user(username) == NOUSER) {
    printf("\nFound no user with name: %s\n", username); 
    return 0;
  }
}
  

  
