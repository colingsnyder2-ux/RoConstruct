// from server: 100% by atomic.potato
typedef void (*Continuation)();

struct S
{
    void f();
};

void Continue();

void S::f()
{
    *(unsigned long *)this = 0x00aa8f34UL;
    *(unsigned long *)((char *)this + 4) = 0x00aa8f28UL;
    *(unsigned long *)((char *)this + 0x18) = 0x00aa8f1cUL;
    *(unsigned long *)((char *)this + 0x1c) = 0x00aa8f10UL;
    *(unsigned long *)((char *)this + 0x90) = 0x00aa8f08UL;
    Continue();
}
