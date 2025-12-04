#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, head;
    cin >> n;
    int req[n];
    for(int i=0;i<n;i++) cin >> req[i];
    cin >> head;

    sort(req, req+n);
    int total = 0;
    int pos = lower_bound(req, req+n, head) - req;

    for(int i=pos;i<n;i++){
        total += abs(req[i]-head);
        head = req[i];
    }

    total += abs(head - req[0]);
    head = req[0];

    for(int i=1;i<pos;i++){
        total += abs(req[i]-head);
        head = req[i];
    }

    cout << total;
}
