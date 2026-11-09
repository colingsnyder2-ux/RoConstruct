// from server: 68% by atomic.potato
extern "C" void __stdcall construct_string(void *, const char *);

struct S
{
    int f(int);
};

int S::f(int value)
{
    construct_string(&value, "ExclusiveArbiter");
    return (int)this;
}
