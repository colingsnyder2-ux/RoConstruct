// from server: 74% by atomic.potato
struct S
{
    int f();
};

struct V
{
    int pad[72];
    int (*call)(V *);
};

int S::f()
{
    V *p = *(V **)((char *)this + 12);
    int (*fn)(V *) = p->call;
    int x = fn((V *)((char *)p + 288));
    return *((int *)((char *)x + 324)) == 4;
}
