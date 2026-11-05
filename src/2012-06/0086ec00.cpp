// from server: 91% by Intel
struct VInstance;

extern "C" void __cdecl sub_86e7c0(int, int);

void __cdecl sub_86ec00(int arg1, int arg2)
{
    if (arg2 != 4)
    {
        sub_86e7c0(arg1, arg2);
        return;
    }

    *(int*)arg1 = 0xde5520;
    *(char*)(arg1 + 4) = 0;
    *(char*)(arg1 + 5) = 0;
}
