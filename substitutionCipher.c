#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int find_index(char key[],char char_to_find){
  for(int i = 0 ; i < 26; i ++)
  {
    if(key[i] == char_to_find){
      return i;
    }
  }
  return -1;
}

char *encrypt(char text[],char key[])
{ 
  char *ciphertext = (char *) malloc(sizeof(char)*strlen(text));

  for(int i = 0; i < strlen(text); i++)
  {
    int index1 = tolower(text[i]) - 'a';
    if(index1 >= 0 && index1 < 26)
    {
      ciphertext[i] = key[index1];
    }
    else
    {
      ciphertext[i] =text[i];
    }
  }
  return ciphertext;
}

char *decrypt(char text[],char key[])
{
  
  char *plaintext = (char *) malloc(sizeof(char)*strlen(text));
  for(int i = 0; i <strlen(text); i++)
  {
    int index2 = tolower(text[i]) - 'a';
    if(index2 >= 0 && index2 < 26)
    {
      int index3 = find_index(key,tolower(text[i]));
      plaintext[i] = 'a' + index3;
    }
    else
    {
      plaintext[i] =text[i];
    }
  }
  return plaintext;
}

int main()
{  int n;
   printf("Enter the length of text \n");
   scanf("%d",&n);
   char text[n];
   printf("Enter the message send to Bob.\n");
   scanf("%s",text);
   printf("Enter the symmetric key or permuation table like a -> d and f -> g then just write dg: \n");
   printf("--------------------------\n");
   char key[26];
   scanf("%s",key);
   char *ciphertext = encrypt(text,key);
   printf("Original Message: %s\nEncrypted Message: %s\n",text,ciphertext);
   char *plaintext= decrypt(ciphertext,key);
   printf("Decrypted Message: %s\n",plaintext);
   printf("--------------\n\n");
   
   return 0;
   
}
