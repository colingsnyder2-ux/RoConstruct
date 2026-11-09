// from server: 67% by atomic.potato
struct S
{
    void f(void*, void*);
};

struct T
{
    void sub_8444f0();
    void sub_8080b0(void*, void*);
};

void S::f(void* a, void* b)
{
    ((T*)this)->sub_8444f0();
    ((T*)this)->sub_8080b0(b, a);
}
