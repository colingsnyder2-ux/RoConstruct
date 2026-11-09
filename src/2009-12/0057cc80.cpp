// from server: 76% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __stdcall f57c040(void *, DWORD);

struct S
{
    void *f(DWORD);
};

void *S::f(DWORD a)
{
    f57c040(this, a);
    *(DWORD *)((char *)this + 0x3c) = 0x99fd90;
    *(DWORD *)this = 0x9c0d48;
    *(DWORD *)((char *)this + 0x28) = 0x9c0d40;
    *(DWORD *)((char *)this + 0x3c) = 0x9c0d30;
    return this;
}
