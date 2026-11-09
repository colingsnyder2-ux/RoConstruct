// from server: 48% by atomic.potato
extern "C" void __stdcall sub_004ffeb0(void*, void*, void*);

struct S
{
    void f(void*);
};

void S::f(void* p)
{
    sub_004ffeb0((char*)this + 0x50, p, 0);
}
