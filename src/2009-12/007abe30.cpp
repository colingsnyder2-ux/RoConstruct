// from server: 75% by atomic.potato
typedef unsigned int DWORD;

extern "C" void G1_func_007d79a0(void *, DWORD, DWORD);

struct Climbing
{
    Climbing(DWORD, DWORD);
};

Climbing::Climbing(DWORD a, DWORD b)
{
    G1_func_007d79a0(this, b, a);
    *(DWORD *)this = 0x9edcd0;
    *(DWORD *)((char *)this + 4) = 0x9edcc8;
}
