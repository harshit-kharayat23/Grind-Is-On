/*Permutations using  set */

// time complexity here is O(n*n!)
class Solution {
public:
vector<vector<int>>result;
set<int>st;

    void solve(vector<int>&nums,vector<int>&temp){
            if(temp.size()==nums.size()){
                result.push_back(temp);
                return ;
            }

            for(int i=0;i<nums.size();i++){
                
                if(st.find(nums[i])!=st.end())continue;
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(nums,temp);

                temp.pop_back();
                st.erase(nums[i]);

            }



    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        solve(nums,temp);
        return result;

    }
};

// now using the seap login here 
class Solution {
public:
    vector<vector<int>>result;

    void solve(int idx,vector<int>&nums){

            if(idx==nums.size()){
                result.push_back(nums);
                return;
            }        

            for(int i=idx;i<nums.size();i++){

                    swap(nums[i],nums[idx]);
                    solve(idx+1,nums);
                    swap(nums[i],nums[idx]);


            }





    }
    vector<vector<int>> permute(vector<int>& nums) {

        solve(0,nums);


        return result;
    }
};