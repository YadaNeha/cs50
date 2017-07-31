#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
int main(int argc, char *argv[])
{
int key = 0;
if(argc == 2){
    key = atoi(argv[1]);
}else{
    printf("Enter valid Input");
    return 1;
}
   string str = "";
   int  pos = 0;
   const char * alphabet = "abcdefghijklmnopqrstuvwxyz";
   printf("plaintext: ");
   str = get_string();
   printf("ciphertext: ");
   for(int i = 0,len = strlen(str); i < len ; i++){
       if(isalpha(str[i])){
           if(isupper(str[i])){
               if(str[i] >= 'A' && str[i] <= 'Z'){
                   pos = str[i] - 'A';
                   printf("%c",toupper(alphabet[(pos+key)%26]));
               }
           }else{
               if(str[i] >= 'a' && str[i] <= 'z'){
                   pos = str[i] - 'a';
                   printf("%c",tolower(alphabet[(pos+key)%26]));
               }
           }
       }else{
            printf("%c",str[i]);
       }
   }
   printf("\n");
}