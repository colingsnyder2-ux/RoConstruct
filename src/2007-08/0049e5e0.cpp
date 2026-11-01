// from server: 100% by colin
struct S_0049de60 {
    int m();
};

extern "C" void* __cdecl func_00486830(void*);

bool __cdecl func_0049e5e0(void* a)
{
    void* p = func_00486830(a);
    int r;
    if (p != 0) {
        r = ((S_0049de60*)p)->m();
    } else {
        r = 0;
    }
    return r != 0;
}
