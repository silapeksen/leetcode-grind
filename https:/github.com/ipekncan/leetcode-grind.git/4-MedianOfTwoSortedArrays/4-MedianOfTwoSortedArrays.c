// Last updated: 24.06.2026 13:29:09
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int newSize=nums1Size+nums2Size;
    int newArray[newSize];
    
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
    }
}