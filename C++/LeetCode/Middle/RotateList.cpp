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
ListNode* rotateRight(ListNode* head, int k) {
        if (!head){return nullptr;}
        if (k <= 0||head->next==nullptr){return head;}
        ListNode* cursor = head;
        int counter;
        while(cursor->next){
            cursor=cursor->next;
            counter++;
        }
        k=k%counter;
        
    return rotateRightWithNormalInput(head,k);
}
private:
    ListNode* rotateRightWithNormalInput(ListNode* head, int k){
    if (k <= 0||head->next==nullptr){return head;}
    ListNode* cursor = new ListNode(-1);
    cursor->next = head;
    
    while(cursor->next->next){
    cursor=cursor->next;
    }

    ListNode*temp = cursor->next;
    cursor->next = nullptr;
    temp->next=head;
    return rotateRightWithNormalInput(temp,k-1);
    }
};
