// Find the permutation of the gicen array 

// approch 
//1. iterate over each character of the string
//2. for each character, 
//   1. start to pick the first char
//   2. go back (backtrack)
//   3. pick the next char

class Solution {
public:
    vector<vector<int>> result;
    
    // Backtracking
    void permutation(vector<int> &nums,int i,int n){
        if(i==n){
            result.push_back(nums);
            return ;
        }

        for(int j=i;j<=n;j++){
            swap( nums[i],nums[j]);
            permutation(nums,i+1,n);
            swap( nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        permutation(nums,0,nums.size()-1);
        
        return result;
    }
};

// Time Complexity: O(n*n!)
// Space Complexity: O(n*n!)