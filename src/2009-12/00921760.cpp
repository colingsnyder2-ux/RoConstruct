// from server: 29% by atomic.potato
extern "C" void __stdcall sym(void *);

struct S
{
    void f(int);
};

void S::f(int value)
{
    sym((void *)value);
}
