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
    ListNode* mergeNodes(ListNode* head) {

        vector<int> v;
        ListNode* temp = head->next;
        int sum = 0;
        int number = 0;
        while (temp != NULL) {
            if (temp->val != 0) {
                sum = sum + temp->val;
            } else {
                v.push_back(sum);
                sum = 0;
            }
            temp = temp->next;
        }
        ListNode* head1 = new ListNode(v[0]);
        ListNode* temp1 = head1;

        for (int i = 1; i < v.size(); i++) {
            ListNode* x = new ListNode(v[i]);
            temp1->next = x;
            temp1 = temp1->next;
        }

        return head1;
    }
};
