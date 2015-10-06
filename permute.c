#include <stdio.h>
void swap(char *a,char *b){
	char temp = *a;
	*a = *b;
    *b = temp;

}
void permute( char *str,int s,int e){
	int i;
     if(s == e){
     	 printf("%s\n",str);
     	 return;
 	  }
 	  for(i = s;i <= e;i++){
 	  	swap(str+s,str+i);
 	  	permute(str,s+1,e);
 	  	swap(str+s,str+i);
 	  }
}
int main(){
	char str[7];
	int i=0;
	printf("\nEnter the string\n");
	scanf("%s",str);
	while(str[i] != '\0')
		i++;
    permute(str,0,i-1);
    return 0;
}