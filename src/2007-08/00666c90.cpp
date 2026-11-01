// from server: 100% by colin
struct CXTTreeBase
{
    int f(int a, int b, int c);
};

extern "C" int __stdcall sub_68F840(int, int*);

int CXTTreeBase::f(int a, int b, int c)
{
    int* pOut1 = (int*)c;
    int* pOut2 = (int*)b;
    unsigned int key = (unsigned int)a >> 4;
    *pOut1 = key;
    unsigned int idx = key % *(unsigned int*)((char*)this + 8);
    *pOut2 = idx;
    int* table = *(int**)((char*)this + 4);
    if (table == 0)
        return 0;
    int node = table[idx];
    while (node != 0)
    {
        if (*(int*)(node + 0x4c) == *pOut1)
        {
            int tmp;
            if (sub_68F840(node, &tmp) != 0)
                return node;
        }
        node = *(int*)(node + 0x48);
    }
    return 0;
}
