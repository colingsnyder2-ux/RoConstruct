// from server: 68% by atomic.potato
struct S_func_00712460 {
    char pad0[36];
    int m_value;
    int f();
};

struct S_func_007b2f40 {
    char pad0[4];
    int m_value;
    void removeFromStage(void*);
};

struct S_func_007bb800 {
    void f(void*);
};

struct SpatialFilter {
    char pad0[8];
    S_func_007bb800* m_p8;
    void func(S_func_00712460*);
};

void SpatialFilter::func(S_func_00712460* p)
{
    int i = p->f();
    m_p8->f((void*)i);
    int n = *(int*)((char*)i + 0x18);
    int j = 0;
    while (j < n)
    {
        int* arr = *(int**)((char*)i + 0x14);
        int v = arr[j];
        if (v != 0)
            v -= 8;
        else
            v = 0;
        m_p8->f((void*)v);
        j++;
    }
    ((S_func_007b2f40*)this)->removeFromStage((void*)this);
}
