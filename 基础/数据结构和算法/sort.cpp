#include <iostream>
#include<vector>
#include<ctime>
#include<cmath>
using namespace std;
//一些功能集成
void swap(vector<int>& Data, int i, int j)
{
	int temp;
	temp = Data[i];
	Data[i] = Data[j];
	Data[j] = temp;
}
void print(vector<int> Data)
{
	int length = Data.size();
	for (int i = 0; i < length; i++)
	{
		cout << Data[i] << " ";
	}
	cout << endl;
}
//冒泡排序初级版:交换排序
void bubbleSort0(vector<int>& Data) //注意如果传引用，会把主函数的pData修改
{
	cout << "Now we use bubbleSort0" << endl;
	cout << "the original data is:";
	print(Data);
	int length = Data.size();
	if (!length)
		return;
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (Data[i] > Data[j])
			{
				swap(Data, i, j);
			}
		}
	}
	cout << "the result is:";
	print(Data);
}
//冒泡排序,相邻两两交换
void bubbleSort(vector<int>& Data)
{
	cout << "Now we use bubbleSort." << endl;
	cout << "the original data is:";
	print(Data);
	int length = Data.size();
	if (!length)
		return;
	for (int i = 0; i < length; i++)
	{
		//注意数组上下界
		for (int j = length - 1; j > i; j--)
		{
			if (Data[j - 1] > Data[j])
			{
				swap(Data, j - 1, j);
			}
		}
	}
	cout << "the result is:";
	print(Data);
}
//改进的冒泡排序：最好情况，有序，比较n-1次，无需交换；最差情况，逆序，比较n*(n-1)/2，移动等数量级,O(n^2)
void bubbleSort2(vector<int>& Data)
{
	cout << "Now we use bubbleSort2." << endl;
	cout << "the original data is:";
	print(Data);
	int length = Data.size();
	bool continuesortflag = true;

	if (!length)
		return;

	for (int i = 0; i < length && continuesortflag; i++)
	{
		continuesortflag = false;
		for (int j = length - 1; j > i; j--)
		{
			if (Data[j - 1] > Data[j])
			{
				swap(Data, j - 1, j);
				continuesortflag = true;
			}
		}
	}
	cout << "the result is:";
	print(Data);
}
//简单选择排序:O(n^2),优点在于交换移动次序比较少；最好最坏比较次数一样多n(n-1)/2；交换最好0最差n-1;
void selectsort(vector<int>& Data)
{
	cout << "Now we use selectsort." << endl;
	cout << "the original data is:";
	print(Data);
	int length = Data.size();

	if (!length)
		return;

	for (int i = 0; i < length - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (Data[min] > Data[j])
			{
				min = j;
			}
		}
		if (i != min)
		{
			swap(Data, i, min);
		}
	}
	cout << "the result is:";
	print(Data);
}
//直接插入：将一个记录插入到已经排好序的有序表中,只需要一个记录的辅助空间，顺序比较n-1次，不需要移动，逆序比较（n+2）(n-1)/2次，移动（n+4）(n-1)/2次
//平均比较移动次数n^2/4次，时间复杂度O(n^2)，性能略优于冒泡和简单选择排序；
void insertsort(vector<int>& Data)
{
	cout << "Now we use selectsort." << endl;
	cout << "the original data is:";
	print(Data);
	int length = Data.size();

	if (!length)
		return;
	//注意i,j可以定义在循环体外扩大作用域
	int guard, i, j;

	for (i = 1; i < length; i++)
	{
		if (Data[i] < Data[i - 1])
		{
			guard = Data[i];
			for (j = i - 1; j >= 0 && Data[j] > guard; j--) //注意j>=0条件不可少,否则{2,5,6,1}会发生数组越界,&&短路运算，j>=0要写在前面
			{
				Data[j + 1] = Data[j];
			}
			Data[j + 1] = guard;
		}
	}
	cout << "the result is:";
	print(Data);
}
//希尔排序：基本有序而非局部有序；时间复杂度O(n^3/2),不稳定,属于插入排序的升级
//incremental如何取还没有解析解，但有经验解
void shellsort(vector<int>& Data)
{
	cout << "Now we use shellsort." << endl;
	cout << "the original data is:";
	print(Data);
	int length = Data.size();

	if (!length)
		return;

	int i, j, increment, guard;
	increment = length;
	do
	{
		increment = increment / 3 + 1;
		for (i = increment; i < length; i++)
		{
			if (Data[i] < Data[i - increment])
			{
				guard = Data[i];
				for (j = i - increment; j >= 0 && Data[j] > guard; j -= increment)
				{
					Data[j + increment] = Data[j];
				}
				Data[j + increment] = guard;
			}
		}

	} while (increment > 1);
	cout << "the result is:";
	print(Data);
}
/*
利用完全二叉树[log2n]+1特性，由于堆排序对原始记录的排序状态并不敏感， 因此它无论是最好、 最坏和平均时间复杂度均为O(nlogn)。 这在性能上显然要远远好过于冒泡、 简单选择、 直接插入的O(n^2)的时间复杂度了。
空间复杂度上，它只有一个用来交换的暂存单元， 也非常的不错。 不过由于记录 的比较与交换是跳跃式进行， 因此堆排序也是一种不稳定的排序方法。
另外， 由于初始构建堆所需的比较次数较多，因此， 它并不适合待排序序列个数较少的情况。 */
void HeapAdjust(vector<int>&Data, int s, int length)
{
	int temp, j;
	temp = Data[s];//先取出当前元素s
	for (j = 2 * s + 1; j < length; j = j * 2 + 1) /* 从s结点左子结点开始，也就是2*s+1处 */
	{
		if (1 + j < length && Data[j] < Data[j + 1])//j+1<length,即为右子结点存在。如果左子结点小于右子结点，j指向右子结点
		{
			j++;
		}
		if (Data[j] > temp)//如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
		{
			Data[s] = Data[j];
			s = j;
		}
		else
		{
			break;
		}
	}
	Data[s] = temp;
}
void heapsort(vector<int>& Data)
{
	cout << "Now we use heapsort." << endl;
	cout << "the original data is:";
	print(Data);
	int length = Data.size();

	if (!length)
		return;

	int i;
	for (i = length / 2 - 1; i >= 0; i--) /*  j结点的父节点为[j/2]，又下标从0开始，所以要减去1；把Data构建成一个大根堆 */
		HeapAdjust(Data, i, length);

	for (i = length - 1; i > 0; i--)
	{
		swap(Data, 0, i); /* 将堆顶记录和当前未经排序子序列的最后一个记录交换 */
		HeapAdjust(Data, 0, i); /*  将Data[0..i-1]重新调整为大根堆 */
	}
	cout << "the result is:";
	print(Data);
}

//非递归实现归并排序，比较占用内存，效率高，稳定；最好、最坏、平均时间性能O(nlogn);空间复杂度O(n)
void Merge(vector<int>& c, vector<int>& d, int left, int middle, int right)
{
    // 合并c[left:middle]和c[middle+1:right]到d[1eft:right]
    int i = left, j = middle + 1, k = left;
    while (i <= middle && j <= right) {
        if (c[i] <= c[j]) {
            d[k++] = c[i++];
        }
        else {
            d[k++] = c[j++];
        }
    }
    if (i > middle) {
        for (int q = j; q <= right; q++) {
            d[k++] = c[q];
        }
    } else {
        for (int q = i; q <= middle; q++) {
            d[k++] = c[q];
        }
    }
}

void MergePass(vector<int> &x, vector<int> &y, int gap, int length)
{
    // 合并大小为s的相邻子组
    int i = 0;
    while (i <= length-2*gap) {
        // 合并大小为s的相邻2段子数组
        Merge(x, y, i, i + gap - 1, i + 2 * gap  - 1);
        i = i + 2 * gap;
    }
    // 剩下的元素少于2s
    if ( i + gap < length ) {
        Merge(x, y, i, i + gap -1, length - 1);
    } else {
        for (int j = i; j <= length- 1; j++) {
            y[j] = x[j];
        }
    }
}

void MergeSort(vector<int> &Data, int length)
{
    vector<int> temp = vector<int>(length);
    int gap = 1;
    while (gap < length) {
        MergePass(Data, temp, gap, length);      // 合并到数组temp
        gap += gap;
        MergePass(temp, Data, gap, length);      // 合并到数组Data
        gap += gap;
    }

}

void Mergesort_interface(vector<int>& Data)
{
	cout << "Now we use mergesort." << endl;
	cout << "the original data is:";
	print(Data);
	int length = Data.size();
	if (!length)
		return;
    MergeSort(Data, length);
	cout << "the result is:";
	print(Data);
}

//快速排序,时间复杂度O（nlogn），空间复杂度O(logn),不稳定，冒泡排序升级
int Partition(vector<int>& Data,int low,int high)
{
    int pivotkey;
    pivotkey=Data[low];
    while(low<high)
    {
        while(low<high && Data[high]>=pivotkey)
        {
            high--;
        }
        swap(Data,low,high);
        while(low<high && Data[low]<=pivotkey)
        {
            low++;
        }
        swap(Data,low,high);
    }
    return low;
}
void Qsort(vector<int>&Data,int low,int high)
{
    int pivot;
    if(low<high)
    {
        pivot=Partition(Data,low,high);
        Qsort(Data,low,pivot-1);
        Qsort(Data,pivot+1,high);
    }
}
void quicksort(vector<int>& Data)
{
	cout << "Now we use quicksort." << endl;
	cout << "the original data is:";
	print(Data);
	int length = Data.size();

	if (!length)
		return;

    Qsort(Data,0,length-1);
	cout << "the result is:";
	print(Data);
}



//测试
int main()
{
	vector<int> Data = { 9,7,8,6,10,4,5,3,2};
	vector<int> p1, p2, p3, p4, p5, p6, p7,p8,p9;
	p1 = p2 = p3 = p4 = p5 = p6 = p7 = p8=p9=Data;
	time_t c_start, c_end;


	c_start = clock();
	bubbleSort0(p1);
	c_end = clock();
	cout << "当前排序算法花费时间为：" << difftime(c_end, c_start) << "ms" << endl << endl;

	c_start = clock();
	bubbleSort(p2);
	c_end = clock();
	cout << "当前排序算法花费时间为：" << difftime(c_end, c_start) << "ms" << endl << endl;

	c_start = clock();
	bubbleSort2(p3);
	c_end = clock();
	cout << "当前排序算法花费时间为：" << difftime(c_end, c_start) << "ms" << endl << endl;

	c_start = clock();
	selectsort(p4);
	c_end = clock();
	cout << "当前排序算法花费时间为：" << difftime(c_end, c_start) << "ms" << endl << endl;

	c_start = clock();
	insertsort(p5);
	c_end = clock();
	cout << "当前排序算法花费时间为：" << difftime(c_end, c_start) << "ms" << endl << endl;

	c_start = clock();
	shellsort(p6);
	c_end = clock();
	cout << "当前排序算法花费时间为：" << difftime(c_end, c_start) << "ms" << endl << endl;

	c_start = clock();
	heapsort(p7);
	c_end = clock();
	cout << "当前排序算法花费时间为：" << difftime(c_end, c_start) << "ms" << endl << endl;

	c_start = clock();
    Mergesort_interface(p8);
	c_end = clock();
	cout << "当前排序算法花费时间为：" << difftime(c_end, c_start) << "ms" << endl << endl;

	c_start = clock();
	quicksort(p9);
	c_end = clock();
	cout << "当前排序算法花费时间为：" << difftime(c_end, c_start) << "ms" << endl << endl;


	return 0;
}
