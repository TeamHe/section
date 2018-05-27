#! /bin/sh

gcc -Tld.lds section.c -o section
arm-linux-gnueabihf-gcc -Tld-arm.lds section.c -o section-arm
