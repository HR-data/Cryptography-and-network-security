#include<stdio.h>
#include <string.h>
#include<stdlib.h>
int Encryption(int* ,int);
int Decryption(int* ,int );
int key =3; // cease chipher

int main()
  {
     int check ;
     printf("Enter 0 for encryption and 1 for decryption\n");
     scanf("%d",&check);
     int *num;
     int n;
     printf("Enter the size of string \n");
     scanf("%d",&n);
     char text[n];
     num = (int *)malloc(n*1);
     printf("Enter the message.\n");
     scanf("%s",text);
     printf("your entered text is : %s\n",text);
     for(int i = 0; i < strlen(text);i++)
       {
          if (text[i] >= 'A' &&text[i] <= 'Z')
             num[i] =text[i] - 'A';
        else if (text[i] >= 'a' &&text[i] <= 'z')
             num[i] =text[i] - 'a'; 
       }
       
       
       if(check==0)
         Encryption(num,n);
       else if (check == 1)
        Decryption(num,n); 



      return 0;
  }
  int Encryption(int* num,int n)
    {  
       printf("The ciphertext is :");
        for(int i = 0 ; i < n; i++)
           {
               num[i] = (num[i] + key)%26;
               
               printf("%c",num[i]+65);
                    
           }
        printf("\n");
        return 0;
    }

  int Decryption(int* num,int n)
    {  
       printf("The plaintext is is :");
       
        for(int i = 0 ; i < n; i++)
           {
               num[i] = (num[i] - key)%26;
               if(num[i]<0)
                 printf("%c",num[i]+26+97);
               else if (num[i<=0])  
                 printf("%c",num[i]+97);
               
               
                    
           }
        printf("\n");
        return 0;
    }  
