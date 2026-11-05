// from server: 72% by atomic.potato
extern "C" void __cdecl CallA(void *);
extern "C" void __cdecl CallB(void *);

struct S {
    void f();
};

void S::f()
{
    struct T {
        void *value;
    };

    T *p = *(T **)((char *)this + 4);
    void **q = (void **)((char *)p + 0x20);
    void *value = *q;

    if (value) {
        CallA(value);
        CallB(value);
        *q = 0;
    }
}
