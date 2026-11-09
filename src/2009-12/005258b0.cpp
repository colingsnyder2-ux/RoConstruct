// from server: 100% by atomic.potato
extern "C" void __cdecl sub_005250b0(int, int, int);

struct S_func_005258b0 {
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        sub_005250b0(a, b, c);
        return;
    }

    *(int*)b = 0xb1a268;
    *((char*)b + 4) = 0;
    *((char*)b + 5) = 0;
}
