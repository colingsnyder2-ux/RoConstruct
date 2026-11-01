// from server: 100% by king_originala
extern void __cdecl median3(int*, int*, int*);

void __cdecl sampleMedian(int* first, int* middle, int* last)
{
    int count = last - first;
    if (count > 40)
    {
        int step = (count + 1) / 8;
        median3(first, first + step, first + 2 * step);
        median3(middle - step, middle, middle + step);
        median3(last - 2 * step, last - step, last);
        median3(first + step, middle, last - step);
    }
    else
    {
        median3(first, middle, last);
    }
}
