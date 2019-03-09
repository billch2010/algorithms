/*
  堆排序：建堆，调整堆，存储结构为顺序数组，逻辑结构可看作完全二叉树
  时间复杂度O(nlgn)
  空间复杂度O(1)
*/

// 递增序，构建大顶堆，与堆尾交换后调整
void heapSort(vector<int>& array) {
    buildHeap(array);
    for (int i = array.size() - 1; i > 0; --i) {
        swap(array[0], array[i]);
        adjustHeap(array, 0, i - 1);
    }
}

void buildHeap(vector<int>& array) {
    int len = array.size();
    for (int k = len/2 - 1; k >= 0; --k) {
        adjust(array, k, len - 1);
    }
}

// param: @end 数组最后的有效下标
// 与较大值的子节点交换
void adjustHeap(vector<int>& array, int start, int end) {
    while (true) {
        int child = start * 2 + 1;  
        // choose the bigger child
        if (child + 1 <= end && array[child+1] > array[child]) {
            ++child;
        } 
        if (array[child] > array[start]) {
            swap(array[child], array[start]);
            start = child;
        } else  break;
    }
}
