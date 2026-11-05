// from server: 76% by atomic.potato
typedef unsigned char BYTE;

extern "C" int __cdecl Function_004436c0();

struct Profiler_00792ee0 {
    int f();
};

int Profiler_00792ee0::f()
{
    if (*(volatile BYTE*)0x00e49108 == 0)
    {
        int value = Function_004436c0();
        if (*(volatile BYTE*)((char*)value + 0x93) == 0)
            return 0;
    }
    return 1;
}
