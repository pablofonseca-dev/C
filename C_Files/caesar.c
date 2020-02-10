#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//Global constants
const string instructionError = "Usage: ./caesar key\n";

//Functions
int getKey(int argOne, string argTwo[]);
string getPlainText(void);
void encrypt(int my_key, string my_text);
int getAlphaIndex(int ascii_val, char startChar);
char getAsciiChar(char startChar, int alpha_index);

int main(int argc, string argv[])
{
    //Get the key
    int key = getKey(argc, argv);

    //Valid if the key entered is less than 0.
    if (key < 0)
    {
        return 1;
    }
    //Get the plain text.
    string plainText = getPlainText();
    encrypt(key, plainText);
}

//Returns a numeric key sent from the command line.
int getKey(int argOne, string argTwo[])
{
    //Ensure single command-line argument.
    if (!(argOne == 2))
    {
        printf("%s\n", instructionError);
        return -1;
    }
    else
    {
        //Make sure argument contains only digit characters.
        for (int i = 0, n = strlen(argTwo[1]); i < n; i++)
        {
            if (!isdigit(argTwo[1][i]))
            {
                printf("%s\n", instructionError);
                return -1;
            }
        }
    }
    //Converts the string into an integer.
    int key = atoi(argTwo[1]);
    return key;
}

//Returns the plaintext.
string getPlainText(void)
{
    string plainText = get_string("plaintext: ");
    return plainText;
}

//Does the encryption.
void encrypt(int customKey, string cipherText)
{
    printf("ciphertext: ");
    int textLength = strlen(cipherText);
    for (int index = 0; index < textLength; index++)
    {
        //Is responsible for validating if the character is a letter of the alphabet.
        if (isalpha(cipherText[index]))
        {
            //The character is a letter of the alphabet.
            //Stores the numerical value of the ascii table character.
            int asciiValue = (int)cipherText[index];
            //Find its alpha index.
            int inputCharAlphaIndex;
            bool isUpper = false;
            //If the character is an uppercase letter.
            if (isupper(cipherText[index]))
            {
                //Starts the count in A -> position 65.
                inputCharAlphaIndex = getAlphaIndex(asciiValue, 'A');
                isUpper = true;
            }
            else
            {
                //The character is a lowercase letter.
                //Starts the count in a -> position 97.
                inputCharAlphaIndex = getAlphaIndex(asciiValue, 'a');
            }
            //Stores the new letter originated with the calculation
            //of the position of the previous letter between 0 and 25
            //and the Caesar formula.
            //Module 26 is useful because thanks to it you can never
            //overflow to a value different than a letter in the ASCII table.
            int outputCharAlphaIndex = (inputCharAlphaIndex + customKey) % 26;
            char generatedChar;
            if (isUpper)
            {
                generatedChar = getAsciiChar('A', outputCharAlphaIndex);
            }
            else
            {
                generatedChar = getAsciiChar('a', outputCharAlphaIndex);
            }
            printf("%c", generatedChar);
        }
        else
        {
            printf("%c", cipherText[index]);
        }
    }
    printf("\n");
}

int getAlphaIndex(int asciiValue, char startInChar)
{
    int indexCounter = 0;
    for (int start = (int)startInChar; start < asciiValue; start++)
    {
        indexCounter++;
    }
    return indexCounter;
}

char getAsciiChar(char operableChar, int alphaIndex)
{
    for (int index = 0; index < alphaIndex; index++)
    {
        operableChar++;
    }
    return operableChar;
}
