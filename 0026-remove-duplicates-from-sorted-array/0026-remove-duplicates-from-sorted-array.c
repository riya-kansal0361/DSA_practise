int removeDuplicates(int* arr, int numsSize){
    int i=0;
    for(int j=1;j<numsSize;j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}