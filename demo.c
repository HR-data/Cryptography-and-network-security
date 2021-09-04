 #include<stdio.h>
#include<string.h>
int main()
{
 char str[]="meetmeafterthepartyisover";
 int n=strlen(str);
 char str1[n/2+1],str2[n/2+1];
 int j=0,k=0;
 for(int i=0;i<n;i++)
 {
  if(i%2==0)
  {
   str1[j++]=str[i];
  }
  else
  {
   str2[k++]=str[i];
  }
 }
 printf("%s%s",str1,str2);
 return 0;
	
}