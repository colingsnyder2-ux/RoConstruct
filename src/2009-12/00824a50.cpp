// from server: 76% by atomic.potato
typedef unsigned char BYTE;

extern "C" void __stdcall ImportedCall(void *);
extern "C" void Call8a3db0(void *);
extern "C" void __stdcall Call8236b0(void *);

struct S
{
    S *f(BYTE flag);
};

S *S::f(BYTE flag)
{
    ImportedCall((char *)this + 0x74);
    Call8a3db0(this);
    if (flag & 1)
        Call8236b0(this);
    return this;
}
