// from server: 68% by atomic.potato
struct S_func_00692f80 {
    char pad0[8];
    int m_offset;
    int f(int a, int b);
};

extern "C" void __stdcall sub_a404c8(void*, const void*);

int S_func_00692f80::f(int a, int b)
{
    int tmp = 0;
    int* p = (int*)a;
    if (p != 0)
        p = (int*)((char*)p - 0x1c);
    else
        p = 0;
    int* src = (int*)((char*)this + m_offset + (int)p);
    sub_a404c8((void*)b, (const void*)src);
    *(int*)((char*)b + 0x1c) = *(int*)((char*)src + 0x1c);
    return b;
}
