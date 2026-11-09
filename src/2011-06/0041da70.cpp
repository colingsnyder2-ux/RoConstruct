// from server: 90% by atomic.potato
struct S_func_0041da70 {
    void f();
};

extern "C" int __cdecl sub_007f90e0(int, const char*, const char*, int, int, int, int);
extern unsigned char byte_00ccc396;
extern char str_00a63bf0[];
extern char str_00a63ae4[];

void S_func_0041da70::f()
{
    if (byte_00ccc396) {
        sub_007f90e0(3, str_00a63bf0, str_00a63ae4, 0x47c, 0, 0, 0);
    }
    ((void (__thiscall*)(void*))0x41d710)(this);
}
