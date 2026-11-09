// from server: 46% by Intel
extern "C" void __stdcall func_004125d0(int);
extern "C" void __stdcall func_006cab60(int, int);
extern "C" void __stdcall func_009831f5(int);

int dword_00BC069C;
char byte_00E46EA4;
int dword_00E46CC0;

void func_007829B0()
{
    int v0 = 0;
    if (!byte_00E46EA4)
    {
        byte_00E46EA4 = 1;
        char buffer[12];
        buffer[0] = 0;
        buffer[1] = 0;
        *(int*)&buffer[4] = 0;
        *(int*)&buffer[8] = 27;
        func_004125d0(dword_00BC069C);
        func_006cab60(dword_00E46CC0, (int)buffer);
        func_009831f5(0x00B1AC90);
    }
}
