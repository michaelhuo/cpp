#include <cstdlib>
#include <climits>
using namespace std;
int find_least_common_number(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
  //TODO: Write - Your - Code
  int size1 = arr1.size();
  int size2 = arr2.size();
  int size3 = arr3.size();
  int size = size1 < size2? size1 : size2;
  size = size < size3? size : size3;
  vector<int> arrs[3] = {arr1, arr2, arr3};
  int subs[3] = {0, 0, 0}; 

  while (subs[0] < size && subs[1] < size && subs[2] < size) {
    if (arrs[0][subs[0]] == arrs[1][subs[1]] && arrs[1][subs[1]] == arrs[2][subs[2]]) {
      return arrs[0][subs[0]];
    } 
    int idx = 0;
    int arr_index = idx;
    int min_index = subs[idx];
    int min_value = arrs[idx][min_index];
    for (int idx = 1; idx < 3; idx ++) {
      if (arrs[idx][subs[idx]] < min_value) {
        arr_index = idx;
        min_index = subs[idx];
        min_value = arrs[idx][min_index];
      }
    }
    subs[arr_index] ++;
  } 
  return -1;
}
