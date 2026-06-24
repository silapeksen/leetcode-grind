// Last updated: 24.06.2026 13:29:08
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
struct ListNode* root=NULL;
struct ListNode* iter=NULL;
int carry=0;

while(l1!=NULL||l2!=NULL||carry!=0){
int sum=carry;
if(l1!=NULL){
sum+=l1->val;
l1=l1->next;
}
if(l2!=NULL){
    sum+=l2->val;
    l2=l2->next;
}
carry=sum/10;
struct ListNode* sum_node=(struct ListNode*)malloc(sizeof(struct ListNode));
sum_node->val=sum%10;
sum_node->next=NULL;

if(root==NULL){
    root=sum_node;
    iter=root;
}
else{
    iter->next=sum_node;
    iter=iter->next;
}

 
    
}
return root;

}