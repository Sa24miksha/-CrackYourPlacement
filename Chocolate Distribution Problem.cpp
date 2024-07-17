//Chocolate Distribution problem 

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
      sort(a.begin(),a.end());
        long long d=INT_MAX;
        int i=0,j=m-1;
        for(int i=0;j<n;i++,j++){
            d = min(d,a[j]-a[i]);
        }
        return d;
    
    }   
};