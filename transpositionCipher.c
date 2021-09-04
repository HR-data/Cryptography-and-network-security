#include <stdio.h>
#include <ctype.h> // tolower
#include <stdlib.h> // for malloc
#include <string.h> // for strlen


void encryption(char *key, char *words, char *cipher)
{
    
    int  pos;

    for (int i = 0; i < strlen(words); i += strlen(key))
    {
        for (int j = 0; j < strlen(key); ++j)
        {
            pos = key[j] - '0' - 1 + i;

            if (pos < strlen(words))
            {
                sprintf(cipher, "%s%c", cipher, tolower(words[pos]));
            }
            else
            {
                sprintf(cipher, "%s ", cipher);
            }
        }
    }
}


void decryption(char *key, char *cipher, char *plaintext)
{
    
    char *arr = (char*)malloc(sizeof(char) * strlen(key));

    for (int i = 0; i < strlen(key); ++i)
        arr[(key[i] - '0') - 1] = '0' + i + 1;

    encryption(arr, cipher, plaintext);
    free(arr);
}

int main(int argc, char const *argv[])
{
  
    int n,m;
    printf("Enter the length of message \n");
    scanf("%d",&n);

    char text[n];
    printf("Enter the message send to bob : \n");
    scanf("%s",text);
    printf("Enter the length of key \n");
    scanf("%d",&m);
    printf("Enter the key in number like if key is ABC then enter 012 .\n");
    char  key[m] ;
    scanf("%s",key);

  
    char ciphertext[1024], plaintext[1024];

    encryption(key, text, ciphertext);
    printf("Encrpyted message is: %s \n", ciphertext);

    decryption(key, ciphertext, plaintext);
    printf("Decyprted message is: %s \n", plaintext);

    return 0;
}
