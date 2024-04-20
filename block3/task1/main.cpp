#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  int n, k, p, car;
  cin >> n >> k >> p;

  vector<int> last_seen(n, -1), next_use(p, p);
  for (int i = 0; i < p; ++i) {
    cin >> car;
    --car;
    if (last_seen[car] != -1) next_use[last_seen[car]] = i;
    last_seen[car] = i;
  }

  int count = 0;
  set<int> on_floor;
  for (int i = 0; i < p; ++i) {
    if (!on_floor.count(i)) {
      ++count;
      if (on_floor.size() == k) on_floor.erase(prev(on_floor.end()));
    } else {
      on_floor.erase(i);
    }
    on_floor.insert(next_use[i]);
  }

  cout << count << endl;
  return 0;
}