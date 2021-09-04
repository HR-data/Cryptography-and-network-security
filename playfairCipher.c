#include<stdio.h>
#include<string.h>
#include<ctype.h>
int func1(int size,int a[]);
int func2(int position,int a[],int size);
main()
{
 int i,j,k,numstr[100],numcipher[100],numkey[100];
 int lenkey,l1,tempkey[100],f=-1;
 int size,cipherkey[5][5],lennumstr,r1,r2,c1,c2;
 char str[100],key[100];
 printf("Enter a string\n");
 gets(str);
 //converting entered string to Capital letters
 for(i=0,j=0;i<strlen(str);i++)
 {
  if(str[i]!=' ')
  {
   str[j]=toupper(str[i]);   
   j++;
  }
 }
 str[j]='\0';
 printf("Entered the message send to bob is %s\n",str);
 //Storing string in terms of ascii and to restore spaces I used -20
 size=strlen(str);
 for(i=0;i<size;i++)
 {
  if(str[i]!=' ')
  numstr[i]=str[i]-'A';
 }
 lennumstr=i;
 //Key processing
 printf("Enter the key ,Non repeated elements only\n");
 gets(key);
 //converting entered key to Capital letters
 for(i=0,j=0;i<strlen(key);i++)
 {
  if(key[i]!=' ')
  {
   key[j]=toupper(key[i]);   
   j++;
  }
 }
 key[j]='\0';
 printf("%s\n",key);
 //Storing key in terms of ascii
 k=0;
 for(i=0;i<strlen(key)+26;i++)
 {
  if(i<strlen(key))
  {
   if(key[i]=='J')
   {
    f=8;
    printf("%d",f);
   }
       numkey[i]=key[i]-'A';   
  }
  else
  {
    if(k!=9 && k!=f)//Considering I=J and taking I in place of J except when J is there in key ignoring I
    {
            numkey[i]=k; 
      }
      k++;
  }
 }
 l1=i;
 lenkey=func1(l1,numkey);
 printf("Master key change in key matrix \n");
 for(i=0;i<lenkey;i++)
 {
     printf("%c",numkey[i]+'A');  
 }
 printf("\n");
 //Arranging the key in 5x5 grid
 k=0;
 for(i=0;i<5;i++)
 {
  for(j=0;j<5;j++)
  {
   cipherkey[i][j]=numkey[k];   
   k++;
  }
 }
 printf("The key matix is :\n");
 for(i=0;i<5;i++)
 {
  for(j=0;j<5;j++)
  {
   printf("%c ",cipherkey[i][j]+'A');
  }
  printf("\n");
 }   
   //Message Processing 
   for(i=0;i<lennumstr;i+=2)
   {
      if(numstr[i]==numstr[i+1])
      {
       func2(i+1,numstr,lennumstr);
       lennumstr++;
      }
   }
   if(lennumstr%2!=0)
   {
    func2(lennumstr,numstr,lennumstr);
    lennumstr++;
   }
   printf("The plaintext is\n");
   for(i=0;i<lennumstr;i++)
   {
    printf("%c",numstr[i]+'A');
   }
   for(k=0;k<lennumstr;k+=2)
   {
    for(i=0;i<5;i++)
    {
     for(j=0;j<5;j++)
     {
      if(numstr[k]==cipherkey[i][j])
      {
         r1=i;
         c1=j;       
      }
      if(numstr[k+1]==cipherkey[i][j])
      {
         r2=i;
         c2=j;       
      }     
     }
    }
    //Only change between Ecryption to decryption is changing + to -
    //If negative add 5 to that r or cumn
    if(r1==r2)
    {
     c1=(c1-1)%5;
     c2=(c2-1)%5;
     if(c1<0)
     {
      c1=5+c1;
     }
     if(c2<0)
     {
      c2=5+c2;
     }
     numcipher[k]=cipherkey[r1][c1];
     numcipher[k+1]=cipherkey[r2][c2];
    }
    if(c1==c2)
    {
     r1=(r1-1)%5;
     r2=(r2-1)%5;
      if(r1<0)
     {
      r1=5+r1;
     }
     if(r2<0)
     {
      r2=5+r2;
     }
     numcipher[k]=cipherkey[r1][c1];
     numcipher[k+1]=cipherkey[r2][c2];
    }
    if(r1!=r2&&c1!=c2)
    {
     numcipher[k]=cipherkey[r1][c2];
     numcipher[k+1]=cipherkey[r2][c1];
    }
   } 
   printf("\nThe Cipher Text is\n");
   for(i=0;i<lennumstr;i++)
   {
    if((numcipher[i]+'A')!='X')
      printf("%c",numcipher[i]+65); 
   }
   printf("\n"); 
}
int func1(int size,int a[])
{
 int i,j,k;
 for(i=0;i<size;i++)
  {
 for(j=i+1;j<size;)
 {
    if(a[i]==a[j])
    {    
     for(k=j;k<size;k++)
     {
      a[k]=a[k+1];
     }
         size--;
        }
    else
    {
      j++;
     } 
 }
 }
return(size);
}
int func2(int position,int a[],int size)
{
       int i,insitem=23,temp[size+1];
    for(i=0;i<=size;i++)
        {
        if(i<position)
        {
            temp[i]=a[i];
        }
        if(i>position)
        {
         temp[i]=a[i-1];    
        }
        if(i==position)
        {
            temp[i]=insitem;
        }
        }       
        for(i=0;i<=size;i++)
        {
         a[i]=temp[i];
        }
}