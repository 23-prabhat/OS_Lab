#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, head, disk;
    cin >> n;
    int req[n];
    for(int i=0;i<n;i++) cin >> req[i];
    cin >> head >> disk;

    sort(req, req+n);

    int total = 0;
    int pos = lower_bound(req, req+n, head) - req;

    for(int i=pos;i<n;i++){
        total += abs(req[i]-head);
        head = req[i];
    }
    total += abs((disk-1)-head);
    head = disk-1;

    for(int i=pos-1;i>=0;i--){
        total += abs(req[i]-head);
        head = req[i];
    }

    cout << total;
}


