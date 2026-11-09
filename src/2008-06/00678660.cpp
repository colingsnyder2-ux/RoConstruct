// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
void __cdecl pushHeap(float* data, int hole, int top, float value)
{
    int parent = (hole - 1) / 2;
    while (top < hole && data[parent] < value)
    {
        data[hole] = data[parent];
        hole = parent;
        parent = (hole - 1) / 2;
    }
    data[hole] = value;
}
