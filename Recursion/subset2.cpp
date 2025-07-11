class Solution {
public:
    vector<vector<int>>res;

    void solve(vector<int>&nums,int idx,vector<int>&temp,int n){
            
             res.push_back(temp);

            for(int i=idx;i<n;i++){
                
                if(i>idx && nums[i]==nums[i-1])continue;
                temp.push_back(nums[i]);
                solve(nums,i+1,temp,n);
                temp.pop_back();

            }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<int>temp;
        int n=nums.size();
        solve(nums,0,temp,n);
        return res; 

        
    }
};