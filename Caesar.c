#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
bool isDigit(string arg)
{
    /*
     * This function for checking if the argv[1] is all made of numbers.
     * accepts string "arg" to check if it is all numbers.
     * returns boolean argument to continue the work flow of the cipher.
     */
    bool isDIGIT = true;
    int length = strlen(arg);
    for (int i = 0; i < length; i++)
    {
        /*
         * Going to iterate for all charecters or "Numbers" in this string
         * to check if it's numbers or not .. if it was not a number the
         * boolean value will change to false .
         */
        if (!(isdigit(arg[i])))
        {
            isDIGIT = false;
        }
    }
    return isDIGIT;
}
//encryption function 
void encipher(string plainText, int key)
{
    /*
     * This function will encipher the given string from the user.
     * Will seprate the alphapatical letters to two sections:
     *     - Capital letters and will be encripted aside.
     *     - Small letters and will be encripted aside.
     * Then all of the letters will be printed to the user side by side.
     * will accept int key for shifting the letters, string plainText which will be encrypted.
     * will not return anything so it is void
     */
    char capital[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char small[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    //Taking the length of the given string to help with the "for" loop.
    int length = strlen(plainText);
    //Making an array of charecters to hold the encrypted charecters.
    char ciphertext[length];
    //a variable to help with finding the right element of the letters' arrays to use it.
    int numnum = 0;
    
    for (int i = 0; i < length; i++)
    {
        if (isupper(plainText[i]))
        {
            int letter = plainText[i] - 'A';
            numnum = (letter + key) % 26;
            ciphertext[i] = capital[numnum];
        }
        else if (islower(plainText[i]))
        {
            int letter = plainText[i] - 'a';
            numnum = (letter + key) % 26;
            ciphertext[i] = small[numnum];
        }
        else
        {
            // This section for the "none-alphapatical charecters" like "," or numbers
            ciphertext[i] = plainText[i];
        }
    }
    //printing the result for the user.
    printf("ciphertext: ");
    for (int i = 0 ; i < length; i++)
    {
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //if the user managed successfuly to put 2 argument vectors then we need to check
        //the "argv[1]" if it was written all by numbers.
        bool isDIGIT = isDigit(argv[1]);
        if (!(isDIGIT))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            //coverting the key from "string" to "int".
            int key = atoi(argv[1]);
            //taking input from the user for the text that they want to encipher
            string plainText = get_string("plaintext:  ");
            //encrypting the text and printing it.
            encipher(plainText, key);
           
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
