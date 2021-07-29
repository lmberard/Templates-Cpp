
/*Ordenamiento por Selección:*/

template<class T>
void swap (T& e1, T& e2) 
{
T tmp = e1; e1 = e2; e2 = tmp;
}

template<class T>
void selectionsort(T data[], const int n) {
    for (int i = 0, least, j; i < n-1; i++) {
        for (j = i+1, least = i; j < n; j++)
            if (data[j] < data[least])
                least = j;
        swap(data[least],data[i]);
    }
}

/*Ordenamiento por burbujeo*/

template<class T>
void swap (T& e1, T& e2) 
{
T tmp = e1; e1 = e2; e2 = tmp;
}

template<class T>
void bubblesort(T data[], const int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = n-1; j > i; --j)
            if (data[j] < data[j-1])
                swap(data[j],data[j-1]);
}

/*Ordenamiento por inserción*/
template<class T>
void swap (T& e1, T& e2) 
{
T tmp = e1; e1 = e2; e2 = tmp;
}

template<class T>
void insertionsort(T data[], const int n) {
    for (int i = 1, j; i < n; i++) {
        T tmp = data[i];
        for (j = i; j > 0 && tmp < data[j-1]; j--)
            data[j] = data[j-1];
        data[j] = tmp;
    }
}

//Ordenamiento Shell

template<class T>
void swap (T& e1, T& e2) 
{T tmp = e1; e1 = e2; e2 = tmp;
}

template<class T>
void Shellsort(T data[], const int n) {
    register int i, j, hCnt, h;
    int increments[20], k;
//  create an appropriate number of increments h
    for (h = 1, i = 0; h < n; i++) {
        increments[i] = h;
        h = 3*h + 1;
    }
 // loop on the number of different increments h
    for (i--; i >= 0; i--) {
        h = increments[i];
     // loop on the number of subarrays h-sorted in ith pass
        for (hCnt = h; hCnt < 2*h; hCnt++) {
         // insertion sort for subarray containing every hth element of array data
            for (j = hCnt; j < n; ) {
                T tmp = data[j];
                k = j;
                while (k-h >= 0 && tmp < data[k-h]) {
                    data[k] = data[k-h];
                    k -= h;
                }
                data[k] = tmp;
                j += h;
            }}}}

/*Ordenamiento por Mezcla*/

template<class T>
void swap (T& e1, T& e2) 
{
T tmp = e1; e1 = e2; e2 = tmp;
}


template<class T>
void merge(T array1[], T temp[], int first, int last) {
    int mid = (first + last) / 2;
    int i1 = 0, i2 = first, i3 = mid + 1;
    while (i2 <= mid && i3 <= last)
        if (array1[i2] < array1[i3])
             temp[i1++] = array1[i2++];
        else temp[i1++] = array1[i3++];
    while (i2 <= mid)
        temp[i1++] = array1[i2++];
    while (i3 <= last)
        temp[i1++] = array1[i3++];
    for (i1 = 0, i2 = first; i2 <= last; array1[i2++] = temp[i1++]);
}

template<class T>
void mergesort(T data[], T temp[], int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergesort(data, temp, first, mid);
        mergesort(data, temp, mid+1, last);
        merge(data, temp, first, last);
    }
}

/*Ordenamiento Rápido*/

template<class T>
void swap (T& e1, T& e2) 
{
T tmp = e1; e1 = e2; e2 = tmp;
}

template<class T>
void quicksort(T data[], int first, int last) {
    int lower = first+1, upper = last;
    swap(data[first],data[(first+last)/2]);
    T bound = data[first];
    while (lower <= upper) {
        while (data[lower] < bound)
             lower++;
        while (bound < data[upper])
             upper--;
        if (lower < upper)
             swap(data[lower++],data[upper--]);
        else lower++;
    }
    swap(data[upper],data[first]);
    if (first < upper-1)
        quicksort (data,first,upper-1);
    if (upper+1 < last)
        quicksort (data,upper+1,last);
}


/*Otra versión*/

template<class T>
void quicksort2(T data[], int first, int last) 
{
    if (last - first < 30)
         insertionsort(data,first,last);
    else {
         int lower = first+1, upper = last;
         swap(data[first],data[(first+last)/2]);
         T bound = data[first];
         while (lower <= upper) {
             while (data[lower] < bound)
                 lower++;
             while (bound < data[upper])
                 upper--;
             if (lower < upper)
                 swap(data[lower++],data[upper--]);
             else lower++;
         }
         swap(data[upper],data[first]);
         if (first < upper-1)
             quicksort2(data,first,upper-1);
         if (upper+1 < last)
             quicksort2(data,upper+1,last);
    }
}

/*Ordenamiento por montículo*/

template<class T>
void swap (T& e1, T& e2) 
{
T tmp = e1; e1 = e2; e2 = tmp;
}

template<class T>
void moveDown (T data[], int first, int last) {
    int largest = 2*first + 1;
    while (largest <= last) {
        if (largest < last && // first has two children (at 2*first+1 and
            data[largest] < data[largest+1]) // 2*first+2) and the second
             largest++;                      // is larger than the first;

        if (data[first] < data[largest]) {   // if necessary,
             swap(data[first],data[largest]);// swap child and parent,
             first = largest;                // and move down;
             largest = 2*first+1;
        }
        else largest = last+1;  // to exit the loop: the heap property
    }                           // isn't violated by data[first];
}

template<class T>
void heapsort(T data[], const int n) {
    int i;
    for (i = n/2 - 1; i >= 0; --i) // create the heap;
        moveDown (data,i,n-1);
    for (i = n-1; i >= 1; --i) {
        swap(data[0],data[i]);     // move the largest item to data[i];
        moveDown(data,0,i-1);      // restore the heap property;
    }
}
