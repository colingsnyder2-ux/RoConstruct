// from server: 91% by colin
struct S_func_0041cf10 {
    bool f(void*);
};

struct S_other {
    virtual bool v0();
    virtual bool v1();
    virtual bool v2();
    virtual bool v3();
    virtual bool v4();
};

extern "C" bool __stdcall G1_func_0053e2c0(void*, void*);

bool S_func_0041cf10::f(void* a)
{
    if (G1_func_0053e2c0(a, this))
        return false;
    if (*(void**)((char*)a + 0xbc) == this)
        return false;
    if (((S_other*)this)->v3())
        return true;
    return ((S_other*)a)->v4();
}
