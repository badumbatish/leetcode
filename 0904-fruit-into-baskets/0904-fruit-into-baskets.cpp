class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        std::unordered_map<int, int> basket;

        int left, right;

        for (left = 0, right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++;

            if (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) basket.erase(fruits[left]);
                left++;
            }

            if (basket.size() > 2) return -1;
        }

        return right - left;
    }
};