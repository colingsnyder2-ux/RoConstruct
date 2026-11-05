// from server: 30% by atomic.potato
struct S
{
    void f();
};

extern "C" void __stdcall sub_91cc30(void*);

void S::f()
{
    sub_91cc30((char*)this + 8);
}
