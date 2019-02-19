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
      char *password; // passwordsize 20. Why not?
      password = getpass("password: ");

      char salt[2];
      salt[0] = (char)password[0];
      salt[1] = (char)password[1];

      char *pwhash;
      pwhash = crypt(password, salt);
      
      printf("%s\n", pwhash);

      if (strcmp(p->pw_passwd, pwhash) == 0) {
        printf("\nDucking success mate\n");
      } else {
        printf("\nDucking fail mate\n");
      }
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
  

	char  *str = "tjena";
	char  sub[3];
	memcpy( sub, &str[0], 2);
	sub[2] = '\0';

	

	printf("%s\n",sub);

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
  

  
