// from server: 62% by atomic.potato
struct S
{
    char pad[228];
    int field;
    char pad2[4];
    void f(int *p);
};

void S::f(int *p)
{
    field = *p;
}
