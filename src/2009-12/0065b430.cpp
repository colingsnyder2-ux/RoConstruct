// from server: 100% by atomic.potato
extern "C" void __declspec(noreturn) finish();

struct S
{
    void f();
};

void S::f()
{
    *(int*)this = 0x9cd984;
    *((int*)this + 1) = 0x9cd97c;
    *((int*)this + 6) = 0x9cd970;
    *((int*)this + 7) = 0x9cd968;
    finish();
}
