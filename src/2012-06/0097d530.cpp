// from server: 39% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int __stdcall call_target(int, int);

int S::f(int x)
{
    call_target(*(int*)this, x);
    return 0;
}
