// from server: 58% by atomic.potato
typedef unsigned long DWORD;

extern "C" int __cdecl sub_7EB880();
extern "C" int __cdecl sub_7EB8A0();
extern "C" void __stdcall cpu_id(int regs[4], int level);

struct S
{
    int f();
};

int S::f()
{
    int a = 0;
    int b = 0;
    if (sub_7EB880() >= 1)
    {
        if (sub_7EB8A0() != 0)
        {
            int regs[4];
            cpu_id(regs, 1);
            b = regs[3];
        }
    }
    if ((b & 0x10000000) == 0)
    {
        return 1;
    }
    int regs2[4];
    cpu_id(regs2, 1);
    a = regs2[1];
    return (a >> 16) & 0xff;
}
