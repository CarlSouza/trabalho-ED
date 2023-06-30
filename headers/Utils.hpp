#ifndef __SORT_ALGORITHIMS_HPP_
#define __SORT_ALGORITHIMS_HPP_

// #include "../headers/LinkedList.hpp"
// #include "../headers/TreeNode.hpp"

void treeToList(struct TreeNode* root, struct ListNode** head);
void sort(struct TreeNode* root, int iTypeSort);

void bubbleSort(struct ListNode** head);
void insertionSort(struct ListNode** head);
void selectionSort(struct ListNode** head);
void shellSort(struct ListNode** head);

#endif // __SORT_ALGORITHIMS_HPP_
