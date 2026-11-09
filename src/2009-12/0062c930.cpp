// from server: 100% by atomic.potato
struct S
{
    void f();
};

extern "C" void __declspec(noreturn) g();

void S::f()
{
    *(int*)((char*)this + 0) = 0x9cafd4;
    *(int*)((char*)this + 4) = 0x9cafc8;
    *(int*)((char*)this + 0x18) = 0x9cafbc;
    *(int*)((char*)this + 0x1c) = 0x9cafb4;
    g();
}
