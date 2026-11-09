// from server: 76% by atomic.potato
extern "C" void* __cdecl sub_983448(void*, void*, void*, int, int);
extern "C" void* __cdecl sub_47d2a0(void*);
extern "C" void* __cdecl sub_6fb630(void*);

extern "C" char g_d6e21c[];
extern "C" char g_d6e310[];

struct S {
    void* f(int);
};

void* S::f(int)
{
    void* p = sub_983448(this, g_d6e21c, g_d6e310, 0, 0);
    if (p == 0)
        return 0;
    void* q = sub_47d2a0(p);
    if (q == 0)
        return 0;
    return sub_6fb630(q);
}
