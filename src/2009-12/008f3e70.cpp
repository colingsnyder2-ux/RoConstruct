// from server: 59% by atomic.potato
struct S
{
    void f();
    int *a;
};

void S::f()
{
    struct V
    {
        void (*g)(int *);
    };

    V *v = *(V **)a;
    v->g(a);
}
