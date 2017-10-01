//선택정렬
void selectionSort(int list[], int n)
{
    int i, j, least, temp;
    for (i = 0; i<n - 1; i++) {
        least = i;
        for (j = i + 1; j<n; j++)
            if (list[j]<list[least]) least = j;
        SWAP(list[i], list[least], temp);
    }
}

//삽입정렬
void insertionSort(int list[], int n)
{
    int i, j, key;
    for (i = 1; i<n; i++){
        key = list[i];
        for (j = i - 1; j >= 0 && list[j]>key; j--)
            list[j + 1] = list[j];
        list[j + 1] = key;
    }
}

//버블정렬
void bubbleSort(int list[], int n)
{
    int i, j, temp;
    for (i = n - 1; i>0; i--){
        for (j = 0; j<i; j++)
            if (list[j]>list[j + 1])
                SWAP(list[j], list[j + 1], temp);
    }
}

//셀정렬
void incInsertionSort(int list[], int first, int last, int gap)
{
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap){
        key = list[i];
        for (j = i - gap; j >= first && key<list[j]; j = j - gap)
            list[j + gap] = list[j];
        list[j + gap] = key;
    }
}

void shellSort(int list[], int n)
{
    int i=0, gap;
    for (gap = n / 2; gap>0; gap = gap / 2) {
        if ((gap % 2) == 0) gap++;
        for (i = 0; i<gap; i++)
            incInsertionSort(list, i, n - 1, gap);
    }
}

//합병정렬
void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l=0;
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right){
        if (list[i] <= list[j]) sorted[k++] = list[i++];
        else sorted[k++] = list[j++];
    }
    if (i>mid)
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    else
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];

    for (l = left; l <= right; l++)
        list[l] = sorted[l];
}
void mergeSort(int list[], int left, int right)
{
    int mid;
    if (left<right) {
        mid = (left + right) / 2;
        mergeSort(list, left, mid);
        mergeSort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

//퀵정렬
void quickSort(int numbers[], int array_size)
{
    q_sort(numbers, 0, array_size -1);
}

void q_sort(int numbers[], int left, int right)
{
    int pivot, l_hold, r_hold;
    l_hold = left;
    r_hold = right;
    pivot = numbers[left]; // 0번째 원소를 피봇으로 선택
    while (left < right)
    {
        // 값이 선택한 피봇과 같거나 크다면, 이동할 필요가 없다
        while ((numbers[right] >= pivot) && (left < right))
            right --;

        // 그렇지 않고 값이 피봇보다 작다면,
        // 피봇의 위치에 현재 값을 넣는다.
        if (left != right)
        {
            numbers[left] = numbers[right];
        }
        // 왼쪽부터 현재 위치까지 값을 읽어들이면서
        // 피봇보다 큰 값이 있다면, 값을 이동한다.
        while ((numbers[left] <= pivot) && (left < right))
            left ++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right --;
        }
    }
    // 모든 스캔이 끝났다면, 피봇값을 현재 위치에 입력한다.
    // 이제 피봇을 기준으로 왼쪽에는 피봇보다 작거나 같은 값만 남았다.
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;

    // 재귀호출을 수행한다.
    if (left < pivot)
        q_sort(numbers, left, pivot - 1);
    if (right > pivot)
        q_sort(numbers, pivot+1, right);
}

void createList(void)
{

    for (int i = 0; i<MAX_SIZE; i++)
        firstList[i] = rand();
}

void copyList(void){
    for (int i = 0; i<MAX_SIZE; i++) {
        list[i] = firstList[i];
    }
}

int main(void)
{
    clock_t start=0, finish=0, used_time = 0;

    createList();
    copyList();

    //선택정렬
    start = clock();
    selectionSort(list, MAX_SIZE);
    finish = clock();
    used_time = finish - start;
    printf("선택정렬 : %fsec\n", (float)used_time / CLOCKS_PER_SEC);

    copyList();

    //삽입정렬
    start = clock();
    insertionSort(list, MAX_SIZE);
    finish = clock();
    used_time = finish - start;
    printf("삽입정렬 : %fsec\n", (float)used_time / CLOCKS_PER_SEC);

    copyList();

    //버블정렬
    start = clock();
    bubbleSort(list, MAX_SIZE);
    finish = clock();
    used_time = finish - start;
    printf("버블정렬 : %fsec\n", (float)used_time / CLOCKS_PER_SEC);

    copyList();

    //셸정렬
    start = clock();
    shellSort(list, MAX_SIZE);
    finish = clock();
    used_time = finish - start;
    printf("셸정렬 : %fsec\n", (float)used_time / CLOCKS_PER_SEC);

    copyList();

    //합병정렬
    start = clock();
    mergeSort(list, 0, MAX_SIZE);
    finish = clock();
    used_time = finish - start;
    printf("합병정렬 : %fsec\n", (float)used_time / CLOCKS_PER_SEC);

    copyList();

    //퀵정렬
    start = clock();
    quickSort(list, MAX_SIZE);
    finish = clock();
    used_time = finish - start;
    printf("퀵정렬 : %fsec\n", (float)used_time / CLOCKS_PER_SEC);
}