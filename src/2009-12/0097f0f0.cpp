// from server: 53% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl func_004e8f30();

void S::f()
{
    volatile int stack_placeholder;
    (void)stack_placeholder;
    func_004e8f30();
}
