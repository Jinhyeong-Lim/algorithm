#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int* cnt;
queue<int> q;
int n, m; 
struct node {
   int ver;

   node* next, * prev;
   node() 
   {
      next = prev = NULL;
      ver = 0;
   }
   node(int i, node* ptr) {
      ver = i;
      prev = ptr;
      next = ptr->next;
      next->prev = prev->next = this;
   }
};

struct linkedlist {
   node* head;
   node* tail;
   int cnt1;
   linkedlist() {
      head = new node();
      tail = new node();
      head->next = tail;
      tail->prev = head;
   }
   void insert(int i) {
      new node(i, tail->prev);
   }
};

void tst(linkedlist **list, int n)
 {
   for (int i = 0; i < n; i++) 
   {
      if (list[i]->cnt1 == 0) 
	  {
         q.push(i);
      }
   }
   while (!q.empty())
    {
      int j = q.front();
      printf("%d ", j);
      q.pop();
      node* ptr = list[j]->head;
      while (ptr->next != NULL) 
	  {
         list[ptr->ver]->cnt1--;
         if (list[ptr->ver]->cnt1 == 0) q.push(ptr->ver);
         ptr = ptr->next;
      }
    }
}


int main()
 {
   
   cin >> n >> m;

   linkedlist** list = new linkedlist * [n+1];
   for (int i = 0; i < n + 1; i++)
    {
	 list[i] = new linkedlist();
	}
   for (int i = 0; i < n + 1; i++)
    {
	 list[i]->cnt1 = 0; 
	}

   

   for (int i = 0; i < m; i++) 
   {
      int a, b;
      cin >> a >> b;
      list[a]->insert(b);
      list[b]->cnt1++;
   }

   printf("\n");
   tst(list,n);
   printf("\n");
   return 0;
}


