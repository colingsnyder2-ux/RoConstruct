// from server: 52% by atomic.potato
struct S
{
    int f();
};

extern "C" int target(S *);

int S::f()
{
    return target((S *)((char *)this - 240));
}
