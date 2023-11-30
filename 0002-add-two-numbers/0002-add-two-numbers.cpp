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
        ListNode* result = new ListNode();
        ListNode* resNext = result;
        int carry = 0;

        do{
            bool isNull1 = (l1 != nullptr);
            bool isNull2 = (l2 != nullptr);  

            //Defines sum and its carry
            int val1 = isNull1 ? l1->val : 0;
            int val2 = isNull2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum/10;
            resNext->val = sum%10;

            //Assigns the node's next
            l1 = isNull1 ? l1->next : nullptr;
            l2 = isNull2 ? l2->next : nullptr;
            if (l1 != nullptr || l2 != nullptr || carry > 0){
                ListNode* nextNode = new ListNode();
                resNext->next = nextNode;
            }
            
            //Jumps to the next node
            resNext = resNext->next;            
        }while (resNext != nullptr);

        return result;
    }
};