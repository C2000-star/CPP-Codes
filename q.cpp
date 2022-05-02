

arr


merge(arr, start, m , end){
    i = start;
    j = m+1;
    temp[end-start+1];
    k = 0;
    while(i <= m && j <= end){
        if(arr[i] < arr[j]){
            temp[k] = arr[i]
            i++
            k++
        }
        else{
            temp[k] = arr[j]
            j++
            k++
        }
    }
    
    while(i <= m){
        temp[k] = arr[i]
        k++;
        i++
    }
    while (j <= end)
    {
        temp[k] = arr[j] 
        k++;
        j++
    }

    for(int i = start; i <= end; i++){
        arr[i] = temp[start-i]
    }

}
mergeSort(arr, start, end){
    while(start<end){
        int m = start + (end-start)/2;
        mergeSort(arr, start, m);
        mergeSort(arr, m+1, end);
        merge(arr, start, m, end);
    }
}


minVal

for(i to n){
    
}