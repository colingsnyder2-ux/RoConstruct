// from server: 77% by Intel
extern "C" void __cdecl func_004015a0(int, int);
extern "C" void __cdecl func_009831f5(int);

char byte_00E4A498;
int dword_00E4A490;
int dword_00E4A494;

int func_007A1B20()
{
    func_004015a0(0xE4A49C, 0x7A1AF0);
    if (byte_00E4A498)
        return 0xE4A490;

    byte_00E4A498 = 1;
    dword_00E4A490 = 0;
    dword_00E4A494 = 0;
    func_009831f5(0xB1BEF0);
    return 0xE4A490;
}
