/*    53. Maximum Subarray.   */

/*
Brute Force
TC:O(n^2)
*/
#include<iostream>
#include<vector>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxSum=INT_MIN;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                maxSum=max(maxSum,sum);
            }
        }
        return maxSum;
    }
};

// Kadane's Algorithm 
// TC:O(n)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxSum=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxSum=max(maxSum,sum);
            if(sum<0){
                sum=0;
            }
            

        }
        return maxSum;
       
    }
};