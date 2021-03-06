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
#define MAX_PW_AGE (10)
#define MAX_PW_ATTEMPTS (5)

int login_user(const char *username)
{
    struct pwdb_passwd *p = pwdb_getpwnam(username);
    if (p != NULL) {
        if(p->pw_failed >= MAX_PW_ATTEMPTS) {
            printf("Your account is locked. Contact your systems hacker boi.\n");
            return 1;
        }
        char *password;
        password = getpass("password: ");

        // copies the 2 first elements to salt(as it is the salt).
        char salt[2]; 
        memcpy(salt, p->pw_passwd, 2); 

        char *pwhash;
        //encrypts the plaintext password with the salt.
        pwhash = crypt(password, salt); 

        // Is the stored hash the same as the calculated one?
        if (strcmp(p->pw_passwd, pwhash) == 0) {
            p->pw_failed = 0;
            p->pw_age++;
            /**/
            if(p->pw_age >= MAX_PW_AGE) {
                printf("\nYour password has been used for %d logins...\n", p->pw_age);
                printf("\n...Time to change ( ͡° ͜ʖ ͡°).\n");
            }
            printf("\nDucking success mate\n");
        } else {
            p->pw_failed++;
            printf("\nDucking fail mate %d\n", p->pw_failed);
        }

        /* Absolut inte copy-paste:ad kod*/
        if (pwdb_update_user(p)!=0) {
            printf("pwdb_update_user returned error %s\n",pwdb_err2str(pwdb_errno));
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

