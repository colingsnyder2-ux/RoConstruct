// from server: 100% by atomic.potato
extern "C" void __stdcall sub_80b3e0(int, int, int, int);

struct CAudioStream
{
    void f();
};

void CAudioStream::f()
{
    sub_80b3e0(*(int *)((char *)this + 0x58),
               *(int *)((char *)this + 0x5c),
               0x2710,
               0);
}
