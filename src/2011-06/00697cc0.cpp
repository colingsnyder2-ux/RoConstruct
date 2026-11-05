// from server: 38% by atomic.potato
struct S
{
    int f(int, int, int);
};

extern "C" void call_target(void *, int, int, int);

int S::f(int a, int b, int c)
{
    call_target((char *)this + 16, a, b, c);
    return 0;
}
