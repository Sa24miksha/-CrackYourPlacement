// Two sum problem 
//brute force approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target){
                    return {
                    i,j
                    };
                }
            }
        }
        return {
        
         };

    }
    
};

//time complexity is O(n^2) and space complexity is O(1)

//Optimal approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        //find the number (moreNeeded) 
        for(int i=0; i<n; i++){
            int moreNeeded = target - nums[i];
            if(mp.find(moreNeeded) != mp.end()){
                return{mp[moreNeeded],i};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};

//time complexity is O(n) and space complexity is O(n)