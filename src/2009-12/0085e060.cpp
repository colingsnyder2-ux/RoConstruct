// from server: 96% by atomic.potato
extern "C" int __stdcall SystemParametersInfoA(unsigned int, unsigned int, void *, unsigned int);

struct S
{
    void f(int);
};

void S::f(int value)
{
    *(int *)((char *)this + 0x108) = value;
    if ((value & 2) != 0)
    {
        *(int *)((char *)this + 0xfc) = 0;
        return;
    }
    SystemParametersInfoA(0x26, 0, (char *)this + 0xfc, 0);
}
