// from server: 100% by atomic.potato
extern "C" void __stdcall finish();

struct S
{
    void f();
};

void S::f()
{
    *(int *)this = 0x9d9914;
    *(int *)((char *)this + 4) = 0x9d9908;
    *(int *)((char *)this + 0x18) = 0x9d98fc;
    *(int *)((char *)this + 0x1c) = 0x9d98f4;
    finish();
}
