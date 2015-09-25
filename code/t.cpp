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
int main(void)
{
int input[11]={0, 1, 2, 5, 8, 10, 4, 3, 6, 9, 7};

for (int i=1; i<=10; i++)
{
data[i].value= input[i];
data[i].sequence = i;
}

build_max_heap(data);
heap_sort(data);

// 	for (i=1; i<=10; i++)
// 	{
// 	 std::cout<<data[i].value<<" "<<data[i].sequence<<std::endl;
// 	}


int last = 1;
std::cout<<data[1].value<<" "<<std::flush;
for(i = 2; i <= 10; i ++)
{
if(data[i].sequence > data[last].sequence)
{
last = i;
std::cout<<std::endl;
}

std::cout<<data[i].value<<" ";
}

return 0;
}
