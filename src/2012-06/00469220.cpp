// from server: 44% by atomic.potato
extern "C" {
    int __stdcall sub_4691A0(int, int, int, int);
    void __stdcall sub_759C10();
    void __stdcall sub_972290(int, int);
    int __cdecl sub_B229EC(int);
}

extern unsigned char byte_E580B3;
extern int (__cdecl *dword_E5809C)(int, int, int);

struct S {
    void f(int, int, int, int);
};

void S::f(int a, int b, int c, int d)
{
    int v = sub_4691A0(a, b, c, d);
    sub_759C10();
    *(int*)this = 0xB58674;
    if (byte_E580B3 != 0) {
        if (sub_B229EC(0xD6A8CC) == 0) {
            if (dword_E5809C != 0) {
                if (dword_E5809C(0xB44978, 0xB58618, 0x1D5) != 0)
                    return;
            }
            sub_972290(byte_E580B3, 0xB58588);
        }
    }
}
