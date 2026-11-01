// from server: 100% by king_originala
extern void __cdecl adjust_heap(float* first, int parent, int count, float value);

void __cdecl make_heap(float* first, float* last)
{
    int count = last - first;
    int parent = count / 2;
    while (parent > 0)
    {
        --parent;
        adjust_heap(first, parent, count, first[parent]);
    }
}
