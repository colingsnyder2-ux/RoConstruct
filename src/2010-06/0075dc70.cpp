// from server: 87% by atomic.potato
struct S
{
    int f(int);
};

extern "C" void __stdcall sub_709590();
extern "C" void sub_75dc10(S *, int);

int S::f(int value)
{
    sub_709590();
    *(int *)this = 0xA520A4;
    *(int *)((char *)this + 0x20) = 0xA52084;
    sub_75dc10(this, value);
    return (int)this;
}
