// from server: 94% by atomic.potato
typedef unsigned long DWORD;

extern "C" void Finish();

struct S
{
    int f();
};

int S::f()
{
    *(DWORD*)0x00c05d1c = 0;
    *(DWORD*)((char*)this + 0) = 0x00a19efc;
    *(DWORD*)((char*)this + 4) = 0x00a19ef4;
    *(DWORD*)((char*)this + 0x18) = 0x00a19ee8;
    *(DWORD*)((char*)this + 0x1c) = 0x00a19edc;
    Finish();
    return 0;
}
