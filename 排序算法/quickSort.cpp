/* 
快速排序
算法思想：patition找基准二分，递归；
【时间复杂度】最好/平均 O(nlgn)，最坏情况数组有序时，类似退化为冒泡排序O(n^2)
【空间复杂度】额外空间辅助O(lgn)，最坏情况O(n)；（递归时pivot值）
实现方法：a)左右指针填充法，填充到基准的位置； 
        b)左右指针交换法，前后哨兵指针交换； 
        c)前后双指针传递法，双指针同向移动，先动的cur指针与后动prev指针内容交换。
优化方向：a) 基准的选取，避免顺序情况最坏时间复杂度，可随机选取基准的下标 或 三数取中； 
        b) 分割到一定大小后直接用插入排序； 
        c) 一次分割后尽量将与pivot相等的聚在一起；
运用拓展： top-k问题(patition思想或堆排序思想)；查找数组中数量超过一半的值；
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
