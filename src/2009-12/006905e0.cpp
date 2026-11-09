// from server: 62% by atomic.potato
struct S
{
    int f();
};

extern "C" int target(S *, int);

int S::f()
{
    return target(this, 0x130);
}
