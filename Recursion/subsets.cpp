/*.............78.Subsets...............*/

class Solution {
public:

    vector<vector<int>>result;

    void solve(vector<int>&nums,int idx,int n,vector<int>&temp){

            if(idx==n){
                result.push_back(temp);
                return;
            }

            // take 
            temp.push_back(nums[idx]);
            solve(nums,idx+1,n,temp);
            temp.pop_back();
            // not take
            solve(nums,idx+1,n,temp);


    }
    vector<vector<int>> subsets(vector<int>& nums) {

            int n=nums.size();
            vector<int>temp;
            solve(nums,0,n,temp);   
            return result;


    }
};