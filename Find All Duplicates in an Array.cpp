//Find all duplicates in an array 
// Brute Force Approach
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto i: mp){
            if(i.second > 1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};

//Time complexity is O(n) and space complexity is O(n)

//Optimal Approach
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int x = abs(nums[i]);

            //check if already -ve 
            if(nums[x-1] < 0){
                ans.push_back(x);
            }


            //mark all the visited as -1
            nums[x-1] *= -1;
        }

        return ans;
    }
};

//Time complexity is O(n) and space complexity is O(1)