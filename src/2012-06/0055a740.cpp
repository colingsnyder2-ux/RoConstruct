// from server: 58% by Intel
struct FactoryProduct {
    FactoryProduct* __thiscall Initialize();
};

extern "C" void __cdecl func_004015a0(int, int);
extern "C" void __cdecl func_009831f5(int);

int g_flag_00e23c64;
int g_dword_00e23c5c;
int g_dword_00e23c60;
int g_dword_00e23c68;
int g_dword_0055a610;
int g_dword_00b14290;

FactoryProduct* __thiscall FactoryProduct::Initialize() {
    int* this_ptr = reinterpret_cast<int*>(this);
    *this_ptr = 0;

    func_004015a0(g_dword_0055a610, g_dword_00e23c68);

    if (!(g_flag_00e23c64 & 1)) {
        g_flag_00e23c64 |= 1;
        g_dword_00e23c5c = 0;
        g_dword_00e23c60 = 0;
        func_009831f5(g_dword_00b14290);
    }

    return this;
}
