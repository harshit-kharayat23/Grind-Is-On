//1. search insert position 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

         int n=nums.size();
         int ans=n;
         int l=0;
         int r=n-1;
         while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }


         }   
        return ans;

    }
};

//2. Ceil and  FLoor

int findCeil(vector<int>&nums,int n,int target){

	int l=0;
	int r=n-1;
	int ans=-1;
	while(l<=r){

		int mid=l+(r-l)/2;
		if(nums[mid]>=target){
			
			ans=nums[mid];
			r=mid-1;
		}
		else{
			l=mid+1;
			
		}




	}
	return ans;



}

int findFloor(vector<int>&nums,int n,int target){

	int l=0;
	int r=n-1;
	int ans=-1;
	while(l<=r){

		int mid=l+(r-l)/2;
		if(nums[mid]<=target){
			ans=nums[mid];
			l=mid+1;
		}
		else{
			r=mid-1;
		}




	}
	return ans;



}



pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {

	int ceil=findCeil(a,n,x);
	int floor=findFloor(a,n,x);

	return {floor,ceil};



}

//3 :34. Find First and Last Position of Element in Sorted Array

class Solution {
public:


    int lowerBound(vector<int>&nums,int target){

        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans=n;

        while(l<=r){
            int mid=(l+r)/2;

            if(nums[mid]>=target){
                ans=mid;
                r=mid-1;

            }
            else{
                l=mid+1;
            }


        }
        return ans;





    }

    int upperBound(vector<int>&nums,int target){
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans=n;

        while(l<=r){
            int mid=(l+r)/2;

            if(nums[mid]>target){
                ans=mid;
                r=mid-1;

            }
            else{
                l=mid+1;
            }


        }
        return ans;








    }
    vector<int> searchRange(vector<int>& nums, int target) {

            int lb=lowerBound(nums,target);
            int ub=upperBound(nums,target);

            if(lb==nums.size() || nums[lb]!=target)return {-1,-1};

            return {lb,ub-1};


    }
};


//33. Search in Rotated Sorted Array
class Solution {
public:
    int search(vector<int>& nums, int target) {

            int l=0;
            int n=nums.size();
            int r=n-1;

            while(l<=r){

                int mid=l+(r-l)/2;
                if(nums[mid]==target)
                return mid;

                if(nums[l]<=nums [mid]){
                        if(nums[l]<=target && target<=nums[mid]){
                            r=mid-1;
                        }
                        else
                            l=mid+1;
                }
                else{
                    if(nums[mid]<=target && target<=nums[r]){
                        l=mid+1;
                    }
                    else{
                        r=mid-1;
                    }
                }
            }
            return -1;
// 81. Search in Rotated Sorted Array II
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<=r){

            int mid=l+(r-l)/2;

            if(nums[mid]==target)return true;
            if(nums[l]==nums[mid] && nums[mid] ==nums[r]){
                l++;
                r--;
                continue;
            }
            // finding the sorted half
            if(nums[l] <=nums[mid]){
                if(nums[l]<=target && nums[mid]>=target){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }


            }

            else{
                if(nums[mid]<=target && target<=nums[r]){

                    l=mid+1;
                }
                else{
                    r=mid-1;
                }


            }





        }
        return false;




    }
};


    }
};

// 153. Find Minimum in Rotated Sorted Array
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans=INT_MAX;

        while(l<=r){
            int mid=l+(r-l)/2;

        //sorted half

        if(nums[l]<=nums[mid]){
            ans=min(nums[l],ans);
            l=mid+1;
        }

        else{
            ans=min(ans,nums[mid]);
            r=mid-1;
        }

        }
        return ans;



    }
};


// Rotation

#include<bits/stdc++.h>
int findKRotation(vector<int> &arr){
    
    int n=arr.size();
    int l=0;
    int r=n-1;
    int ans=INT_MAX;
    int index=-1;
    while(l<=r){

        int mid=l+(r-l)/2;

        // find the sorted half
        if(arr[l]<=arr[mid]){
            if(arr[l]<ans){
                index=l;
                ans=arr[l];
                
            }
            l=mid+1;
           
         
        }
        else{
            if(arr[mid]<ans){
                ans=arr[mid];
                index=mid;
            }
            r=mid-1;

        }


    }
    return index;


    
}

// Brute Force Approach for 540. Single Element in a Sorted Array
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];

        for(int i=0;i<n;i++){
            if(i==0){
                if(nums[i]!=nums[i+1])return nums[i];
            }
            else if(i==n-1){
                if(nums[i]!=nums[i-1])return nums[i];
            }
            else{
                if(nums[i]!=nums[i+1] && nums[i]!=nums[i-1])
                    return nums[i];
            }


        } return -1;   
    }
};

// Binary search 
//540. Single Element in a Sorted Array


class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        int l=1;
        int r=n-2;
        if(n==1)return arr[0];
        if(arr[0]!=arr[1])return arr[0];
        if(arr[n-1]!=arr[n-2])return arr[n-1];
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])return arr[mid];
            // elimiate a serach space where element is not present 
            if((mid%2==1 && arr[mid]==arr[mid-1])|| mid%2==0 && arr[mid]==arr[mid+1]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
};


// 162. Find Peak Element


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
            int n=nums.size();
            int l=1;
            int r=n-2;
            if(n==1)return 0;
            if(nums[0]>nums[1])return 0;
            if(nums[n-1]>nums[n-2])return n-1;

            while(l<=r){
                int mid=(l+r)/2;
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                    return mid;

                if(nums[mid]>nums[mid-1]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }


            }
            return -1;
    }
};
