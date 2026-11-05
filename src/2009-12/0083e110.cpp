// from server: 64% by atomic.potato
struct CXTPCustomizeSheet
{
    int f(int);
};

int CXTPCustomizeSheet::f(int value)
{
    int* p = *(int**)((char*)this + 0xb8);
    p = *(int**)((char*)p + 0x58);
    if (p != 0)
    {
        int* q = *(int**)((char*)value);
        int flag = (*(int**)((char*)p + 0x90) > 0) ? 1 : 0;
        return ((int (__thiscall *)(int*, int))q[0])(q, flag);
    }
    return 0;
}
