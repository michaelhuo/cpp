#include <climits>
#include <cstdlib>

tuple<int, int> find_buy_sell_stock_prices(int* array, int size) { 
  //TODO: Write - Your - Code
  if (!array || size < 2) {
    tuple<int, int> tmp(std::make_pair(-1, -1));
    return tmp;
  }
  int buy_price = array[0], sell_price = array[1];
  int min_buy_price = buy_price, max_sell_price = sell_price;
  int max_profit = max_sell_price - min_buy_price;
  for (int i = 1; i < size; ++i) {
    int cost = array[i];
    if (cost > sell_price) {
      sell_price = cost;
      int profit = sell_price - buy_price;
      if (profit > max_profit) {
        max_profit = profit;
        max_sell_price = sell_price;
        min_buy_price = buy_price;
      }
    }
    if (cost < buy_price ) {
      buy_price = cost;
      sell_price = INT_MIN;
    }
  }
  tuple<int, int> result(std::make_pair(min_buy_price, max_sell_price));
  return result; // t is a tuple with (high, low) price values
}
