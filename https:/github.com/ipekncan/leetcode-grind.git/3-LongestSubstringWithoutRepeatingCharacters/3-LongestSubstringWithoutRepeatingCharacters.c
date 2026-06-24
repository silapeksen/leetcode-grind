// Last updated: 24.06.2026 13:29:10
#include <string.h>
#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
 int n=strlen(s);
 int right=0;
 int left=0;
 int max_len=0;
 int last_seen[128];

 for(int i=0;i<128;i++){
    last_seen[i]=-1;
 }
 for(int right=0;right<n;right++){
    char current_letter=s[right];
    //did we see this letter before?
    if(last_seen[current_letter]>=left){
    left=last_seen[current_letter]+1;

    }
    last_seen[current_letter]=right;

    int current_len=right-left+1;
    if(current_len>max_len){
        max_len=current_len;
    }
 }
return max_len;
 


}
