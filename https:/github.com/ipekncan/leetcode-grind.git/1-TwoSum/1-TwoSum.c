// Last updated: 24.06.2026 13:29:06
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize=2;
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
           if(nums[i]+nums[j]==target){
            result[0]=i;
            result[1]=j;
            return result;
           }
        }
    }
   *returnSize = 0;
    return NULL;
}
