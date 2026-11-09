// from server: 42% by atomic.potato
struct S
{
    void f(void *);
};

void S::f(void *p)
{
    void *args[2];
    args[0] = p;
    args[1] = 0;
    ((S *)((char *)this + 4))->f(args);
}
