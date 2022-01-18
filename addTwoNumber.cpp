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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int over = 0;
        int sum = 0;
        bool l1End = false;
        bool l2End = false;
        
        ListNode* res = new ListNode;
        
        ListNode* l1Iter = l1;
        ListNode* l2Iter = l2;
        ListNode* resIter = res;
        
        while(true){
            sum = l1Iter->val + l2Iter->val + over;
            over = 0;
            if(sum >= 10){
                over = 1;
                sum -= 10;
            }
            resIter->val = sum;
            l1Iter = l1Iter->next;
            l2Iter = l2Iter->next;
            
            if(l1Iter == nullptr || l2Iter == nullptr){
                if(l1Iter == nullptr) l1End = true;
                if(l2Iter == nullptr) l2End = true;
                if(l1End == true || l2End == true) break;
            }
            resIter->next = new ListNode;
            resIter = resIter->next;
        }
        
        if(l1End)
        {
            while(l2Iter != nullptr){
                sum = l2Iter->val + over;
                over = 0;
                if(sum >= 10){
                    over = 1;
                    sum -= 10;
                }
                resIter->next = new ListNode;
                resIter = resIter->next;
                resIter->val = sum;
                l2Iter = l2Iter->next;
            }
        }
        else
        {
            while(l1Iter != nullptr){
                sum = l1Iter->val + over;                
                over = 0;
                if(sum >= 10){
                    over = 1;
                    sum -= 10;
                }
                resIter->next = new ListNode;
                resIter = resIter->next;
                resIter->val = sum;
                l1Iter = l1Iter->next;
            }
        }
        if(over)
        {
            resIter->next = new ListNode;
            resIter = resIter->next;
            resIter->val = over;
            over = 0;
        }
        return res;
    }
};
