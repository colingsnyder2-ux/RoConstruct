// from server: 57% by atomic.potato
struct S
{
    void __cdecl f(void*, int, int);
};

void S::f(void* p, int, int axis)
{
    if (axis != 4)
        return;
    *(int*)p = 0xdf5c88;
    ((char*)p)[4] = 0;
    ((char*)p)[5] = 0;
}
