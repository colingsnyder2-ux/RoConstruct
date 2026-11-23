// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header available; layout from disassembly offsets only.

extern "C" void* __fastcall fn_005c9ed0(void* self, int unusedEdx);

extern "C" void* __fastcall fn_005c9f70(void* self, int unusedEdx, int arg)
{
    char* p = (char*)fn_005c9ed0(self, 0);
    *(int*)(p + 0x158) = arg;
    *(int*)(p + 0x00) = 0x839f0c;
    *(int*)(p + 0x10) = 0x839efc;
    *(int*)(p + 0x14) = 0x839ef4;
    *(int*)(p + 0x20) = 0x839eec;
    *(int*)(p + 0x24) = 0x839edc;
    *(int*)(p + 0x44) = 0x839ecc;
    *(int*)(p + 0x64) = 0x839ebc;
    *(int*)(p + 0x84) = 0x839eac;
    *(int*)(p + 0xa4) = 0x839e9c;
    *(int*)(p + 0xc4) = 0x839e8c;
    return p;
}
