// from server: 28% by Intel
struct EnumDesc {
    void Initialize();
};

extern "C" void __stdcall func_004125d0(int);
extern "C" void __stdcall func_006cab60(int, int);
extern "C" void __stdcall func_009831f5(int);

int dword_BDBB28;
char byte_E3F2BC;
int dword_E3F0D8;
int dword_AC471E;
int dword_B1B0A0;

void EnumDesc::Initialize() {
    int v1 = 1;
    if (!byte_E3F2BC) {
        byte_E3F2BC = 1;
        char buffer[12];
        buffer[0] = 0;
        buffer[1] = 0;
        *(int*)&buffer[4] = 0;
        *(int*)&buffer[8] = 27;
        func_004125d0(dword_BDBB28);
        func_006cab60(dword_E3F0D8, 0);
        func_009831f5(dword_B1B0A0);
    }
}
