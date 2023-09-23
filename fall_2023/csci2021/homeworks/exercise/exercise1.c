#include <stdio.h>

// void string_copy(char *dst, char *src){
//     int i = 0;
//     while(src[i] != '\0'){
//         dst[i] = src[i];
//         i++;
//     }
//     dst[i] = '\0';
// }

// void string_copy(char *dst, char *src){
//     while(*src != '\0'){
//         *dst = *src;
//         dst++;
//         src++;
//     }
//     *dst = '\0';
// }

// \ 

// command line argument 

/*
• C gives you access to extra arguments typed in when a program is
invoked on the terminal:
CSCI 2021: Fall '23 (Kolb) 17
#include <stdio.h>
int main(int argc, char *argv[]) {
printf("You provided %d command line arguments:\n", argc);
for (int i = 0; i < argc; i++) {
printf("%s\n", argv[i]);
}
return 0;
}
*/

// int main(){
//     // int x = 5;
//     // int *p = &x;
//     // *p = 6;
//     // int **q = &p;
//     // int *** r = &q;
//     // printf("%d\n", *p);
//     // printf("%d\n", **q);
//     // printf("%d\n", ***r);
//     // printf("%p\n", (void *) &p);

//      FILE *fh_output; // file pointer 
//     fh_output = fopen("io.txt", "w"); // opening the file and in writing mode and assining it to the variable fh_output. 
//     // fputs("Hello this Abreham:\n", fh_output); // write a string of characters into the file. 
//     // fputs("I am learning how read and write files in c programing.\n", fh_output); // write a string of characters into the file. 


//     // int data = 38;
//     // fprintf(fh_output, "data: %d\n", data );


//     // for (int i = 0; i < 100; i ++){
//     //     fprintf(fh_output, "%d\n", i);


//     double *num;
//     *num = 123.566;

//     int *pi;
//     *p

//     fprintf(fh_output, "%f\n", &num);
//     // fprintf(fh_output, "%f\n", pi);


//     fclose(fh_output);
    

//     return 0;
// }



void string_copy(char *dst, char *src){
    int i = 0;
    while (src[i] != '\0'){
        dst[i] = src[i];
        i++;
    }
    dst[i] ='\0';
}

void string_copy(char *dst, char *src){
    while(*src != '\0'){
        *dst = *src;
        dst ++;
        src ++; 
    }
    *dst = '\0';
     
}