// from server: 9% by atomic.potato
struct GfxAttachement {
    void __cdecl f(int a, int b, int c, int d, int e, int f2);
};

struct Helper {
    void sub_919330(int*, int*);
};

extern "C" void __stdcall sub_401a30(void*);

void GfxAttachement::f(int a, int b, int c, int d, int e, int f2)
{
    int* p1 = &c;
    int* p2 = &d;
    ((Helper*)a)->sub_919330(p1, p2);
    if (*(void**)&d) sub_401a30(*(void**)&d);
    if (*(void**)&e) sub_401a30(*(void**)&e);
}
