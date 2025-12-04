#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, head;
    cin >> n;
    int req[n], done[n]={0};
    for(int i=0;i<n;i++) cin >> req[i];
    cin >> head;

    int total = 0;
    for(int i=0;i<n;i++){
        int idx=-1, mn=1e9;
        for(int j=0;j<n;j++){
            if(!done[j] && abs(req[j]-head) < mn){
                mn = abs(req[j]-head);
                idx = j;
            }
        }
        total += abs(req[idx]-head);
        head = req[idx];
        done[idx] = 1;
    }

    cout << total;
}
