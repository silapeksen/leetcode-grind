// Last updated: 27.06.2026 16:24:19
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int expand_around(char* s, int left,int right, int len){
   while(left >= 0 && right < len && s[left] == s[right]){
        left--;
        right++;

    }
    int palindrom_length=right-left-1;
    return palindrom_length;
}

char* longestPalindrome(char* s) {
    int len=strlen(s);
    if(len<1)return("");

    int start_point=0;
    int max_len=0;
    

    for(int i=0;i<len;i++){
        int len1=expand_around(s,i,i,len);
        int len2=expand_around(s,i,i+1,len);

        int current_max=0;
        if(len1>len2){
            current_max=len1;
        }
        else{
            current_max=len2;
        }
        if(current_max > max_len){
        max_len = current_max;
        start_point = i - (current_max - 1) / 2;
        }

        

    }

    char * result=(char*)malloc((max_len+1)*sizeof(char));

    strncpy(result,s+start_point,max_len);

    result[max_len]='\0';

    return result;   
}