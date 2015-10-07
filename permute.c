#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **permutes;
int indexi = 0;
void swap(char *a,char *b){
	char temp = *a;
	*a = *b;
    *b = temp;

}
void permute( char *str,int s,int e){
	int i;
     if(s == e){
     	
          permutes[indexi] = (char*)malloc(e+1);
          strcpy(permutes[indexi],str);
          

          indexi++;
     	 return;
 	  }
 	  for(i = s;i <= e;i++){
 	  	swap(str+s,str+i);
 	  	permute(str,s+1,e);
 	  	swap(str+s,str+i);
 	  }
}
void sort(int n){
	int i,j;
	char temp[7];
	for(i = 0;i < n-1;i++){
		for(j = 0;j < n -1;j++){
			if(strcmp(permutes[j],permutes[j+1]) > 0){
				strcpy(temp,permutes[j]);
				strcpy(permutes[j],permutes[j+1]);
				strcpy(permutes[j+1],temp);
			}
		}
	}
}
int main(){
	char str[7];
	int i=0,n,prod = 1,flag = 0;
	printf("\nEnter the string\n");
	scanf("%s",str);
	
	while(str[i] != '\0'){
		    if(str[i] < 'A' || ((str[i] >'Z') && (str[i] < 'a')) || str[i] > 'z'){
                flag = 1;
                break;
             }
             
              i++;

    }
    if(flag || i <= 2 || i > 6){
    	printf("Invalid Input\n");
    	exit(0);
    }
	n = i;
    for(;i > 0;i--){
    	prod *= i; 
    } 
	
	printf("%d",prod);
	permutes = (char**)malloc(prod*sizeof(char*));
    permute(str,0,n-1);
    sort(prod);
    for(i = 0;i < prod;i++)
    	 printf("%s\n",permutes[i]);
    return 0;
}