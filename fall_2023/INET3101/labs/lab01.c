#include <stdio.h>
#include <string.h>

// functions
void addNumbers();
void multiplyNumbers();
void reverseString();
void compareWords();

int main(int argc, char *argv[]) {
    int debugMode = 0;

    // Check if a command line argument was provided.
    if (argc > 1) {
        if (strcmp(argv[1], "debug") == 0) {
            debugMode = 1;
        } else if (strcmp(argv[1], "no-debug") != 0) {
            // Print usage statement if the argument is invalid.
            printf("Error: Usage: %s [debug | no-debug]\n", argv[0]);
            return 1;
        }
    }

    int option;

    while(1){
        // The main menu options 
        printf("Menu:\n");
        printf("1) Add 2 integers\n");
        printf("2) Multiply 2 floating-point numbers\n");
        printf("3) Reverse a string\n");
        printf("4) Compare two words\n");
        printf("5) Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            // calling the addNumbers() method. 
            addNumbers();
            break;
        case 2:
            // calling the multiplyNumbers() method.
            multiplyNumbers();
            break;
        case 3:
            // calling the reverseString() method.
            reverseString();
            break;
        case 4:
            // clalling the compareWords() method. 
            compareWords();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid input\n");
        }
    }
    return 0;
}

void addNumbers(){
    // implimenting the addNumbers method.
    int number1, number2;
    printf("Enter two numbers: ");
    scanf("%d %d", &number1, &number2);
    int sum = number1 + number2;
    printf("Sum: %d\n", sum);
}

void multiplyNumbers(){
    // implimenting the multiplyNumbers method
    float number1, number2;
    printf("Enter two floating-point numbers: ");
    scanf("%f %f", &number1, &number2);
    float product = number1 * number2;
    printf("Product: %.2f\n", product);
}

void reverseString(){
    // implimenting the reverseString method
    char str[50];
    printf("Enter a string: ");
    scanf("%s", str);
    int length = strlen(str);
    printf("Reversed string: ");
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void compareWords(){
    // implimenting the comparewords method
    char word1[100], word2[100];
    printf("Enter two words: ");
    scanf("%s %s", word1, word2);
    if (strcmp(word1, word2) == 0) {
        printf("Words are the same.\n");
    } else {
        printf("Words are different.\n");
    }
}
 