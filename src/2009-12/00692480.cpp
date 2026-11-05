// from server: 52% by atomic.potato
struct S
{
    int f(int value);
};

extern "C" void __stdcall sub_5F3990(void*, int);

int S::f(int value)
{
    sub_5F3990((char*)this + 0x13c, 1);
    return value;
}
