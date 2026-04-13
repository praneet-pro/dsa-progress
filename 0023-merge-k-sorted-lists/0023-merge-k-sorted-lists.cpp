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

    struct CompareNode {
        bool operator()(ListNode* a, ListNode* b) {     // for min heap
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> pq;

        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) 
                pq.push(lists[i]);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(!pq.empty()) {
            ListNode* winner = pq.top();
            pq.pop();
            tail->next = winner;
            tail = tail->next;

            if(winner->next != NULL)
                pq.push(winner->next);
        }
        return dummy->next;
    }
};