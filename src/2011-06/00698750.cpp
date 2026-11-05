// from server: 73% by atomic.potato
extern "C" void __cdecl sub_0080B15D();

struct S
{
    void* f();
};

void* S::f()
{
    *(volatile unsigned char*)0x00CCFA90 += 0;
    sub_0080B15D();
    return (void*)0x00CCFA8C;
}
