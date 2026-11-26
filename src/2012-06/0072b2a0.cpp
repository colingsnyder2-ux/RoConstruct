// from server: 100% by Xemicl
// roc 2012-06 0072b2a0  unit: RBX::Workspace  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0072b2a0
//
// 0072b2a0  81ecd0000000         sub esp, 0xd0
// 0072b2a6  8d0424               lea eax, [esp]
// 0072b2a9  50                   push eax
// 0072b2aa  ff151451b200         call dword ptr [0xb25114]
// 0072b2b0  33c9                 xor ecx, ecx
// 0072b2b2  6a7e                 push 0x7e
// 0072b2b4  51                   push ecx
// 0072b2b5  8d54245a             lea edx, [esp + 0x5a]
// 0072b2b9  52                   push edx
// 0072b2ba  66894c245c           mov word ptr [esp + 0x5c], cx
// 0072b2bf  e8b0802500           call 0x983374
// 0072b2c4  83c40c               add esp, 0xc
// 0072b2c7  6a40                 push 0x40
// 0072b2c9  8d442454             lea eax, [esp + 0x54]
// 0072b2cd  50                   push eax
// 0072b2ce  8d4c2408             lea ecx, [esp + 8]
// 0072b2d2  51                   push ecx
// 0072b2d3  ff154051b200         call dword ptr [0xb25140]
// 0072b2d9  6a00                 push 0
// 0072b2db  6a00                 push 0
// 0072b2dd  6a40                 push 0x40
// 0072b2df  8d54241c             lea edx, [esp + 0x1c]
// 0072b2e3  52                   push edx
// 0072b2e4  6a40                 push 0x40
// 0072b2e6  8d442464             lea eax, [esp + 0x64]
// 0072b2ea  50                   push eax
// 0072b2eb  6a00                 push 0
// 0072b2ed  6a00                 push 0
// 0072b2ef  ff15c821b200         call dword ptr [0xb221c8]
// 0072b2f5  8d4c2410             lea ecx, [esp + 0x10]
// 0072b2f9  51                   push ecx
// 0072b2fa  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 0072b301  ff158c26b200         call dword ptr [0xb2268c]
// 0072b307  81c4d0000000         add esp, 0xd0
// 0072b30d  c3                   ret 
// copied from an identical function in another client (function ?makeGuidString@ns_ROCX00000c@@YAXAAUString@1@@Z)

namespace ns_ROCX00000c {
// from server: 100% by king_originala
// roc 2008-06 005a80d0  unit: RBX::Log  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a80d0
//
// 005a80d0  81ecd0000000         sub esp, 0xd0
// 005a80d6  8d0424               lea eax, [esp]
// 005a80d9  50                   push eax
// 005a80da  ff1538418000         call dword ptr [0x804138]
// 005a80e0  33c9                 xor ecx, ecx
// 005a80e2  6a7e                 push 0x7e
// 005a80e4  51                   push ecx
// 005a80e5  8d54245a             lea edx, [esp + 0x5a]
// 005a80e9  52                   push edx
// 005a80ea  66894c245c           mov word ptr [esp + 0x5c], cx
// 005a80ef  e810960f00           call 0x6a1704
// 005a80f4  83c40c               add esp, 0xc
// 005a80f7  6a40                 push 0x40
// 005a80f9  8d442454             lea eax, [esp + 0x54]
// 005a80fd  50                   push eax
// 005a80fe  8d4c2408             lea ecx, [esp + 8]
// 005a8102  51                   push ecx
// 005a8103  ff1528418000         call dword ptr [0x804128]
// 005a8109  6a00                 push 0
// 005a810b  6a00                 push 0
// 005a810d  6a40                 push 0x40
// 005a810f  8d54241c             lea edx, [esp + 0x1c]
// 005a8113  52                   push edx
// 005a8114  6a40                 push 0x40
// 005a8116  8d442464             lea eax, [esp + 0x64]
// 005a811a  50                   push eax
// 005a811b  6a00                 push 0
// 005a811d  6a00                 push 0
// 005a811f  ff15ec228000         call dword ptr [0x8022ec]
// 005a8125  8d4c2410             lea ecx, [esp + 0x10]
// 005a8129  51                   push ecx
// 005a812a  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 005a8131  ff154c248000         call dword ptr [0x80244c]
// 005a8137  81c4d0000000         add esp, 0xd0
// 005a813d  c3                   ret 

struct GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

struct String {};

extern "C" {
    extern long (__stdcall *CoCreateGuid)(GUID*);
    extern int (__stdcall *StringFromGUID2)(const GUID&, wchar_t*, int);
    extern int (__stdcall *WideCharToMultiByte)(
        unsigned int, unsigned long, const wchar_t*, int,
        char*, int, const char*, int*);
    extern String& (__thiscall *assignString)(String*, const char*);
    void* __cdecl memset(void*, int, unsigned int);
}

void __cdecl makeGuidString(String& result)
{
    GUID guid;
    char text[64];
    CoCreateGuid(&guid);
    wchar_t wide[64] = {0};
    StringFromGUID2(guid, wide, 64);
    WideCharToMultiByte(0, 0, wide, 64, text, 64, 0, 0);
    assignString(&result, text);
}
}
