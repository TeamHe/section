#! /bin/sh

gcc -Tld.lds section.c -o section
arm-linux-gnueabihf-gcc -Tld-arm.lds section.c -o section-arm

gcc -Tld.lds section-stu.c -o section-stu

#gcc -c -o section-stu.o section-stu.c
#objdump -d section-stu.o
