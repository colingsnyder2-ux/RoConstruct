// from server: 89% by atomic.potato
struct S
{
    int f(int);
};

extern "C" void __stdcall sub_5f3990(void *, int);

int S::f(int value)
{
    sub_5f3990((char *)this + 0xc8, value);
    return value;
}
