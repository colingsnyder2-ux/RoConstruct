// from server: 9% by Intel
typedef int DWORD;

struct RBX_PlayerChatLine {
    DWORD v0;
    DWORD v1;
    DWORD v2;
    DWORD v3;
    DWORD v4;
    DWORD v5;
    DWORD v6;
    DWORD v7;
    DWORD v8;
    DWORD v9;
    DWORD v10;
    DWORD v11;
    DWORD v12;
    DWORD v13;

    int f();
};

extern "C" int __stdcall func_0ad9098(DWORD);
extern "C" int __stdcall func_03e280(DWORD);
extern "C" int __stdcall func_03c9f0(DWORD);

int RBX_PlayerChatLine::f() {
    DWORD arg0;
    DWORD arg1 = 0xAD9098;
    DWORD arg2 = 0x00000000;
    DWORD esi;
    DWORD edi;
    DWORD eax;
    DWORD arg3;
    DWORD arg4;
    DWORD arg5;
    DWORD arg6;
    DWORD arg7;
    DWORD arg8;
    DWORD arg9;
    DWORD arg10;
    DWORD arg11;
    DWORD arg12;
    DWORD arg13;

    arg0 = -1;
    eax = func_0ad9098(arg1);
    esi = eax;
    edi = (DWORD)this;
    arg3 = esi;
    arg4 = (DWORD)this;
    arg5 = 0;
    arg6 = esi;
    arg7 = edi;
    arg8 = esi;
    arg9 = edi;
    arg10 = 0;
    arg11 = esi;
    arg12 = esi;
    arg13 = esi;

    // This represents the structural flow of the provided assembly
    // The assembly performs stack-based setup and calls.
    return 0;
}
