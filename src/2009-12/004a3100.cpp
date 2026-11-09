// from server: 75% by atomic.potato
extern "C" void __stdcall sub_4a2c80(void *, int);

struct S
{
    int f(int);
};

int S::f(int value)
{
    int count = ((*(int *)((char *)this + 0x54) -
                  *(int *)((char *)this + 0x50)) >> 5) + value;
    sub_4a2c80((char *)this + 0x44, count);
    return (*(int *)((char *)this + 0x54) -
            *(int *)((char *)this + 0x50)) >> 5;
}
