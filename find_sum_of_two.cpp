#include <unordered_set>
bool find_sum_of_two(vector<int>& A, int val) {
  //TODO: Write - Your - Code
    if (A.empty() || A.size() < 2) {
        return false;
    }
    int size = A.size();
    unordered_set<int> hash_set;
    for (int n : A) {
        int m = val - n;
        if (hash_set.find(m) != end(hash_set)) {
            return true;
        }
        hash_set.insert(n);
    }
  return false;
}
