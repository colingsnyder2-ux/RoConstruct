// from server: 60% by atomic.potato
typedef void (__thiscall *Fn)(void *);

struct S
{
    int value0;
    int value1;
    int value2;
    int value3;
    int value4;
    int value5;
    void f();
};

void S::f()
{
    value0 = (int)0x00b98f84;
    value5 = (int)0x00b98f7c;
    value5 = (int)0x00b43e60;

    void *p = *(void **)((char *)this + 0x18);
    if (p)
    {
        void **vtable = *(void ***)p;
        Fn fn = (Fn)vtable[4];
        fn(p);
    }

    ((void (__thiscall *)(S *))0x00b229d8)(this);
}
