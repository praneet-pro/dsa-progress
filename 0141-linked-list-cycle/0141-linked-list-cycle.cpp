/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) 
                return true;
        }
        return false;
    }
};


/*
What happens if this linked list represents high-frequency trading data, and it has 10 billion nodes? If you write down 10 billion memory addresses on your notepad, you are going to consume gigabytes of extra RAM just to solve a simple loop. That is an O(N) memory solution. A systems engineer cannot afford that.
*/