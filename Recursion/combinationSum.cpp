/*Combination Sum 39 */

class Solution {
public:
    vector<vector<int>>res;

    void solve(vector<int>& candidates,int i,int sum,int target,vector<int>&temp,int n){
        


        if(sum>target){
            return;
        }
        if(i>=n){
            if(sum==target){
                res.push_back(temp);          
            }
            return ;
        }

        sum+=candidates[i];
        temp.push_back(candidates[i]);
        solve(candidates,i,sum,target,temp,n);

        sum-=candidates[i];
        temp.pop_back();
        solve(candidates,i+1,sum,target,temp,n);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>temp;
        int sum=0;

        solve(candidates,0,sum,target,temp,n);
        return res;


    }
};