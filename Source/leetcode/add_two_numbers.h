#pragma once
#include <iostream>
#include <cmath>

struct ListNode
{
   int val;
   ListNode* next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode* next) : val(x), next(next) {}
};

inline ListNode* create_node(int val)
{
   ListNode* pNode = new ListNode();
   pNode->val = val;
   return pNode;
}

inline ListNode* list_from_int(size_t val, bool reverse = false)
{
   if (val == 0)
      return create_node(0);

   const size_t digitsCount = static_cast<size_t>(log10(val)) + 1;

   ListNode* pRootNode = nullptr;
   ListNode* pPrevNode = nullptr; // Used only if reverse
   for (size_t i = digitsCount; i > 0; --i)
   {
      const int digit = val % 10;
      val /= 10;

      if (pRootNode == nullptr)
      {
         pRootNode = create_node(digit);
         continue;
      }

      ListNode* pNewNode = create_node(digit);
      if (reverse)
      {
         if (pPrevNode == nullptr)
            pPrevNode = pRootNode;
         pPrevNode->next = pNewNode;
         pPrevNode = pPrevNode->next;
      }
      else
      {
         pNewNode->next = pRootNode;
         pRootNode = pNewNode;
      }
   }
   return pRootNode;
}

inline size_t list_to_int(ListNode* pList, bool reverse = false)
{
   size_t val = 0;
   if (reverse)
   {
      size_t i = 0;
      for (ListNode* pNode = pList; pNode != nullptr; pNode = pNode->next)
         val += static_cast<size_t>(pNode->val) * static_cast<size_t>(pow(10, i++));
   }
   else
   {
      size_t digitsCount = 0;
      for (ListNode* pNode = pList; pNode != nullptr; pNode = pNode->next, ++digitsCount);

      size_t i = digitsCount - 1;
      for (ListNode* pNode = pList; pNode != nullptr && i >= 0; pNode = pNode->next, --i)
         val += static_cast<size_t>(pNode->val) * static_cast<size_t>(pow(10, i++));
   }
   return val;
}

class Solution
{
public:
   ListNode* addTwoNumbers(ListNode* pList1, ListNode* pList2)
   {
      const size_t v1 = list_to_int(pList1, true);
      const size_t v2 = list_to_int(pList2, true);
      return list_from_int(v1 + v2, true);
   }
};

// DEBUG ZONE
inline void cout_list(ListNode* pList)
{
   ListNode* pNode = pList;
   for (; pNode != nullptr; pNode = pNode->next)
      std::cout << pNode->val;
   std::cout << std::endl;
}

inline bool run_test()
{
   //ListNode* l = list_from_int(1000, true);
   //ListNode* list1 = list_from_int(1000000000000000000000000000001);
   //ListNode* list2 = list_from_int(564);
   //cout_list(list1);
   //cout_list(list2);
   //cout_list(Solution().addTwoNumbers(list1, list2));
   return true;
}