// from server: 81% by atomic.potato
extern "C" int __stdcall sub_00926430(void *, void *);

struct S_func_008b3a90 {
    char pad0[96];
    void *m_field60;
    int f(void *);
};

int S_func_008b3a90::f(void *arg)
{
    void *value = (void *)sub_00926430(this, arg);
    if (value != 0 && m_field60 != 0) {
        void *p = *(void **)((char *)m_field60 + 0xd4);
        void **vtable = *(void ***)p;
        typedef void (__thiscall *Func)(void *, void *);
        ((Func)((char *)vtable + 0x7c))(p, value);
    }
    return 1;
}
