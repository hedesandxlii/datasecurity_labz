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

char *substring(char *string, int position, int length){


	char *pointer;
	int c;
		

	pointer = malloc(length+1);

	if(pointer == NULL)
		{
		printf("fel fel fel");
		exit(1);
	}

	for(c=0; c<length ; c++)
	{
		*(pointer+c) = *(string+position-1);
		string++;
	}

	*(pointer+c) = '\0';

	return pointer;



}
int login_user(const char *username)
{
  struct pwdb_passwd *p = pwdb_getpwnam(username);
  if (p != NULL) {
      char *password; // passwordsize 20. Why not?
      password = getpass("password: ");

      char *salt;

      memcpy(salt, password, 2);

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
  

  
