#include <bits/stdc++.h>
using namespace std;

int main() {
    int frames, n;
    cin >> frames >> n;

    vector<int> pages(n), f;
    for (int i = 0; i < n; i++) cin >> pages[i];

    unordered_map<int,int> lastUsed;
    int time = 0, faults = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        time++;

        if (find(f.begin(), f.end(), page) != f.end()) {
            lastUsed[page] = time;
            continue;
        }

        if (f.size() < frames) {
            f.push_back(page);
            lastUsed[page] = time;
            faults++;
        } else {
            int lruPage = f[0];
            for (int p : f)
                if (lastUsed[p] < lastUsed[lruPage])
                    lruPage = p;

            for (int j = 0; j < f.size(); j++)
                if (f[j] == lruPage)
                    f[j] = page;

            lastUsed[page] = time;
            faults++;
        }
    }

    cout << faults;
    return 0;
}
