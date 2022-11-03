#include <iostream>
#include <time.h>
#include <chrono>

using namespace std;
using namespace chrono;

// #define MAX 32 + 1 // 요소 32개인 경우
#define MAX 1024 + 1 // 요소 1024개인 경우

int arr[MAX];  
int compcount = 0; // 비교 횟수

void makeRandomArray() // Random한 배열을 생성하는 함수
{
    arr[0] = -1; // index = 0 은 사용 X
    for(int i = 1 ; i < MAX ; i++)
    {
        arr[i] = rand() % 10;
    }
}

void makeSortedArray() // sorted된 배열을 생성하는 함수
{
    arr[0] = -1;
    for(int i = 1 ; i < MAX ; i++)
    {
        arr[i] = i;
    }
}

int compCountV1(int x, int y) // 부등호가 없는 경우의 compCount
{
    compcount++;
    return x < y;
}

int compCountV2(int x, int y) // 부등호가 있는 경우의 compCount
{
    compcount++;
    return x <= y;
}

// 각 정렬마다의 output 배열
int i_arr[MAX];
int h_arr[MAX];
int m_arr[MAX];
int q_arr[MAX];
int rq_arr[MAX];
int mq_arr[MAX];
int dq_arr[MAX];


void swap(int* p, int* q)
{
    int* temp = p;
    p = q;
    q = temp;
}

void insertionSort(int arr[])
{
    int j;
    int i;
    int key;

    // 두 번째 요소부터 key넣고 비교
    // key의 앞 요소가 key보다 크면 한 칸 뒤로 밀어주고 key는 해당 요소의 앞에 삽입
    for(j=2; j<MAX; j++)
    {
        key = arr[j];
        i = j-1;
        while(compCountV1(0, i) && compCountV1(key, arr[i])) // i>0 && key < arr[i]
        {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}


int heapsize = MAX - 1;
int length = MAX - 1;
void maxHeapify(int arr[], int i)
{
    int l = 2*i; // i의 왼쪽 자식
    int r = 2*i+1; // i의 오른쪽 자식
    int largest;
    // l과 i의 값을 비교하여 둘 중 더 큰 값을 largest에 넣음.
    if (compCountV2(l, heapsize) && compCountV1(arr[i], arr[l])) // l<=heapsize && arr[i] < arr[l]
        largest = l;
    else largest = i;
    if (compCountV2(r, heapsize) && compCountV1(arr[largest], arr[r])) // r<=heapsize && arr[largest] < arr[r]
        largest = r;
    if (largest != i) // i와 largest의 값을 비교하였을 때 서로 값이 다르면 둘의 자리를 바꿔줌.
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest); // 원래 largest의 자리에 대하여 maxHeapify 반복.
    }
}

void buildMaxHeap(int arr[]) // arr을 maxHeap화 함.
{
    for(int i=length/2;i>0;i--)
        maxHeapify(arr, i);
}

void heapSort(int arr[])
{
    buildMaxHeap(arr); // 우선 maxHeap으로 만든다.
    for(int i=length;i>1;i--) // 마지막 노드부터 index가 2인 노드까지 반복
    {
        swap(arr[1], arr[i]); // root와 마지막 노드의 자리를 바꿈
        heapsize--;
        maxHeapify(arr, 1); // 바뀐 노드에 대하여 maxHeapify
    }
}


void merge(int arr[], int p, int q, int r) 
{

    int n1 = q - p + 1; 
    int n2 = r - q;

    int L[n1+1], R[n2+1];
    // 배열 두 개로 divide
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    // k = p;
    L[n1] = 99999;
    R[n2] = 99999; // 두 개로 나눈 배열의 각 끝에 무한대 추가

    for (int k = p ; k <= r; k++ )
    {
        // 두 배열의 각 요소를 비교하여 작은 요소부터 arr 배열에 넣음
        if(compCountV2(L[i], R[j])) // L[i] <= R[j]
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int arr[], int p, int r) {
    if (compCountV1(p, r)) // p < r
    {
        int q = (p + r) / 2; // 가운데 요소의 index를 q로 지정
        mergeSort(arr, p, q); // 둘로 나눈 배열을 다시 divide. recursive
        mergeSort(arr, q + 1, r); 
        merge(arr, p, q, r); // 둘로 나눈 배열을 합병
    }  
}

int partition(int arr[], int p, int r)
{
    // last element is pivot
    int x = arr[r];
    int i = p-1;
    for(int j = p;j<=r-1;j++)
    {
        // pivot보다 작은 값의 경우
        if(compCountV2(arr[j], x)) // arr[j] <= x
        {
            // i의 값을 하나 증가시키고 해당 자리와 swap
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // pivot보다 작은 요소들이 모두 앞으로 모엿으면 그 다음 자리와 pivot을 swap
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quickSort(int arr[], int p, int r)
{
    if (compCountV1(p, r)) // p < r
    {
        // q를 기준으로 두 개의 배열로 나눠 각각의 배열에 대하여 다시 quicksort를 함. recursive
        int q = partition(arr, p, r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}

int randomizedPartition(int arr[], int p, int r)
{
    int i =  p + rand() % (r-p); // 1 ~ 32 사이의 난수를 선택하여 pivot으로

    swap(arr[i], arr[r]); // pivot이 선정되면 마지막 요소와 자리를 바꾸고 이후는 기존 quick sort와 동일.
    return partition(arr, p, r);
}

void randomizedQuickSort(int arr[], int p, int r)
{
    if (compCountV1(p, r)) // p < r
    {
        int q = randomizedPartition(arr, p, r);
        randomizedQuickSort(arr, p, q-1);
        randomizedQuickSort(arr, q+1, r);
    }
}

int medianOfThreePartition(int arr[], int p, int r)
{
    int q = (p + r) / 2;
    // index = p, q, r인 세 가지의 값을 비교하여 중앙값을 pivot으로 선정.
    if (compCountV1(arr[q], arr[p])) // arr[q] < arr[p]
        swap(arr[q], arr[p]);
    if (compCountV1(arr[r], arr[p])) // arr[r] < arr[p]
        swap(arr[r], arr[p]);
    if (compCountV1(arr[q], arr[r])) // arr[q] < arr[r]
        swap(arr[q], arr[r]);

    // 중앙값으로 pivot이 선정되면 이후는 기존 quick sort 방식과 동일
    return partition(arr, p, r);
    
}

void medianQuickSort(int arr[], int p, int r)
{
    if (compCountV1(p, r)) // p < r
    {
        int q = medianOfThreePartition(arr, p, r);
        medianQuickSort(arr, p, q-1);
        medianQuickSort(arr, q+1, r);
    }
}

void dualPivotQuickSort(int arr[], int p, int r)
{
    if(compCountV2(p, r)) // p <= r
    {
        // pivot1이 pivot2보다 크다면 서로 자리를 바꿔줌
        if(compCountV1(arr[r], arr[p])) // arr[r] < arr[p]
            swap(arr[p], arr[r]);

        int pivot1 = arr[p], pivot2 = arr[r]; // 양 끝 2개의 요소를 각 pivot1과 pivo2로
        int l, k, g;
        // k : sort 진행 중일 때 배열을 지나가며 각 요소의 index를 저장

        l = k = p + 1; // l : pivot1보다 작은 값이 들어갈 다음 위치
        g = r - 1; // g : pivot2보다 큰 값이 들어갈 다음 위치

        while(compCountV2(k, g)) // k <= g
        {
            // pivot1보다 작은 값은 pivot1의 앞에 들어감
            if(compCountV1(arr[k], pivot1)) // arr[k] < pivot1
            {
                swap(arr[k], arr[l]);
                l++;
            }
            else // pivot1보다 큰 값의 경우
            {
                // 그중 pivot2보다 큰 값은 pivot2의 뒤에 들어감
                if(compCountV1(pivot2, arr[k])) // pivot2 < arr[k]
                {
                    while(compCountV1(pivot2, arr[g]) && compCountV1(k, g)) // (pivot2 < arr[g]) && (k < g)
                        g--;

                    swap(arr[k], arr[g]);
                    g--;
                    
                    // arr[k]가 pivot1보다 작으면 자기 자리가 아님
                    if(compCountV1(arr[k], pivot1)) // arr[k] < pivot1
                    {
                        swap(arr[k], arr[l]);
                        l++;
                    }
                }
            }
            k++;
        }
        l--;
        g++;
        
        swap(arr[p], arr[l]);
        swap(arr[r], arr[g]);

        dualPivotQuickSort(arr, p, l-1);
        dualPivotQuickSort(arr, l+1, g-1);
        dualPivotQuickSort(arr, g+1, r);
    }
}


int main()
{
    typedef duration<double, milli> doublemillisec; // 시스템 시간을 측정하기 위함.
    makeRandomArray(); // random한 수들로 배열을 생성ㄱ
    // makeSortedArray(); // sorted된 배열 생성

    // input 배열의 요소들을 output할 배열에 copy
    for(int i=0;i<MAX;i++){
        i_arr[i] = arr[i];
        h_arr[i] = arr[i];
        m_arr[i] = arr[i];
        q_arr[i] = arr[i];
        rq_arr[i] = arr[i];
        mq_arr[i] = arr[i];
        dq_arr[i] = arr[i];
    }
    // 원래 배열
    cout << "==================== Original Array ====================" << endl;
    for(int i=1;i<MAX;i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    
    compcount = 0; // Sort 시작 전 비교 횟수를 저장하는 compcount는 0으로 초기화하고 시작
    system_clock::time_point begin = system_clock::now(); // Sorting 시작 전  시스템 시간
    insertionSort(i_arr);
    system_clock::time_point end = system_clock::now(); // Sorting 끝난 직후 시스템 시간
    cout << "==================== Insertion Sort ====================" << endl;
    for(int i=1;i<MAX;i++)
    {
        cout << i_arr[i] << ' ';
    }
    cout << endl << "compcount : " << compcount << endl;
    doublemillisec doubleMilliSec = duration_cast<doublemillisec>(end - begin); // Sorting 끝난 직후 시스템 시간에서 시작 전 시스템 시간을 빼면 Sorting 시간임
    cout << "Sort time : " << doubleMilliSec.count() << endl;


    compcount = 0;
    begin = system_clock::now();
    heapSort(h_arr);
    end = system_clock::now();
    cout << "==================== Heap Sort ====================" << endl;
    for(int i=1;i<MAX;i++)
    {
        cout << h_arr[i] << ' ';
    }
    cout << endl << "compcount : " << compcount << endl;
    doubleMilliSec = duration_cast<doublemillisec>(end - begin);
    cout << "Sort time : " << doubleMilliSec.count() << endl;


    compcount = 0;
    begin = system_clock::now();
    mergeSort(m_arr, 1, MAX-1);
    end = system_clock::now();
    cout << "==================== Merge Sort ====================" << endl;
    for(int i=1;i<MAX;i++)
    {
        cout << m_arr[i] << ' ';
    }
    cout << endl << "compcount : " << compcount << endl;
    doubleMilliSec = duration_cast<doublemillisec>(end - begin);
    cout << "Sort time : " << doubleMilliSec.count() << endl;


    compcount = 0;
    begin = system_clock::now();
    quickSort(q_arr, 1, MAX-1);
    end = system_clock::now();
    cout << "==================== Quick Sort ====================" << endl;
    for(int i=1;i<MAX;i++)
    {
        cout << q_arr[i] << ' ';
    }
    cout << endl << "compcount : " << compcount << endl;
    doubleMilliSec = duration_cast<doublemillisec>(end - begin);
    cout << "Sort time : " << doubleMilliSec.count() << endl;


    compcount = 0;
    begin = system_clock::now();
    randomizedQuickSort(rq_arr, 1, MAX-1);
    end = system_clock::now();
    cout << "==================== Randomized Quick Sort ====================" << endl;
    for(int i=1;i<MAX;i++)
    {
        cout << rq_arr[i] << ' ';
    }
    cout << endl << "compcount : " << compcount << endl;
    doubleMilliSec = duration_cast<doublemillisec>(end - begin);
    cout << "Sort time : " << doubleMilliSec.count() << endl;


    compcount = 0;
    begin = system_clock::now();
    medianQuickSort(mq_arr, 1, MAX-1);
    end = system_clock::now();
    cout << "==================== Median Quick Sort ====================" << endl;
    for(int i=1;i<MAX;i++)
    {
        cout << mq_arr[i] << ' ';
    }
    cout << endl << "compcount : " << compcount << endl;
    doubleMilliSec = duration_cast<doublemillisec>(end - begin);
    cout << "Sort time : " << doubleMilliSec.count() << endl;

    
    compcount = 0;
    begin = system_clock::now();
    dualPivotQuickSort(dq_arr, 1, MAX-1);
    end = system_clock::now();
    cout << "==================== DualPivot Quick Sort ====================" << endl;
    for(int i=1;i<MAX;i++)
    {
        cout << dq_arr[i] << ' ';
    }
    cout << endl << "compcount : " << compcount << endl;
    doubleMilliSec = duration_cast<doublemillisec>(end - begin);
    cout << "Sort time : " << doubleMilliSec.count() << endl;
}