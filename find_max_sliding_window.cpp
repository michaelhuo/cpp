#include <cstdlib>
vector<int> find_max_sliding_window(vector<int>& v, int window_size) {
 vector<int> result;
 //Write your code
 int i = -1, j = -1;
 int size = v.size();
 if (size == 0) {
     return result;
 }
 int max_value = v[0], max_index = 0;
 int min_size  = window_size;
 if (size <= window_size) {
    min_size = size;
 } else{
    min_size = window_size;
 }
 for (i = 1; i < min_size; ++i) {
     if (v[i] >= max_value) {
        max_value = v[i];
        max_index = i;
     }
 }
 result.push_back(max_value);
 if (i == size) {
     return result;
 }
 
 for (j = 0; i < size; ++i) {
     ++j;
     if (j - 1 == max_index) {
         max_index = j;
         max_value = v[j];
         for (int k = j + 1; k < i; k++) {
             if (v[k] >= max_value) {
                 max_value = v[k];
                 max_index = k;
             }
         }
     }
     if (v[i] >= max_value) {
         max_value = v[i];
         max_index = i;
     }
     result.push_back(max_value);
 } 
 return result;
}

