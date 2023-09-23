Abreham Getachew - getac021

Program Description;
          
This command line application provides a user menu driven interface that allows you to perform operations. 
These operations include adding two numbers multiplying two numbers reversing a string and comparing two words. 
By selecting an option, from the menu you will receive the results. Additionally the program offers a debug mode for information.

Menu. Usage;
             
The program presents you with a menu that includes the following choices;
1) Add two numbers ( numbers)
2) Multiply two numbers ( numbers)
3) Enter a string and reverse it
4) Provide two words, for comparison
5) Exit

To perform your desired operation simply enter the respective number from the menu.
 In case you mistakenly enter an option don't worry! The program will kindly prompt you to try agian. 

Each Function Defined;
            
1) addNumbers()
Input Type(s); Two whole numbers
Output Type; number (the sum of the two input values)
Algorithm Description; This function takes in two numbers as input calculates their sum using a specific algorithm and then displays the result on screen.
2) multiplyNumbers()
Input Type(s); Two numbers
Output Type; number (Product of the multiplication)
Algorithm Description; This function receives two decimal numbers as input calculates their product and displays the result rounded to three decimal places.

3) reverseString()
Input Type(s); A string (, without any spaces)
Output Type; String (The reversed version of the input string)
Algorithm Description; This function accepts a string as input reverses it character, by character and outputs the reversed string.

4) Function compareWords()
Input Type(s); Two words (strings separated by a space)
Output Type; Text (Result of comparison)
Algorithm Description; This function takes two words as input compares them using the strcmp() function and displays whether they are the same or different.

List of Required Files;
             
 lab01.c    ; program file that contains the menu and program logic.
 README.txt   ; This document explains the program.
 

Usage;
   
1. Compile the program using a C compiler, like gcc.
2. Run the compiled executable.
3. Follow the on screen menu to select an operation.
4. Enter values as prompted.
5. View the results. Continue using the menu until you choose to exit.

Optional Debug Mode;
           
You can enable mode by running the program with the "command line argument;
Example;./lab01.c debug
Debug mode provides information, for debugging purposes.
