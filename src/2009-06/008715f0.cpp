// from server: 65% by atomic.potato
extern "C" void __cdecl Function719B76(void *, int, int, const char *);

struct S
{
    int value;
    void f();
};

void S::f()
{
    Function719B76((char *)this + 0x1b8, 0x0c, 2, "QSUVW");
}
