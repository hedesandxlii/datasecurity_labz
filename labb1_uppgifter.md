# Labb 1 Uppgifter
## Prep assignment 1
### *What is a brute force attack?*
A bruteforce attack is is an attack where you try every combination possible.

### *What is a dictionary attack?*
A dictionary attack is an attack where you have a database of common passwords and try those. Often a dictionary attack will try alterations of a simple password, e.g. `password` -> `P@s$w0rD`.

### *What is a time-memory tradeoff attack?*
An attack that computes a big hashtable occupying a lot of space but that is instant to lookup things in.

### *What is the difference between a rainbow table and an ordinary time-memory tradeoff table?*
A rainbow table uses a different *reduction function* for every step in the chain. The result of
this is that 2 chains can only collide on the same step in the chain, resulting in a lower
probability of collision.



## Prep assignment 2
### *How is the LAN Manager (LM) hash produced, how is this hash used to authenticate a user, and what is the efffective security of LM?*
Translates to uppercase and adds padding to 14 bytes.
Splits into 2 keys and encrypts `KGS!@#$%` with the 2 keys. This yields a 2
8-byte ciphertexts which are concatenated and returned as a response.

Because the password is uppercased, we get a *"smaller effective character set"*. Because we encrypt the same string, namely `KGS!@#$%`, with 2 different keys, the security is further decreased.

### *How is the NT LAN Manager version 1 (NTLM) hash produced, how is this hash used to authenticate a user, and what is the efffective security of NTLM?*
#### How is the hash poduced/How does it authenticate the user?
First, the server sends a 8 byte, random *challenge*, then the password is hased witn *MD4*, which
yields a hash of 16 bytes. This hash is then padded with 5 bytes to create a string of 21 bytes.
This hash is divided into 3 7-byte DES-keys which encrypts the same challenge (3 times). The 3-fold
encrypted challenge is then concatinated and sent back as a response to the server. If the response
is correct, the user is authenticated.

#### What is the effective security of NTLM?
The algorithm is based on `MD4` and `DES`, but since the same *plaintext* (in
this case, the challenge) is used with different keys, the response is more
vurnable than if the challenge would be **hashed once** (with some other
encryption algorithm then).



## Prep assignment 3
### Ensure that you understand what a salt is, and why it is used.
Adds a static string to the password before the hash is calculated. This is
done the render time-memory attacks useless.

### Find information and read about *PBKDF2*. Roughly compare the time required to calculate a hash with *PBKDF2* with the time required for a single round of *SHA-1*. You do not have to understand the algorithm in detail.
Since `SHA-1` can be used in `PBKDF2`, we will use that example. The number of
times `PBKDF2` uses `SHA-1` depends on the ratio between the *input length* and
the *derived key length*. 

If we want `PBKDF2` to produce a *derived key* that is dubble the length of the *input*, `SHA-1`
will run twice inside `PBKDF2`, 3rd the lenght -> it will run thrice, etc.



## Prep assignment 4
### Read about hashcat such that you have a rough idea of ithe features.


### Assume a password is 7 characters long, each character being in the range `[a-zA-Z0-9]`, i.e. both small and large letters, and numbers. How many such passwords exists?
In `[a-zA-Z0-9]` there is `26 * 2 + 10 = 62` characters. 62 possibilities on 7
positions `=> 62^7 = `**`3.52 * 10^12`** different passwords.



## Prep assignnment 5
### Look up the meaning of the term *Penetration testing* if it is unfamiliar to you.

### Read this short security bulletin about one of the exploits we will use during the attack:
https://helpx.adobe.com/security/products/flash-player/apsa15-03.html
