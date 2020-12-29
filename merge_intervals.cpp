#include <iostream>
using namespace std;
class Pair{
  public:
    int first, second;
    Pair(int x, int y){
      first = x;
      second = y; 
    }
};

vector<Pair> merge_intervals(vector<Pair>& v){
  vector<Pair> result;
  if (v.empty()) {
    return result;
  }
  int size = v.size();
  int start = v[0].first;
  int stop = v[0].second;
  for (int i = 1; i < size; i++) {
    Pair& p = v[i];
    //std::cout << p.first << ',' << p.second << std::endl;
    if (p.first <= stop) {
      if (p.second > stop) {
        stop = p.second;
      }
    } else {
      Pair pair(start, stop);
      result.push_back(pair);
      start = p.first;
      stop = p.second;
    }
  }
  Pair pair(start, stop);
  result.push_back(pair);
  return result; 
}
