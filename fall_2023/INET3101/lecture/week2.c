#include <stdio.h>
int main() {
    printf("Hello world\n");

    char myString[100];
    int i;
    for(i = 0; i < 100; i++){
        myString[i] = "\0";
    }

    myString[0] = 'a';
    myString[1] = 'c';
    myString[2] = 'b';

    for(i = 0; i < 100; i++){
        printf("output is: %s", myString);
    }


}
// there is a realationship between an arry and pointers although 
// pointers:
    // symbolic ways to use the address.
    /*
    value of pointer is a memory address.
    example:
        char aready[100]
        char *bob;

        bob == &aready[0]
            meaning that a pointer just points to the first element of an array 
            & represents "memory address of", and [0] is the first element. 


    dates + 2 is indicating a pointer aritmetic. 

    wen can use the star in two ways. 
        to create a pointer and to derefrence the value. 
        *(date + 2) ==dates[2];
        (*dates) + 2




        Assignment:
            assign an adress to a pointer (ptr = array)
            value finding (dereferencing)
            




    pointer pitfalls 
        int urn[3];
        int *ptr1, *ptr2;

        valid: 
            ptr++ // just an array 
            ptr2 = ptr + 2 initialized pointers
            ptr2 = urn +1
        Invalid:
            urn++
            ptr2 = ptr2 + ptr1; cannot add two pointers 
            ptr2 = urn *ptr1 
    */




   /*
   CHARACTER I/O
   system i/o vs standard i/o
   system i/o:
        Lowest form of I/O in the Linux/UNIX OS
        read/write/open/close/lseek/fcntl/ioctl
        NO BUFFERING
        Uses “file descriptor”
    Standard I/O (#include <stdio.h>)
        BUFFERED (3 types – NONE/LINE/FULLY)
        printf/scanf/gets/puts/getchar/putchar/…….
        Uses a FILE object (structure inclusive of file descriptor)




   */

  int main(){
    char buf[100];
    read(0, &buf, 100);
    buf[strlen(buf) -1] = '\0';
    write(1, &buf);
  }


// lab overview:
    // script the folder and submit 