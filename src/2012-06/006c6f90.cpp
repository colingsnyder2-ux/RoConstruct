// from server: 22% by Intel
extern "C" void __stdcall func_005574b0();
extern "C" void __stdcall func_006cab60(int);
extern "C" void __stdcall func_009831f5(int);

struct Settings {
    void func_006c6f90();
};

void Settings::func_006c6f90() {
    static int guard = 0;
    if (!guard) {
        guard = 1;
        char buffer[12];
        *(int*)buffer = 0;
        *(int*)(buffer + 4) = 0;
        *(int*)(buffer + 8) = 27;
        func_005574b0();
        func_006cab60(0xE2E4E8);
        func_009831f5(0xB167B0);
    }
}
