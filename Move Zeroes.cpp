//=Move Zeroes to end of array

// brute 

 class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0,next=0;i<nums.size();++i)
		if(nums[i])
			swap(nums[i],nums[next++]);
    }
};

//time complexity - O(n)
//space complexity - O(1)

// optimal
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j=0;
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};

//time complexity - O(n)
//space complexity - O(1)