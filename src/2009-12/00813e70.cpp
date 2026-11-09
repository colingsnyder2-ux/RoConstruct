// from server: 95% by atomic.potato
extern "C" void __stdcall sub_98DE5C(void *, void *);

struct S {
    virtual void v();
    void f(void *);
};

void S::f(void *p)
{
    sub_98DE5C((char *)this + 0xF4, p);
    ((void (__thiscall *)(S *, int, int))(*(void **)((char *)*(void **)this + 0x1AC)))(this, 0, 1);
}
