//Sort Colors
// brute force

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j]) {
                    std::swap(nums[i], nums[j]);
                }
            }
        }
    }
};

//time complexity - O(n^2)
//space complexity - O(1)

// optimal solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, n = nums.size();
        for(int num : nums) {
            if(num == 0) zeros++;
            else if(num == 1) ones++;
        }  

        for(int i = 0; i < zeros; ++i) {
            nums[i] = 0;
        }

        for(int i = zeros; i < zeros + ones; ++i) {
            nums[i] = 1;
        }

        for(int i = zeros + ones; i < n; ++i) {
            nums[i] = 2;
        }
    }
};

//time complexity - O(n)
//space complexity - O(1)