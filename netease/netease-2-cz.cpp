#include <iostream>
using namespace std;

int main(){
    int n=11,k=6,t=3;
    // cin>>n>>k>>t;

    if(k < t + 1 || k+k-t-1>n){
        cout<<-1<<endl;
        return 0;
    }
    string ans = "";
    for(int i=0; i<=t; i++){
        ans += '1';
    }
    k -= t+1;
    while(k--){
        ans += "01";
    }
//     int left = n - ans.size(); 换成这个然后添加left个0就可以
    if(ans.size() <= n){
        for(int i=0; i<n-ans.size(); i++) {
            ans += '0';
        }
        cout<<ans<<endl;
    }
    else {
        cout<<-1<<endl;
    }
}