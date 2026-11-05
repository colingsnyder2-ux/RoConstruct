// from server: 40% by atomic.potato
struct S
{
    void f();
};

extern "C" void func_004d62e0(void *);

void S::f()
{
    func_004d62e0((void *)0x00b7dc40);
}
