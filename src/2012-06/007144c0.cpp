// from server: 83% by Intel
typedef unsigned long DWORD;
typedef int BOOL;

extern "C" BOOL __stdcall G1_func_00972eb0(void* thisptr);
extern "C" BOOL __stdcall G1_func_00972290(int, const char*);
extern "C" BOOL __cdecl G1_func_00E5809C(int, const char*, const char*);

extern unsigned char G1_byte_00E580B3;
extern DWORD G1_dword_00E5809C;

extern const char G1_str_00BA0D10[];
extern const char G1_str_00BA1D98[];
extern const char G1_str_00BA1EC0[];

struct Tool
{
    void func_0070F460();
    void func_00713300();
    void func_00713530();
    void func_00712540();
    void func_007131E0(int);

    void func_007144C0();
};

void Tool::func_007144C0()
{
    if (G1_byte_00E580B3 != 0)
    {
        void* checkPtr = (char*)this + 0x244;
        if (G1_func_00972eb0(checkPtr))
        {
            if (G1_dword_00E5809C != 0)
            {
                if (G1_func_00E5809C(0x147, G1_str_00BA0D10, G1_str_00BA1D98))
                {
                    goto LABEL_END;
                }
            }
            int flag = G1_byte_00E580B3;
            G1_func_00972290(flag, G1_str_00BA1EC0);
        }
    }

LABEL_END:
    this->func_0070F460();
    this->func_00713300();
    this->func_00713530();
    this->func_00712540();
    this->func_007131E0(5);
}
