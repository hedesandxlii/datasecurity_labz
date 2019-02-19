#!/bin/bash
gcc $1 pwdblib.o -lcrypt -o skicka_mig && ./skicka_mig
