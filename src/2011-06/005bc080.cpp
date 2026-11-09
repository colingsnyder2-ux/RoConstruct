// from server: 60% by atomic.potato
struct Inner_005bc080 {
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, void*);
};

struct Outer_005bc080 {
    char pad[0x1c];
    Inner_005bc080* p;
    void* method(int, int);
};

extern "C" void __cdecl sub_00652040(void*, void*);

void* Outer_005bc080::method(int a, int b)
{
    void* local = 0;
    Inner_005bc080* q = p;
    q->f2(&local, &a);
    sub_00652040(&local, &b);

    return this;
}
