/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        std::vector<int> result = { -1, -1};

        int minDistance = INT_MAX;
        ListNode* previousNode = head;
        ListNode* currentNode = head->next;

        int currentIndex = 1;
        int previousCriticalIndex =  0;
        int firstCriticalIndex = 0;

        while (currentNode->next != nullptr) {
            if ((currentNode -> val < previousNode->val && currentNode->val < currentNode->next->val) ||
                (currentNode->val > previousNode->val && currentNode->val > currentNode->next->val)) {
                    if (previousCriticalIndex == 0) {
                        previousCriticalIndex = currentIndex;
                        firstCriticalIndex = currentIndex;
                    } else {
                        minDistance = min (minDistance, currentIndex - previousCriticalIndex);
                        previousCriticalIndex = currentIndex;
                    }
                }
            currentIndex++;
                    previousNode = currentNode;
                    currentNode = currentNode->next;
        }

        if (minDistance != INT_MAX ) {
            int maxDistance = previousCriticalIndex - firstCriticalIndex;
            result = { minDistance, maxDistance };
        }

        return result;
    }
};