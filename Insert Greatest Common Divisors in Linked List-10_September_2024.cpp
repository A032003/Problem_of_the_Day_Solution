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
    int gcd(int a, int b) {
        int result = min(a, b);
        while (result > 0) {
            if (a % result == 0 && b % result == 0) {
                break;
            }
            result--;
        }
        return result;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* temp = head;
        while (temp->next != NULL) {

            int ans = gcd(temp->val, temp->next->val);
            ListNode* currnext = temp->next;
            ListNode* newNode = new ListNode(ans);
            temp->next = newNode;
            newNode->next = currnext;
            temp = temp->next->next;
        }
        return head;
    }
};
