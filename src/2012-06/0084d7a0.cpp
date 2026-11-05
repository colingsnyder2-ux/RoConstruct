// from server: 79% by atomic.potato
extern "C" int __cdecl sub_831fd0(int, int);
extern "C" int __cdecl sub_832480(int, int);
extern "C" void __cdecl sub_832340(int, int, int);
extern "C" int __cdecl sub_831dc0(int, int, int);
extern "C" void __cdecl sub_831b00(int, int);
extern "C" int __cdecl sub_6c1d00();
extern "C" void __cdecl sub_5771b0(int*, int);

extern int dword_de13b0;

struct LuaArguments {
};

bool __cdecl func(int a, int b, int* out)
{
    int edi = sub_831fd0(a, b);
    if (edi == 0)
        return false;
    if (sub_832480(a, b) == 0)
        return false;
    sub_832340(a, -10000, dword_de13b0);
    int eax = sub_831dc0(a, -1, -2);
    if (eax != 0) {
        sub_831b00(a, -3);
        *out = sub_6c1d00();
        sub_5771b0(out + 1, edi);
        return true;
    }
    sub_831b00(a, -3);
    return false;
}
