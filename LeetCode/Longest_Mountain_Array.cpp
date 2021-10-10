class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i = 0 ; i < arr.size() ;)
        {
            int st = i;
            while(i < n-1 && arr[i] < arr[i+1]) i++;
            int j = i;
            while(j != st && i < n-1 && arr[i] > arr[i+1]) i++;
            if(st != 0 && i != j)
            {
                ans = max(ans , i-st+1);
            }
            else if(st == 0 && i != j)
            {
                ans = max(ans , i-st+1);
            }
            if(i == n-1) break;
            if(st == i) i++;
        }
        return ans;
    }
};
