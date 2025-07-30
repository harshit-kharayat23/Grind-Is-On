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
