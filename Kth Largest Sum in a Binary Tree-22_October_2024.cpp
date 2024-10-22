/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> pq;
        queue<TreeNode*> q;
        long long sum = 0;
        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front == NULL) {
                pq.push(sum);
                sum = 0;
                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                sum = sum + front->val;
                if (front->left != NULL) {
                    q.push(front->left);
                }
                if (front->right != NULL) {
                    q.push(front->right);
                }
            }
        }

        if (k > pq.size()) {
            return -1;
        } else {
            while (k != 1) {
                pq.pop();
                k--;
            }
            return pq.top();
        }
    }
};
