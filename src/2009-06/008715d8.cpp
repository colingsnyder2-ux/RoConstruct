// from server: 78% by atomic.potato
extern "C" void __stdcall Function719B76(void *, int, int, const char *);

struct S
{
    int value;
    void f();
};

void S::f()
{
    Function719B76((char *)this + 0x1a0, 0x0c, 2, "QSUVW");
}
