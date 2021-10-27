class Solution {
public:
    void swap(vector<int>& arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int ptr = -1, itr = 0, ptr2= n - 1;
   
   while(itr <= ptr2){
       
       if(arr[itr] == 0){
           swap(arr, ++ptr, itr);
           itr++;
       }
       else if(arr[itr] == 2){
           swap(arr, itr, ptr2--);
       }
       else{
           itr++;
       }
   }
    }
};
