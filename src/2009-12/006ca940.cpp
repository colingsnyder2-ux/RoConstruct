// from server: 81% by atomic.potato
typedef unsigned char byte;
typedef unsigned int DWORD;

extern "C" void imported_destructor(void *);
extern "C" void __stdcall cleanup(void *);

struct S
{
    S *f(byte);
};

S *S::f(byte flag)
{
    char buffer[32];
    *(DWORD *)this = 0x9d774c;
    imported_destructor((char *)this + 0xc020);
    if (flag & 1)
        cleanup(this);
    return this;
}
