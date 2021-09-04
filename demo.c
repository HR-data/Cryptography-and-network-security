#include<stdio.h>
int main()
    {
      int num[]={1,2,3};
      int l = sizeof(num)/sizeof(int);
      for(int i = 0;i <l ; i++)
       {
           printf("%d \n",num[i]);
           if (num[i] >= 65 &&num[i] <= 90)
                 {
                   printf("%c",num[i]+65);    
                 }
               else if (num[i] >= 97 && num[i] <= 122)
                  {
                      printf("%c",num[i]+97); 
                  }
       }

    }