//Jump Game
//Given an array of non-negative integers, you are initially positioned at the first index of the array.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachable = 0;
        for(int i=0; i<nums.size(); i++){
            if(reachable < i){
                return false;
            }

            reachable = max(reachable, i+nums[i]);
        }
        return true;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)