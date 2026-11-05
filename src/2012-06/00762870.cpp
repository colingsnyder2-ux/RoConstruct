// from server: 39% by Intel
typedef unsigned int DWORD;

extern "C" void __cdecl func_004015a0(DWORD, DWORD);
extern "C" void __cdecl func_009831f5(DWORD);

int func_00762870()
{
    func_004015a0(0x762840, 0xE37360);
    if (!(*(unsigned char*)0xE3735C & 1))
    {
        *(unsigned char*)0xE3735C |= 1;
        *(DWORD*)0xE37354 = 0;
        *(DWORD*)0xE37358 = 0;
        func_009831f5(0xB18B60);
    }
    return 0xE37354;
}
