#include<stdio.h>
#include<string.h>
int main()
{
   
    char text[]="meetmeafterthepartyisover";
    char text1[strlen(text)/2+1],text2[strlen(text)/2+1];
    int j=0,k=0;
    for(int i=0; i < strlen(text); i++)
        {
           if(i%2==0)
           {
             text1[j++]=text[i];
           }
        else
          {
            text2[k++]=text[i];
          }
       }
    printf("------------------\n") ;  
    printf("The ciphertext is %s%s\n",text1,text2);
    return 0;
	
}