#include <iostream>
#include<vector>
#include<ctime>
#include<cmath>
using namespace std;


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
//ð�����������:��������
void bubbleSort0(vector<int>& Data) //ע����������ã������������pData�޸�
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
//ð������,������������
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
		//ע���������½�
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
//�Ľ���ð�����������������򣬱Ƚ�n-1�Σ����轻���������������򣬱Ƚ�n*(n-1)/2���ƶ���������,O(n^2)
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
//��ѡ������:O(n^2),�ŵ����ڽ����ƶ�����Ƚ��٣������Ƚϴ���һ����n(n-1)/2���������0���n-1;
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
//ֱ�Ӳ��룺��һ����¼���뵽�Ѿ��ź�����������,ֻ��Ҫһ����¼�ĸ����ռ䣬˳��Ƚ�n-1�Σ�����Ҫ�ƶ�������Ƚϣ�n+2��(n-1)/2�Σ��ƶ���n+4��(n-1)/2��
//ƽ���Ƚ��ƶ�����n^2/4�Σ�ʱ�临�Ӷ�O(n^2)������������ð�ݺͼ�ѡ������
void insertsort(vector<int>& Data)
{
	cout << "Now we use selectsort." << endl;
	cout << "the original data is:";
	print(Data);
	int length = Data.size();

	if (!length)
		return;
	//ע��i,j���Զ�����ѭ����������������
	int guard, i, j;

	for (i = 1; i < length; i++)
	{
		if (Data[i] < Data[i - 1])
		{
			guard = Data[i];
			for (j = i - 1; j >= 0 && Data[j] > guard; j--) //ע��j>=0����������,����{2,5,6,1}�ᷢ������Խ��,&&��·���㣬j>=0Ҫд��ǰ��
			{
				Data[j + 1] = Data[j];
			}
			Data[j + 1] = guard;
		}
	}
	cout << "the result is:";
	print(Data);
}
//ϣ�����򣺻���������Ǿֲ�����ʱ�临�Ӷ�O(n^3/2),���ȶ�,���ڲ������������
//incremental���ȡ��û�н����⣬���о����
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
������ȫ������[log2n]+1���ԣ����ڶ������ԭʼ��¼������״̬�������У� �������������á� ���ƽ��ʱ�临�ӶȾ�ΪO(nlogn)�� ������������ȻҪԶԶ�ù���ð�ݡ� ��ѡ�� ֱ�Ӳ����O(n^2)��ʱ�临�Ӷ��ˡ�
�ռ临�Ӷ��ϣ���ֻ��һ�������������ݴ浥Ԫ�� Ҳ�ǳ��Ĳ��� �������ڼ�¼ �ıȽ��뽻������Ծʽ���У� ��˶�����Ҳ��һ�ֲ��ȶ������򷽷���
���⣬ ���ڳ�ʼ����������ıȽϴ����϶࣬��ˣ� �������ʺϴ��������и������ٵ������ */
void HeapAdjust(vector<int>&Data, int s, int length)
{
	int temp, j;
	temp = Data[s];//��ȡ����ǰԪ��s
	for (j = 2 * s + 1; j < length; j = j * 2 + 1) /* ��s������ӽ�㿪ʼ��Ҳ����2*s+1�� */
	{
		if (1 + j < length && Data[j] < Data[j + 1])//j+1<length,��Ϊ���ӽ����ڡ�������ӽ��С�����ӽ�㣬jָ�����ӽ��
		{
			j++;
		}
		if (Data[j] > temp)//����ӽڵ���ڸ��ڵ㣬���ӽڵ�ֵ�������ڵ㣨���ý��н�����
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
	for (i = length / 2 - 1; i >= 0; i--) /*  j���ĸ��ڵ�Ϊ[j/2]�����±��0��ʼ������Ҫ��ȥ1����Data������һ������� */
		HeapAdjust(Data, i, length);

	for (i = length - 1; i > 0; i--)
	{
		swap(Data, 0, i); /* ���Ѷ���¼�͵�ǰδ�����������е����һ����¼���� */
		HeapAdjust(Data, 0, i); /*  ��Data[0..i-1]���µ���Ϊ����� */
	}
	cout << "the result is:";
	print(Data);
}

//�ǵݹ�ʵ�ֹ鲢���򣬱Ƚ�ռ���ڴ棬Ч�ʸߣ��ȶ�����á����ƽ��ʱ������O(nlogn);�ռ临�Ӷ�O(n)
void Merge(vector<int>& c, vector<int>& d, int left, int middle, int right)
{
    // �ϲ�c[left:middle]��c[middle+1:right]��d[1eft:right]
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
    // �ϲ���СΪs����������
    int i = 0;
    while (i <= length-2*gap) {
        // �ϲ���СΪs������2��������
        Merge(x, y, i, i + gap - 1, i + 2 * gap  - 1);
        i = i + 2 * gap;
    }
    // ʣ�µ�Ԫ������2s
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
        MergePass(Data, temp, gap, length);      // �ϲ�������temp
        gap += gap;
        MergePass(temp, Data, gap, length);      // �ϲ�������Data
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

//��������,ʱ�临�Ӷ�O��nlogn�����ռ临�Ӷ�O(logn),���ȶ���ð����������
void quicksort(vector<int>& Data)
{
	cout << "Now we use heapsort." << endl;
	cout << "the original data is:";
	print(Data);
	int length = Data.size();

	if (!length)
		return;


	cout << "the result is:";
	print(Data);
}
int main()
{
	vector<int> Data = { 9,7,8,6,10,4,5,3,2};
	vector<int> p1, p2, p3, p4, p5, p6, p7,p8,p9;
	p1 = p2 = p3 = p4 = p5 = p6 = p7 = p8=p9=Data;
	time_t c_start, c_end;


	c_start = clock();
	bubbleSort0(p1);
	c_end = clock();
	cout << "��ǰ�����㷨����ʱ��Ϊ��" << difftime(c_end, c_start) << "ms" << endl << endl;

	c_start = clock();
	bubbleSort(p2);
	c_end = clock();
	cout << "��ǰ�����㷨����ʱ��Ϊ��" << difftime(c_end, c_start) << "ms" << endl << endl;

	c_start = clock();
	bubbleSort2(p3);
	c_end = clock();
	cout << "��ǰ�����㷨����ʱ��Ϊ��" << difftime(c_end, c_start) << "ms" << endl << endl;

	c_start = clock();
	selectsort(p4);
	c_end = clock();
	cout << "��ǰ�����㷨����ʱ��Ϊ��" << difftime(c_end, c_start) << "ms" << endl << endl;

	c_start = clock();
	insertsort(p5);
	c_end = clock();
	cout << "��ǰ�����㷨����ʱ��Ϊ��" << difftime(c_end, c_start) << "ms" << endl << endl;

	c_start = clock();
	shellsort(p6);
	c_end = clock();
	cout << "��ǰ�����㷨����ʱ��Ϊ��" << difftime(c_end, c_start) << "ms" << endl << endl;

	c_start = clock();
	heapsort(p7);
	c_end = clock();
	cout << "��ǰ�����㷨����ʱ��Ϊ��" << difftime(c_end, c_start) << "ms" << endl << endl;

	c_start = clock();
    Mergesort_interface(p8);
	c_end = clock();
	cout << "��ǰ�����㷨����ʱ��Ϊ��" << difftime(c_end, c_start) << "ms" << endl << endl;

	c_start = clock();
	quicksort(p9);
	c_end = clock();
	cout << "��ǰ�����㷨����ʱ��Ϊ��" << difftime(c_end, c_start) << "ms" << endl << endl;


	return 0;
}
