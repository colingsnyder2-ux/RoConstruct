// from server: 43% by colin
struct VCApp {
    int CComObject(int a, int b);
};

extern "C" int __stdcall sub_408460(int);
extern "C" int __stdcall sub_41bd80(int);
extern "C" int __stdcall sub_429220(int, int, int);
extern "C" int __stdcall sub_62ff38(int, int);
extern "C" int __stdcall sub_62ff3e(int);
extern "C" int __stdcall sub_62ff44(int);
extern "C" int __stdcall sub_72a5a2(int);
extern "C" int __stdcall sub_72a5a8(int, int);
extern "C" int __stdcall sub_72a5ae(int, int);

extern "C" int __stdcall imp_77dd90(int);
extern "C" int __stdcall imp_77dd94(int, int, int);
extern "C" int __stdcall imp_77dd98(int);
extern "C" int __stdcall imp_77ddac(int);
extern "C" int __stdcall imp_77ddbc(int);

int VCApp::CComObject(int a, int b) {
    int result;
    int local10;
    int local14;
    int local18;
    int local1c;
    int local20;
    int local24;
    int local28;
    int local2c;
    int local30;
    int local34;
    int local38;

    local10 = 0;
    local14 = 0;
    local18 = 0;
    local1c = 0;
    local20 = 0;
    local24 = 0;
    local28 = 0;
    local2c = 0;
    local30 = 0;
    local34 = 0;
    local38 = 0;

    sub_62ff44(0);
    sub_62ff3e((int)&local10);

    int edi = sub_41bd80(a);
    if (edi == 0) {
        imp_77ddac(0);
        imp_77dd90(a);
        int t = *(int*)local10;
        imp_77dd94((int)&local38, 0x7851b8, t);
        imp_77ddbc((int)&local10);
        imp_77dd98((int)&local38);
        result = sub_429220(0x790290, 0, edi);
        imp_77ddbc((int)&local38);
        if (local14 != 0) {
            *(int*)(local14 + 4) = local10;
        }
        if (local1c != 0) {
            sub_62ff38(0, local18);
        }
        return result;
    }

    sub_408460(0);
    imp_77dd98(0);
    sub_72a5ae(0x1000, 0);
    imp_77ddbc((int)&local38);
    sub_72a5a8(2, 0);
    imp_77dd90(a);
    imp_77dd98(0x785194);
    result = sub_72a5a2(0);
    imp_77ddbc((int)&local10);
    if (result != 0 && result != 0x669) {
        result = sub_429220(0x790290, 0x785178, result);
    }
    if (local14 != 0) {
        *(int*)(local14 + 4) = local10;
    }
    if (local1c != 0) {
        sub_62ff38(0, local18);
    }
    return result;
}
