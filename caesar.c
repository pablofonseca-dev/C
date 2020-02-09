#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
const string instruction_error = "Usage: ./caesar key\n";

//MY FUNCTIONS
int getKey(int argOne, string argTwo[]);
string getPlainText(void);
bool checkAlpha(string plainText, int index);
bool checkCapitalization(string plainText, int index);
void encrypt(int my_key, string my_text);
int get_alpha_index(int ascii_val, char startChar);
char get_ascii_char(char startChar, int alpha_index);

int main(int argc, string argv[])
{
    //GET KEY
    int key = getKey(argc, argv);
    if (key == -1)
    {
        return 1;
    }
    //GET PLAINTEXT
    string plainText = getPlainText();
    encrypt(key, plainText);
}

//GET KEY FROM COMMAND-LINE ARGUMENTS
int getKey(int argOne, string argTwo[])
{
    //Ensure single command-line argument.
    if (!(argOne == 2))
    {
        printf("%s\n", instruction_error);
        return -1;
    }
    else
    {
        //Make sure argument contains only digit characters.
        bool validation = false;
        for (int i = 0, n = strlen(argTwo[1]); i < n; i++)
        {
            if (isdigit(argTwo[1][i]))
            {
                validation = true;
            }
            else
            {
                validation = false;
                printf("%s\n", instruction_error);
                return -1;
            }
        }
    }
    //Converts the string into an integer
    int key = atoi(argTwo[1]);
    return key;
}

//GET THE PLAINTEXT
string getPlainText(void)
{
    string plainText = get_string("plaintext: ");
    return plainText;
}

void encrypt(int my_key, string my_text)
{
    printf("ciphertext: ");
    int key_len = strlen(my_text);
    //Validate if is each char is Up or Lower
    for (int index = 0; index < key_len; index++)
    {
        if (isalpha(my_text[index]))
        {
            int ascii_val = (int)my_text[index];
            //Find its alpha index, no matter if it is uppercase or lowercase
            int actual_alpha_index;
            if (isupper(my_text[index]))
            {
                actual_alpha_index = get_alpha_index(ascii_val, 'A');
            }
            else
            {
                actual_alpha_index = get_alpha_index(ascii_val, 'a');
            }
            //printf("%i ->", actual_alpha_index);
            int new_alpha_index = (actual_alpha_index + my_key) % 26;
            //printf("%i \n", new_alpha_index);
            //Now let's find the new char with the actual alphabetical index
            char c;
            if (isupper(my_text[index]))
            {
                c = get_ascii_char('A', new_alpha_index);
            }
            else
            {
                c = get_ascii_char('a', new_alpha_index);
            }
            printf("%c", c);
        }
        else
        {
            printf("%c", my_text[index]);
        }
    }
    printf("\n");
}

int get_alpha_index(int ascii_val, char startChar)
{
    int index_counter = 0;
    for (int start = (int)startChar; start < ascii_val; start++)
    {
        //Increment a little counter
        //This counter ends in the last position of the char starting with 0.
        index_counter++;
    }
    return index_counter;
}

char get_ascii_char(char startChar, int alpha_index)
{
    for (int index = 0; index < alpha_index; index++)
    {
        startChar++;
    }
    char finalChar = startChar;
    return finalChar;
}
