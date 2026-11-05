// from server: 86% by atomic.potato
struct P_751CD0
{
    void f(float, float, void*, void*);
};

struct S_func_00695730
{
    void f(void*);
};

void S_func_00695730::f(void* p)
{
    P_751CD0* q = *(P_751CD0**)((char*)this - 4);
    q->f(*(float*)((char*)p + 0x18), *(float*)((char*)p + 0x1c),
         (char*)p + 0x0c, p);
}
