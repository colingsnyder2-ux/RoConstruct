// from server: 46% by atomic.potato
extern "C" void __cdecl sub_6d2ca0(int*, int*, int*, int*);

void __cdecl sub_6d4290(int* first, int* last, int* result)
{
    int count = (int)(last - first);
    if (count > 0x28)
    {
        int n = count + 1;
        int q = n / 8;
        int step = q * 8;
        int half = q * 4;
        sub_6d2ca0(first, first + half, first + step, result);
        sub_6d2ca0(first + half, first + step, first + step + half, result);
        sub_6d2ca0(first + step, first + step + half, first + step + step, result);
        sub_6d2ca0(first + step + half, first + step + step, last, result);
    }
    else
    {
        sub_6d2ca0(first, last, result, result);
    }
}
