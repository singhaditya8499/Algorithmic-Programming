//https://www.codechef.com/problems/AMCS03

#include <iostream>
using namespace std;
double calculateMax(int n,int speed[],int distance[],double t) {
    double maxx = -100.0;
    for(int i=0;i<n;i++) {
        double tmp = speed[i]*t + distance[i];
        maxx = max(maxx, tmp);
    }
    return maxx;
}
double calculateMin(int n,int speed[],int distance[],double t) {
    double minn = 1e15;
    for(int i=0;i<n;i++) {
        double tmp = speed[i]*t + distance[i];
        minn = min(tmp,minn);
    }
    return minn;
}
int main() {
	// your code goes here
	int n,k;
	cin>>n>>k;
	int speed[n],distance[n];
	for(int i=0;i<n;i++) {
	    cin>>speed[i];
	    cin>>distance[i];
	}
	double low = 0,high = k;
	while(high-low>0.00000001) {
        cout<<low<<" "<<high<<endl;
	    double m1 = low + double(high-low)/3.0;
	    double m2 = high - double(high-low)/3.0;
	    double maxValueAtM1 = calculateMax(n,speed,distance,m1);
	    double minValueAtM1 = calculateMin(n,speed,distance,m1);
	    double maxValueAtM2 = calculateMax(n,speed,distance,m2);
	    double minValueAtM2 = calculateMin(n,speed,distance,m2);
	    
	    double valueAtM1 = maxValueAtM1 - minValueAtM1;
	    double valueAtM2 = maxValueAtM2 - minValueAtM2;
	    if(valueAtM1>valueAtM2) {
	        low = m1;
	    } else if(valueAtM1<valueAtM2) {
	        high = m2;
	    } else {
	        low = m1;
	        m2 = high;
	    }
	}
    double ans = (calculateMax(n,speed,distance,low) - calculateMin(n,speed,distance,low));
	printf("%0.6f\n",ans);
	return 0;
}
