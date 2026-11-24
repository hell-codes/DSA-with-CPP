/*
Question No: 2
Remove the smallest and largest elements and insert their
difference. After K operations, print the sum of the array.
Each query starts from the original array.
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    multiset<long long> s;
    long long sum=0;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        s.insert(x);
        sum+=x;
    }
    vector<long long> ans(n);
    ans[0]=sum;
    for(int i=1;i<n;i++){
        auto mn=s.begin();
        auto mx=prev(s.end());
        long long a=*mn,b=*mx;
        s.erase(mn);
        s.erase(mx);
        s.insert(b-a);
        sum-=a+b;
        sum+=b-a;
        ans[i]=sum;
    }
    while(q--){
        int k;
        cin>>k;
        cout<<ans[k]<<"\n";
    }
}
