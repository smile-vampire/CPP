#include<iostream>
#include<stack>

struct ListNode{
  int value;
  ListNode* pNext;
};

void ListReverse(ListNode* pHead)
{
  std::stack<ListNode*>nodes;
  
  ListNode* pNode = pHead;
  while(pNode != nullptr)
  {
    nodes.push(pNode);
    pNode = pNode->pNext;
  }

  while(!nodes.empty())
  {
    pNode = nodes.top();
    printf("%d\t",pNode->value);
    nodes.pop();
  }
}

