#include <bits/stdc++.h>
using namespace std;

int main() {
    int frames, n;
    cin >> frames >> n;

    vector<int> pages(n), f;
    for (int i = 0; i < n; i++) cin >> pages[i];

    int faults = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        if (find(f.begin(), f.end(), page) != f.end()) continue;

        if (f.size() < frames) {
            f.push_back(page);
            faults++;
        } else {
            int idx = -1, farthest = -1;
            for (int j = 0; j < f.size(); j++) {
                int nextUse = INT_MAX;
                for (int k = i + 1; k < n; k++) {
                    if (pages[k] == f[j]) {
                        nextUse = k;
                        break;
                    }
                }
                if (nextUse > farthest) {
                    farthest = nextUse;
                    idx = j;
                }
            }
            f[idx] = page;
            faults++;
        }
    }

    cout << faults;
    return 0;
}
