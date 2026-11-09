// from server: 86% by atomic.potato
extern "C" long __stdcall InterlockedExchange(volatile long *Target, long Value);

extern "C" void __cdecl sub_7E5B60(void *);
extern "C" void __cdecl sub_7E5C10();

extern int dword_B64AE8;
extern int dword_B99164;
extern double qword_B99128;

void *__cdecl sub_7E5D40(void *arg)
{
    if (dword_B64AE8 <= 0)
    {
        sub_7E5B60(arg);
        return arg;
    }
    if (dword_B99164 == 0)
    {
        if (InterlockedExchange((volatile long *)&dword_B99164, 1) == 0)
            sub_7E5C10();
    }
    *(double *)arg = qword_B99128;
    return arg;
}
