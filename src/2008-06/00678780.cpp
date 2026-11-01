// from server: 100% by king_originala
extern void __cdecl push_heap(float*, int, int, float);

#pragma float_control(precise, off, push)

void __cdecl adjust_heap(float* first, int hole, int length, float value)
{
    int top = hole;
    int child = 2 * hole + 2;

    while (child < length)
    {
        if (first[child] < first[child - 1])
            --child;
        first[hole] = first[child];
        hole = child;
        child = 2 * child + 2;
    }

    if (child == length)
    {
        first[hole] = first[length - 1];
        hole = length - 1;
    }

    push_heap(first, hole, top, value);
}

#pragma float_control(pop)
