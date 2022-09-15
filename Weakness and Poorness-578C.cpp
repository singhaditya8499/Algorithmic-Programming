// https://codeforces.com/problemset/problem/578/C

#include <iostream>
#include <vector>

using namespace std;

double calculate(vector<double> v) {
    double ans = 0;
    double minSum = 0, maxSum = 0;
    double sum = 0;
    for(int i=0;i<v.size();i++) {
        sum += v[i];
        minSum = min(minSum, sum);
        maxSum = max(maxSum, sum);
    }
    ans = maxSum - minSum;
    return ans;
}
int main() {
    int n;
    cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    long long minElement = LLONG_MAX;
    long long maxElement = LLONG_MIN;
    for(int i=0;i<n;i++) {
        minElement = min(minElement, arr[i]);
        maxElement = max(maxElement, arr[i]);
    }
    double low = minElement;
    double high = maxElement;
    while(high-low>0.000000000001) {
        double m1 = low + (high-low)/3;
        double m2 = high - (high-low)/3;
        vector<double> v1;
        vector<double> v2;
        for(int i=0;i<n;i++) {
            v1.push_back((arr[i]-m1));
            v2.push_back((arr[i]-m2));
        }
        double weakness1 = calculate(v1);
        double weakness2 = calculate(v2);
        if(weakness1>weakness2) {
            low = m1;
        } else if(weakness2>weakness1) {
            high = m2;
        } else {
            low = m1;
            high = m2;
        }
    }
    
    vector<double> v;
    for(int i=0;i<n;i++) {
        v.push_back((arr[i]-low));
    }
    double ans = calculate(v);
    // cout<<ans<<endl;
    printf("%0.12f\n",ans);
}