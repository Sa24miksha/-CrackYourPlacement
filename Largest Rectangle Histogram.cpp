//Largest Restangle Histogram
//brute force approach
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        for(int i=0; i<n; i++){
            int curr = heights[i];

            for(int j = i-1; j>=0; j--){
                if(heights[j] >= heights[i]){
                    curr += heights[i];
                }
                else{
                    break;
                }
            }
            for(int j=i+1;j<n; j++){
                if(heights[j]>= heights[i]){
                    curr += heights[i];
                }
                else{
                    break;
                }
            }
            res = max(res,curr);
        }
        return res;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(1)

//Optimized approach
//1. initialize result = 0
//2. find previous smaller and next smaller of every element
//3. now for each element height[i]{
//   int area = (ns[i]-ps[i]-1)*height[i];
//   result = max(result, area);
//}
//4. return result

class Solution {
public:

    //prev smaller 
    vector<int> previous_smaller(vector<int> & heights){
        vector<int> ans;
        stack<int> st;
        int n = heights.size();

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            int ele = (st.empty()) ? -1 : st.top();
            ans.push_back(ele);
            st.push(i);
        }
        return ans;
    }

    //next smaller 
    vector<int> next_smaller(vector<int> & heights){
        vector<int> ans;
        stack<int> st;
        int n = heights.size();

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            int ele = (st.empty()) ? n : st.top();
            ans.push_back(ele);
            st.push(i);
        }
           reverse(ans.begin(), ans.end());
           return ans;
        }


    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        vector<int> ps = previous_smaller(heights);
        vector<int> ns = next_smaller(heights);

        for(int i=0; i<n; i++){
            int curr = ( ns[i] - ps[i]-1 )* heights[i];
            res = max(res, curr );
        }
        return res;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

