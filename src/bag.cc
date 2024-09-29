#include <bag.h>

int bag1(vector<int>& weight, vector<int>& value, int bagWeight) {
  vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));
  for (int j = weight[0]; j <= bagWeight; ++j) {
    dp[0][j] = value[0];
  }

  for (int i = 1; i < weight.size(); ++i) {
    for (int j = 0; j <= bagWeight; ++j) {
      if (j < weight[i]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
      }
    }
  }
  return dp[weight.size() - 1][bagWeight];
}
int bag2(vector<int>& weight, vector<int>& value, int bagWeight) {
  vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));
  for (int j = weight[0]; j <= bagWeight; ++j) {
    dp[0][j] = value[0];
  }

  for (int j = 0; j <= bagWeight; ++j) {
    for (int i = 1; i < weight.size(); ++i) {
      if (j < weight[i]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
      }
    }
  }
  return dp[weight.size() - 1][bagWeight];
}
int bag3(vector<int>& weight, vector<int>& value, int bagWeight) {
  vector<int> dp(bagWeight + 1, 0);
  for (int i = 0; i < weight.size(); ++i) {
    for (int j = bagWeight; j > 0; --j) {
      dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
  }
  return dp[bagWeight];
}