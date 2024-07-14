#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;

// //Brute force 
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//        for(int i=0; i<nums.size(); i++){
//         for(int j=i+1; j<nums.size(); j++){
//             if(nums[i] == nums[j]){
//                 return nums[j];
//             }
//         }
//        } 
//        return -1;
//     }
// };

// Time Complexity - O(n^2)
// Space Complexity - O(1)

//Optimal Solution 01
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      unordered_map<int,int> mp;
      for(int i=0; i<nums.size(); i++){
        mp[nums[i]]++;
      }
      for(auto i: mp){
        if(i.second > 1){
            return i.first;
        }
      }
      return -1;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)  // for storing the frequency of each element

//optimal Solution 02
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = -1;

    for(int i=0; i<nums.size(); i++){
        int index = abs(nums[i]);

        //if found visited
        if(nums[index] < 0){
            return index;
        }

        //mark negative/visited
        nums[index] *= -1;
    }
        return -1;
    }
};