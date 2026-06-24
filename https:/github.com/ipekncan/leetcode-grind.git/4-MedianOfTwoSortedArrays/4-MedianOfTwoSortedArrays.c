#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Binary Search
    int* A = nums1;
    int* B = nums2;
    int aSize = nums1Size;
    int bSize = nums2Size;

    // A her zaman küçük dizi olmalı
    if (nums1Size > nums2Size) {
        A = nums2;
        B = nums1;
        aSize = nums2Size;
        bSize = nums1Size;
    }

    int sum_len = aSize + bSize;
    int half = sum_len / 2; 
    
    int left = 0;
    int right = aSize - 1; 

   
    while (1) { 
       
        int i = (left + right) >= 0 ? (left + right) / 2 : ((left + right) / 2) - 1;
        int j = half - i - 2; 
        
        
        double A_left  = (i >= 0) ? A[i] : -2e9;
        double A_right = ((i + 1) < aSize) ? A[i + 1] : 2e9;

        double B_left  = (j >= 0) ? B[j] : -2e9;
        double B_right = ((j + 1) < bSize) ? B[j + 1] : 2e9;

        if (A_left <= B_right && B_left <= A_right) {
            
           
            if (sum_len % 2 != 0) {
                // Sağ tarafın en küçüğü medyandır
                return (A_right < B_right) ? A_right : B_right;
            } 
            
            else {
                double max_left = (A_left > B_left) ? A_left : B_left;
                double min_right = (A_right < B_right) ? A_right : B_right;
                return (max_left + min_right) / 2.0;
            }
        } 
        // A_left çok büyükse sol sınırı daralt
        else if (A_left > B_right) {
            right = i - 1;
        } 
        // B_left çok büyükse sağ sınırı genişlet
        else {
            left = i + 1;
        }
    }
}




    /*int newSize=nums1Size+nums2Size;
    int newArray[newSize];
    //Adding arrays to a new array.
    for(int i=0;i<newSize;i++){
        if(i<nums1Size){newArray[i]=nums1[i];}
        else{newArray[i]=nums2[i - nums1Size];}
    }
    //Sorting numbers.
    for(int i=0;i<newSize;i++){
        for(int j=i+1;j<newSize;j++){
            if(newArray[j]<newArray[i]){
                int temp=newArray[i];
                newArray[i]=newArray[j];
                newArray[j]=temp;
            }
        }
    }

    if(newSize%2!=0){
        int b=newSize/2;
       double median=newArray[b];
       return median;
       }
       
    
    else {
        int b=newSize/2;
        double median=(newArray[b-1]+newArray[b])/2.0;
        return median;
    }*/

    


