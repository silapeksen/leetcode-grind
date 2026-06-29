// Last updated: 29.06.2026 16:05:37
1#include<stdio.h>
2#include <limits.h>
3int reverse(int x){
4    int digit;
5    int reversed_num=0;
6if(x>0){
7    while(x>0){
8    digit=x%10;
9    if (reversed_num > INT_MAX / 10 || reversed_num < INT_MIN / 10) {return 0;}
10    reversed_num=(reversed_num * 10)+ digit;
11    x=x/10;
12    
13    }
14    return reversed_num;
15}
16else{
17    
18    while(x<0){
19    digit=x%-10;
20    if (reversed_num > INT_MAX / 10 || reversed_num < INT_MIN / 10) {return 0;}
21    reversed_num=(reversed_num * 10)+ digit;
22     x=x/10;
23    
24    }
25    return reversed_num;
26}
27}