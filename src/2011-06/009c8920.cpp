// from server: 23% by atomic.potato
struct S
{
    int v0;
    int v1;
    int v2;
    int v3;

    void f();
};

void S::f()
{
    struct T
    {
        int (*fn)(int);
    };

    T* p = (T*)v3;
    p->fn(v3);
}
