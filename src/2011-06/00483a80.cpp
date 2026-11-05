// from server: 100% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl sub_413d60();

void S::f()
{
    *(unsigned long*)((char*)this + 0x00) = 0x00a726dc;
    *(unsigned long*)((char*)this + 0x04) = 0x00a726d4;
    *(unsigned long*)((char*)this + 0x18) = 0x00a726c8;
    *(unsigned long*)((char*)this + 0x1c) = 0x00a726bc;
    *(unsigned long*)((char*)this + 0x90) = 0x00a726b4;
    sub_413d60();
}
