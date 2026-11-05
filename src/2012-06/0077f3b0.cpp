// from server: 27% by Intel
struct EnumDesc
{
    void Initialize();
};

extern "C" void __stdcall func_0077f2b0(int);
extern "C" void __stdcall func_006cab60(int, int);
extern "C" void __stdcall func_009831f5(int);

int dword_BEF8A8;
char byte_E3A0C4;
int dword_E39EE0;
int dword_B1B350;
int dword_AC41BE;

void EnumDesc::Initialize()
{
    int eax = 1;
    if (byte_E3A0C4 & 1)
    {
        eax = dword_E39EE0;
    }
    else
    {
        byte_E3A0C4 |= 1;
        int ecx = 0;
        char local_c[12];
        local_c[0] = 0;
        local_c[1] = 0;
        *(int*)(local_c + 4) = 0;
        *(int*)(local_c + 8) = 0x1B;
        int eax2 = dword_BEF8A8;
        func_0077f2b0(eax2);
        func_006cab60(dword_E39EE0, eax);
        func_009831f5(dword_B1B350);
        eax = dword_E39EE0;
    }
}
