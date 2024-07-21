//majority element is the element that appears more than n/2 times in the array

//brute force approach
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
            if(count > (n/2)){
                return nums[i];
            }
        }
        return -1;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(1)

//Optimized approach
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        //traverse and put login
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==candidate){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                candidate = nums[i];
                count = 1;
            }
        }
        return candidate;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

//using map

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it :mp){
            if(it.second> (n/2)){
                return it.first;
            }
        }
        return -1;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)