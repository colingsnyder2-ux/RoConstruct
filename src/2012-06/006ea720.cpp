// from server: 13% by atomic.potato
struct S {
    char pad0[0x30];
    void (__thiscall *fn30)(int);
    int field34;
    int field38;
    int field3c;
    int method(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

extern "C" void __stdcall sub_8ead80(int, int);
extern "C" void __stdcall sub_535930(int);
extern "C" void __stdcall sub_5337e0(int, int, int, int);
extern "C" void __stdcall sub_533590(int, int, int, int);

int S::method(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8,
              int a9, int a10, int a11, int a12, int a13, int a14, int a15,
              int a16, int a17, int a18)
{
    int local0 = 0;
    int local1 = 0;
    int local2 = 0;
    int local3 = 0;
    int local4 = 0;
    int local5 = 0;
    int local6 = 0;
    int local7 = 0;
    int local8 = 0;
    int local9 = 0;
    int local10 = 0;
    int local11 = 0;
    int local12 = 0;
    int local13 = 0;
    int local14 = 0;
    int local15 = 0;
    int local16 = 0;
    int local17 = 0;
    int local18 = 0;
    int local19 = 0;
    int local20 = 0;
    int local21 = 0;
    int local22 = 0;
    int local23 = 0;
    int local24 = 0;
    int local25 = 0;
    int local26 = 0;
    int local27 = 0;
    int local28 = 0;
    int local29 = 0;
    int local30 = 0;
    int local31 = 0;

    if (a1) {
        local0 = a1;
        (*(void (__thiscall **)(int, int, int))a1)(a1, 0, (int)&local0);
    }

    unsigned char b = *(unsigned char*)0xe2f383;

    if (a2) {
        local1 = a2;
        (*(void (__thiscall **)(int, int, int))a2)(a2, 0, (int)&local1);
    }

    sub_8ead80((int)&local2, 0x532580);
    sub_535930((int)&local3);

    sub_5337e0((int)&local4, a3, (int)&this->field3c, 0);
    sub_533590((int)&local5, a3, (int)&this->field38, 0);

    int v = local6;
    if (v) v -= 0x1c;
    else v = 0;

    this->fn30(this->field34 + v);

    if (local7) {
        void (__thiscall *f)(int, int, int) = *(void (__thiscall **)(int, int, int))local7;
        if (f) f(local7, (int)&local8, 2);
        local7 = 0;
    }

    if (local9) {
        void (__thiscall *f)(int, int, int) = *(void (__thiscall **)(int, int, int))local9;
        if (f) f(local9, (int)&local10, 2);
    }

    return 0;
}
