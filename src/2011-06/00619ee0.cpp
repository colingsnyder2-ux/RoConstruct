// from server: 77% by atomic.potato
extern "C" {
int __stdcall sub_762b30(int, int);
int __stdcall sub_762c10(int, int);
int __stdcall sub_762550(int, int);
int __stdcall sub_762370(int, int);
int __stdcall sub_762520(int, int);
int __stdcall sub_762e50(int, int);
int __stdcall sub_7623c0(int, int);
int __stdcall sub_618770(int, int);
}

struct S {
};

int __cdecl f(int a, int b) {
    int esi = a;
    int edi = b;
    sub_762b30(esi, 0x619ee0);
    sub_762c10(esi, 0xffffd8f0);
    sub_762b30(esi, edi);
    sub_762c10(esi, -2);
    if (sub_762550(esi, -1) == 0) {
        sub_762370(esi, -2);
        sub_618770(esi, edi);
        sub_762b30(esi, edi);
        sub_762520(esi, -2);
        sub_762e50(esi, -4);
    }
    sub_7623c0(esi, -2);
    return 0;
}
