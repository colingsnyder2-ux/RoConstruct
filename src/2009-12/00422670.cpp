// from server: 43% by atomic.potato
struct CRobloxTreeCtrlNode
{
    void f(int flags);
};

extern "C" void __stdcall sub_66FF30(void *);
extern "C" void __stdcall sub_66AA30(void *);

void CRobloxTreeCtrlNode::f(int flags)
{
    if ((flags & 2) && *(char *)((char *)this + 0x5d) == 0)
    {
        void *p = *(void **)((char *)this + 0x60);
        void **vt = *(void ***)p;
        void (__stdcall *fn)(void *, int, void *) = (void (__stdcall *)(void *, int, void *))vt[0x154 / 4];
        void *tmp;
        fn(p, 1, &tmp);
        sub_66FF30(&tmp);
        *(int *)((char *)this + 0x0) = 0;
        ((void (__thiscall *)(void *))0x421300)(this);
        ((void (__thiscall *)(void *))0x4215B0)(this);
        sub_66AA30(&tmp);
    }
}
