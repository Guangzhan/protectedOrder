#include <iostream>
using namespace std;

struct node
{
   int value;
   int sequence;
};

node data[11];

int HeapSize = 10;

void exchange(node* l, node *r)
{
	node m = *l;
	*l = *r;
	*r = m;
}

void max_heapify(node *a, int i)
{
	int left = i << 1;
	int right = left | 1;
	
	int largest = i;
	if(left <= HeapSize && a[left].value > a[largest].value)
		largest = left;

	if(right <= HeapSize && a[right].value > a[largest].value)
		largest = right;

	if(i != largest)
	{
		exchange(&a[i], &a[largest]);
		max_heapify(a, largest);
	}
}

void build_max_heap(node* a)
{
	int i;
	for(i = HeapSize/2; i >= 1; i --)
		max_heapify(a, i);
}

void heap_sort(node* a)
{
	while(HeapSize >= 1)
	{
		exchange(&a[HeapSize], &a[1]);
	

		HeapSize -= 1;
		max_heapify(a, 1);
	}
}
