// from server: 100% by atomic.potato
extern "C" void target(void *);

struct S
{
    void f();
};

void S::f()
{
    target((char *)this + 0x18c);
}
