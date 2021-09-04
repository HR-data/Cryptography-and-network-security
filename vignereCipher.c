#include<stdio.h>
#include<string.h>
 
void main()
{   int n,m;
    printf("Enter the length of message \n");
    scanf("%d",&n);

    char text[n];
    printf("Enter the message send to bob : \n");
    scanf("%s",text);
    printf("Enter the length of key \n");
    scanf("%d",&m);
    printf("Enter the key .\n");
    char  key[m] ;
    scanf("%s",key);
    int  keylength = strlen(key);
    char newkey[strlen(text)];
    char encrypted[strlen(text)],decrypted[strlen(text)]; 
    int i,j;
    for( i = 0, j = 0; i < strlen(text); i++, ++j)
    {
        if(j == strlen(key))
            j = 0;
 
        newkey[i] = key[j];
    }
 
    newkey[i] = '\0';
 
    //encryption
    for(i = 0; i < strlen(text); ++i)
        encrypted[i] = 65+((text[i] + newkey[i]) % 26) ;
 
    encrypted[i] = '\0';
 
    //decryption
    for(i = 0; i <strlen(text); ++i)
        decrypted[i] = (((encrypted[i] - newkey[i]) + 26) % 26) + 65;
 
    decrypted[i] = '\0';
 
    printf("Plaintext: %s", text);
    printf("Key: %s\n", key);
    printf("The new  key : %s\n", newkey);
    printf("The ciphertext is: %s\n", encrypted);
    printf("The plaintext is: %s\n", decrypted);
 

}