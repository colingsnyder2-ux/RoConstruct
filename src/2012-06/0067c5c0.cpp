// from server: 24% by Intel
extern "C" void __stdcall func_004125d0();
extern "C" void __stdcall func_006cab60();
extern "C" void __stdcall func_009831f5();

struct EnumDesc {
    int f();
};

int EnumDesc::f() {
    int v1;
    char v2[12];
    int v3;

    if (*(char*)0xE294C4) {
        return (int)0xE292E0;
    }

    *(char*)0xE294C4 = 1;
    v3 = 0;
    v2[0] = 0;
    v2[1] = 0;
    *(int*)&v2[4] = 0;
    *(int*)&v2[8] = 27;

    func_004125d0();
    func_006cab60();
    func_009831f5();

    return (int)0xE292E0;
}
