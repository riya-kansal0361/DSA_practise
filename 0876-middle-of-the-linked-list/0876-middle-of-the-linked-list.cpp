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
    private:
    int length(ListNode *head) {
  int i = 0;
  while (head != NULL) {
    i++;
    head = head->next;
  }

  return i;
}
public:
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) {
      return head;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }
    int l = length(head);
    if(l%2 == 0){
        return slow->next;
    }

    else{
        return slow;
    }
    }
};