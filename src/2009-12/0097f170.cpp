// from server: 38% by atomic.potato
struct S
{
    int f();
};

extern "C" void callee(void*);

int S::f()
{
    callee((void*)0x00b7dc50);
    return 0;
}
