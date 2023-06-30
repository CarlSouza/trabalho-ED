#ifndef __SORT_ALGORITHIMS_HPP_
#define __SORT_ALGORITHIMS_HPP_

// #include "../headers/LinkedList.hpp"
// #include "../headers/TreeNode.hpp"

void treeToList(struct TreeNode* root, struct ListNode** head);
void sort(struct TreeNode* root);
void showSort(struct TreeNode* root);
int find_max(struct ListNode* head);
void print_bars(struct ListNode** head);
void printSortOptions();

void bubbleSort(struct ListNode** head, bool showSort_);
void insertionSort(struct ListNode** head, bool showSort);
void selectionSort(struct ListNode** head, bool showSort);
void shellSort(struct ListNode** head, bool showSort);

#endif // __SORT_ALGORITHIMS_HPP_
