// Last updated: 27.06.2026 16:23:37
1#include <stdio.h>
2#include <string.h>
3#include <stdlib.h>
4
5int expand_around(char* s, int left,int right, int len){
6   while(left >= 0 && right < len && s[left] == s[right]){
7        left--;
8        right++;
9
10    }
11    int palindrom_length=right-left-1;
12    return palindrom_length;
13}
14
15char* longestPalindrome(char* s) {
16    int len=strlen(s);
17    if(len<1)return("");
18
19    int start_point=0;
20    int max_len=0;
21    
22
23    for(int i=0;i<len;i++){
24        int len1=expand_around(s,i,i,len);
25        int len2=expand_around(s,i,i+1,len);
26
27        int current_max=0;
28        if(len1>len2){
29            current_max=len1;
30        }
31        else{
32            current_max=len2;
33        }
34        if(current_max > max_len){
35        max_len = current_max;
36        start_point = i - (current_max - 1) / 2;
37        }
38
39        
40
41    }
42
43    char * result=(char*)malloc((max_len+1)*sizeof(char));
44
45    strncpy(result,s+start_point,max_len);
46
47    result[max_len]='\0';
48
49    return result;   
50}