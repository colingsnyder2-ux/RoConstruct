// from server: 76% by atomic.potato
struct S
{
    int holder[2];
    int collector[2];
    void f();
};

extern "C" void callee_005395b0(void *);
extern "C" int callee_00695fb0(S *);
extern "C" void callee_006974e0(void *, void *);

void S::f()
{
    callee_005395b0((char *)this + 0x1bc);
    int value = callee_00695fb0(this);
    callee_006974e0((char *)this + 0x1b4, (void *)value);
}
