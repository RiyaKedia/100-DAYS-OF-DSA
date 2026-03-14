/* The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 50005

typedef struct {
    int maxHeap[SIZE];
    int minHeap[SIZE];
    int maxSize;
    int minSize;
} MedianFinder;


/* ---------- Max Heap ---------- */

void maxHeapifyUp(int heap[], int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p] < heap[i]){
            int t=heap[p];
            heap[p]=heap[i];
            heap[i]=t;
            i=p;
        } else break;
    }
}

void maxHeapifyDown(int heap[], int size, int i){
    while(1){
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;

        if(l<size && heap[l]>heap[largest]) largest=l;
        if(r<size && heap[r]>heap[largest]) largest=r;

        if(largest!=i){
            int t=heap[i];
            heap[i]=heap[largest];
            heap[largest]=t;
            i=largest;
        } else break;
    }
}


/* ---------- Min Heap ---------- */

void minHeapifyUp(int heap[], int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p] > heap[i]){
            int t=heap[p];
            heap[p]=heap[i];
            heap[i]=t;
            i=p;
        } else break;
    }
}

void minHeapifyDown(int heap[], int size, int i){
    while(1){
        int smallest=i;
        int l=2*i+1;
        int r=2*i+2;

        if(l<size && heap[l]<heap[smallest]) smallest=l;
        if(r<size && heap[r]<heap[smallest]) smallest=r;

        if(smallest!=i){
            int t=heap[i];
            heap[i]=heap[smallest];
            heap[smallest]=t;
            i=smallest;
        } else break;
    }
}


/* ---------- MedianFinder ---------- */

MedianFinder* createMedianFinder(){
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->maxSize=0;
    obj->minSize=0;
    return obj;
}

void addNum(MedianFinder* obj, int num){

    obj->maxHeap[obj->maxSize]=num;
    maxHeapifyUp(obj->maxHeap,obj->maxSize);
    obj->maxSize++;

    int top=obj->maxHeap[0];
    obj->maxHeap[0]=obj->maxHeap[obj->maxSize-1];
    obj->maxSize--;
    maxHeapifyDown(obj->maxHeap,obj->maxSize,0);

    obj->minHeap[obj->minSize]=top;
    minHeapifyUp(obj->minHeap,obj->minSize);
    obj->minSize++;

    if(obj->minSize > obj->maxSize){
        int move=obj->minHeap[0];
        obj->minHeap[0]=obj->minHeap[obj->minSize-1];
        obj->minSize--;
        minHeapifyDown(obj->minHeap,obj->minSize,0);

        obj->maxHeap[obj->maxSize]=move;
        maxHeapifyUp(obj->maxHeap,obj->maxSize);
        obj->maxSize++;
    }
}

double findMedian(MedianFinder* obj){

    if(obj->maxSize > obj->minSize)
        return obj->maxHeap[0];

    return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}


/* ---------- Main Function ---------- */

int main(){

    MedianFinder* mf = createMedianFinder();

    int n,x;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Enter number: ");
        scanf("%d",&x);

        addNum(mf,x);

        printf("Current Median = %.2f\n",findMedian(mf));
    }

    free(mf);
}