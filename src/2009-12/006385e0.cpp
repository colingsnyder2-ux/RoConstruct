// from server: 100% by atomic.potato
extern "C" void __declspec(noreturn) RBX_VSelection_FactoryProduct_tail();

struct S
{
    void f();
};

void S::f()
{
    *(int *)this = 0x9cc0fc;
    *(int *)((char *)this + 4) = 0x9cc0f4;
    *(int *)((char *)this + 24) = 0x9cc0e8;
    *(int *)((char *)this + 28) = 0x9cc0e0;
    RBX_VSelection_FactoryProduct_tail();
}
