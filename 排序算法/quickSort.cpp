/* 快速排序
有三种实现方法：左右指针填充法，左右指针交换法，前后指针交换法
平均时间复杂度 O(nlgn)，最坏O(n^2)【数组顺序时】
空间复杂度O(lgn),每个递归需要返回一个值
*/

void quickSort(vector<int>& array){
    quickSort(array, 0, array.size() - 1);
}

void quickSort(vector<int>& array, int low, int high){
    if (low >= high) return;
    int pivot = patition(array, low, high);
    quickSort(array, 0, pivot - 1);
    quickSort(array, pivot + 1, high);
}

int patition(vector<int>& array, int low, int high){
    int pivot = array[low];
    // 左右指针填充法/挖坑法 
    while (low < high) {
        while (low < high && array[high] > pivot) --high;
        if (low < high) array[low] = array[high];
        while (low < high && array[low] <= pivot) ++low
        if (low < high) array[high] = array[low];        
    }
    array[low] = pivot;
    return low;
    
    // 左右指针交换法
    int start = low;
    while (low < high) {
        while (low < high && array[high] > pivot) --high;
        while (low < high && array[low] <= pivot) ++low
        if (low < high) swap(array[high], array[low]);        
    }
    array[start] = array[low];
    array[low] = pivot;   
    return low;        
        
    // 前后指针交换法
    int slow = low, fast = low + 1;
    while (fast <= high) {
        if (array[fast] <= pivot && fast != ++slow) {
            swap(array[slow], array[fast]);
        }
        ++fast;
    }
    array[low] = array[slow];
    array[slow] = pivot;   
    return slow;   
}
