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
    ListNode* insertionSortList(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode demo(0);
        demo.next = head;

        ListNode* curr = head->next;
        ListNode* prevCurr = head;

        while (curr != NULL) {

            ListNode* next = curr->next;

            ListNode* prev = &demo;

            while (prev->next != curr && prev->next->val <= curr->val) {

                prev = prev->next;
            }

            if (prev->next != curr) {

                prevCurr->next = next;

                curr->next = prev->next;
                prev->next = curr;

            } else {

                prevCurr = curr;
            }

            curr = next;
        }

        return demo.next;
    }
};