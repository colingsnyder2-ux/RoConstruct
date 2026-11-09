// from server: 70% by atomic.potato
struct S
{
    int f(int);
    void* g(void*);
};

struct T : S
{
    int f(int);
};

int T::f(int value)
{
    void* x = g((char*)value + 4);
    int y = *(int*)x;
    return S::f(y);
}
