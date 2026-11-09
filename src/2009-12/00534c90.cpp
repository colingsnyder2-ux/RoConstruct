// from server: 75% by atomic.potato
struct IdSerializer {
};

extern "C" int __stdcall sub_5340A0(int, int, int);
extern "C" int __stdcall sub_5348A0(int);

void __cdecl f(int a, int b)
{
    int local = 0xC2;
    sub_5340A0(a, b, (int)&local);
    if (*(int*)(a + 4) != 0)
        sub_5348A0((int)&local);
}
