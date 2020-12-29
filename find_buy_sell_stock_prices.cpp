#include <cstdlib>
#include <climits>
#include <utility>
#include <tuple>
using namespace std;
tuple<int, int> find_buy_sell_stock_prices(int* array, int size) { 
  //TODO: Write - Your - Code

  tuple<int, int> result(std::make_pair(-1, -1));
  if (size < 2) {
    return result;
  }
  vector<int> min_left(size, INT_MAX);
  vector<int> max_right(size, INT_MIN);
  int minimum = INT_MAX, maximum = INT_MIN;
  int max_price = INT_MIN, min_price = INT_MAX, max_profit = INT_MIN;
  for (int i = 0; i < size - 1; i++) {
    if (array[i] < minimum) {
      minimum = array[i];
    }
    min_left[i] = minimum;
  }
  for (int i = size - 1; i > 0; i--) {
    if (array[i] > maximum) {
      maximum = array[i];
    }
    max_right[i] = maximum;
  }
  for (int i = 0; i < size - 1; i++) {
    int profit = max_right[i + 1] - min_left[i];
    if (profit > max_profit) {
      max_profit = profit;
      min_price = min_left[i];
      max_price = max_right[i + 1];
    }
  }
  result = make_pair(min_price, max_price);
  return result; // t is a tuple with (high, low) price values
}
