// https://www.spoj.com/problems/KOPC12A/

#include <iostream>
#include <climits>

using namespace std;
long long calculate(long long m, int n, long long height[], long long cost[]) {
    long long ans = 0;
    for(int i=0;i<n;i++) {
        ans += (abs(m-height[i])*cost[i]);
    }
    return ans;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        long long height[n], cost[n];
        for(int i=0;i<n;i++) {
            cin>>height[i];
        }
        for(int i=0;i<n;i++) {
            cin>>cost[i];
        }
        long long minHeight = LLONG_MAX;
        long long maxHeight = LLONG_MIN;
        for(int i=0;i<n;i++) {
            minHeight = min(minHeight,height[i]);
        }
        for(int i=0;i<n;i++) {
            maxHeight = max(maxHeight, height[i]);
        }
        long long low = minHeight, high = maxHeight;
        while(high-low>2) {
            // cout<<low<<" "<<high<<endl;
            long long m1 = low + (high-low)/3;
            long long m2 = high - (high-low)/3;

            long long costForM1 = calculate(m1,n,height,cost);
            long long costForM2 = calculate(m2,n,height,cost);

            if(costForM1>costForM2) {
                low = m1;
            } else if(costForM2>costForM1) {
                high = m2;
            } else {
                low = m1;
                high = m2;
            }
        }
        long long ans = LLONG_MAX;
        for(long long i=low;i<=high;i++) {
            ans = min(ans,calculate(i,n,height,cost));
        }
        cout<<ans<<endl;
    }
}