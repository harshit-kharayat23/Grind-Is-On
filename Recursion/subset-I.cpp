class Solution {
  public:
  vector<int>res;
  
  
    void solve(vector<int>&arr,int n,int i,int sum){
            
            if(i>=n){
                res.push_back(sum);
                return ;
            }
            
            solve(arr,n,i+1,sum+arr[i]);
            
            solve(arr,n,i+1,sum);
        
        
        
    }
    
    
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int n=arr.size();
        int sum=0;
        solve(arr,n,0,sum);
        return res;
    }
};