#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *encode(const char *string) {
  char* result = malloc(strlen(string)+1);

    for (size_t i = 0; i < strlen(string); i++)
    {
        if (string[i]=='a')
        {
            result[i]='1';
        }
        else if(string[i]=='e'){
            result[i] = '2';
        }
        else if(string[i]=='i'){
            result[i] = '3';
        }
        else if(string[i]=='o'){
            result[i] = '4';
        }
        else if(string[i]=='u'){
            result[i] = '5';
        }
        else{
            result[i] = string[i];
        }
        
    }
    result[strlen(string)] = '\0';
  return result;
}

char *decode(const char *string) {
  char* result = malloc(strlen(string)+1);

    for (size_t i = 0; i < strlen(string); i++)
    {
        if (string[i]=='1')
        {
            result[i]='a';
        }
        else if(string[i]=='2'){
            result[i] = 'e';
        }
        else if(string[i]=='3'){
            result[i] = 'i';
        }
        else if(string[i]=='4'){
            result[i] = 'o';
        }
        else if(string[i]=='5'){
            result[i] = 'u';
        }
        else{
            result[i] = string[i];
        }
        
    }
    result[strlen(string)] = '\0';
  return result;
}

int main(){
    printf("%s", encode("hello world\n"));
    printf("%s", decode(encode("hello world\n")));
}