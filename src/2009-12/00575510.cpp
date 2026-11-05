// from server: 11% by atomic.potato
struct S
{
    void f();
    char pad[8];
};

struct T
{
    int pad;

    void f();
};

void T::f()
{
}

void S::f()
{
    ((T*)*(void**)((char*)this + 4) + 1)->f();
}
