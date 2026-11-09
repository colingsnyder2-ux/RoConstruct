// from server: 30% by Intel
extern "C" void __stdcall func_004125d0(int);
extern "C" void __stdcall func_006cab60(int, int);
extern "C" void __cdecl func_009831f5(int);

int* g_ptr_00bb7230 = (int*)0x00bb7230;
int* g_ptr_00e418e0 = (int*)0x00e418e0;
char* g_byte_00e41ac4 = (char*)0x00e41ac4;

struct EnumDesc {
    int func();
};

int EnumDesc::func() {
    int v1;
    int v2 = 1;
    if (!(*g_byte_00e41ac4 & 1)) {
        *g_byte_00e41ac4 |= 1;
        int v3 = 0;
        char buffer[12];
        *(int*)&buffer[0] = 0;
        *(int*)&buffer[4] = 0;
        *(int*)&buffer[8] = 1;
        func_004125d0(*g_ptr_00bb7230);
        func_006cab60((int)g_ptr_00e418e0, (int)&buffer);
        func_009831f5(0x00b1af50);
    }
    return (int)g_ptr_00e418e0;
}
