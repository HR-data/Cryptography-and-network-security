#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,num,key[200];
	char text[200],ciphertext[200];
	printf("Enter the message send to bob : ");
	scanf("%s",text);
	
	printf("Enter the size of the key: ");
	scanf("%d",&num);
	printf("Enter the key with spaces and it should be integer: ");
	for(i=0;i<num;i++)
    {
      scanf("%d",&key[i]);
    }
	  
	
	
	for(int k=0;k<strlen(text);k++)
    {
      i=k%num;
      
      for(j=1;j<=num;j++)
      {
        
      
        if(key[i]==j)
        {
          int pos=(j-1)+(k/num)*num;
          ciphertext[pos]=text[k];	
        break;
        }
        }
    }
    
  printf("----------------------\n");  

	printf("The ciphertext is: ");
	for(i=0;i<strlen(text);i++)
     {
       printf("%c",ciphertext[i]);
     }
	printf("\n");  
  return 0;  
}