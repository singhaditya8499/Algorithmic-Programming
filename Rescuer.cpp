// https://www.hackerearth.com/problem/algorithm/rescuer-2d2495cb/

#include<bits/stdc++.h>
using namespace std;

double calculate(double m, double x1, double y1, double x2, double y2, double v1, double v2) {
    double ans = 0;
    double distL2E = sqrt(pow(abs(m-x1),2) + pow(abs(y1),2));
    double distE2S = sqrt(pow(abs(m-x2),2) + pow(abs(y2),2));
    ans = distL2E/v1 + distE2S/v2;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        double x1,y1,x2,y2,v1,v2;
        cin>>x1>>y1>>x2>>y2>>v1>>v2;
        if(x2<x1) {
            x1 = -x1;
            x2 = -x2;
        }
        double low = x1;
        double high = x2;
        while(high-low>0.000001) {
            double m1 = low + (high-low)/3.0;
            double m2 = high - (high-low)/3.0;

            double valueAtM1 = calculate(m1,x1,y1,x2,y2,v1,v2);
            double valueAtM2 = calculate(m2,x1,y1,x2,y2,v1,v2);

            if(valueAtM1>valueAtM2) {
                low = m1;
            } else if(valueAtM2>valueAtM1) {
                high = m2;
            } else {
                low = m1;
                high = m2;
            }
        }
        double ans = calculate(low,x1,y1,x2,y2,v1,v2);
        printf("%0.5f\n",ans);
    }
    
}