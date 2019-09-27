#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string p, c = "";
    if (argc == 2 && atoi(argv[1]) > 0)// check the arguments
    {
        int key = atoi(argv[1]);// use key
        p = get_string("plaintext:  ");// get the plaintext
        printf("ciphertext: ");
        for (int i = 0; i < strlen(p); i++)
        {
            if (p[i] >= 'a' && p[i] <= 'z') //check lowercase
            {
                printf("%c", (((p[i] - 'a') + key) % 26) + 'a');
            }
            else if (p[i] >= 'A' && p[i] <= 'Z')//check uppercase
            {
                printf("%c", (((p[i] - 'A') + key) % 26) + 'A');
            }
            else 
            {
                printf("%c", p[i]); //otherways
            }
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");//when the argc has not key
        return 1;
    }
    
}
