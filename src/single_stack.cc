#include <single_stack.h>

int trap(vector<int>& height) {
  stack<int> help;
  help.push(0);
  int result = 0;
  for (int i = 1; i < height.size(); ++i) {
    while (!help.empty() && height[i] > height[help.top()]) {
      int below = help.top();
      help.pop();
      if (!help.empty()) {
        result += (min(height[i], height[help.top()]) - height[below]) *
                  (i - help.top() - 1);
      }
    }
    help.push(i);
  }
  return result;
}

int largestRectangleArea(vector<int>& heights) {
  stack<int> help;
  help.push(0);
  heights.insert(heights.begin(), 0);
  heights.push_back(0);
  int result = 0;
  for (int i = 1; i < heights.size(); ++i) {
    while (!help.empty() && heights[i] < heights[help.top()]) {
      int left = help.top();
      help.pop();
      if (!help.empty()) {
        result = std::max(result, heights[left] * (i - help.top() - 1));
      }
    }
    help.push(i);
  }
  return result;
}