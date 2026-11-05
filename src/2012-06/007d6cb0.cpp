// from server: 46% by atomic.potato
struct S
{
    void f(void *);
};

void S::f(void *a)
{
    struct V
    {
        void *x;
        void *y;
        void *z;
    };

    V v;
    v.x = a;
    v.y = ((void **)this)[5];
    v.z = ((void **)this)[6];
    ((S *)((char *)this + 16))->f(&v);
}
