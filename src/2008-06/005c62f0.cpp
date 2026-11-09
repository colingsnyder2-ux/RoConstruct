// from server: 100% by king_originala
struct Base {
    int f(int a1);
};

struct S {
    S* f(int a1);
};

S* S::f(int a1)
{
    ((Base*)this)->f(a1);
    *(volatile char*)((char*)this + 0x1c) = 0;
    *(volatile int*)((char*)this + 0x00) = 0x839124;
    *(volatile int*)((char*)this + 0x04) = 0x839108;
    *(volatile int*)((char*)this + 0x20) = 0;
    *(volatile int*)((char*)this + 0x24) = 0;
    *(volatile char*)((char*)this + 0x28) = 0;
    *(volatile float*)((char*)this + 0x30) = 0.0f;
    *(volatile float*)((char*)this + 0x34) = 0.0f;
    *(volatile float*)((char*)this + 0x38) = 0.0f;
    *(volatile short*)((char*)this + 0x3c) = 0;
    *(volatile short*)((char*)this + 0x3e) = 0;
    *(volatile int*)((char*)this + 0x40) = 0;
    *(volatile int*)((char*)this + 0x44) = 0;
    return this;
}
