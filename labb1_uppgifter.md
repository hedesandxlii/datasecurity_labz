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
