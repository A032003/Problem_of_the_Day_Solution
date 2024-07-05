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
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        if (count <= 2) {
            return {-1, -1};
        }
        vector<int> arr;
        ListNode* temp1 = head;

        while (temp1 != NULL) {
            arr.push_back(temp1->val);
            temp1 = temp1->next;
        }
        vector<int> idx;

        for (int i = 1; i < arr.size() - 1; i++) {
            if ((arr[i - 1] > arr[i]) && (arr[i] < arr[i + 1])) {
                idx.push_back(i + 1);
            } else if ((arr[i - 1] < arr[i]) && (arr[i] > arr[i + 1])) {
                idx.push_back(i + 1);
            }
        }

        if (idx.size() < 2) {
            return {-1, -1};
        }

        int mini = idx[1] - idx[0];

        for (int i = 1; i < idx.size() - 1; i++) {
            mini = min(mini, idx[i + 1] - idx[i]);
        }
        int maxi = idx.back() - idx.front();

        return {mini, maxi};
    }
};
