// from server: 100% by auto
// roc 2007-03 00401d10  unit: seg_00400000  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401d10
//
// 00401d10  56                   push esi
// 00401d11  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00401d15  85f6                 test esi, esi
// 00401d17  57                   push edi
// 00401d18  8bf9                 mov edi, ecx
// 00401d1a  750a                 jne 0x401d26
// 00401d1c  6805400080           push 0x80004005
// 00401d21  e8daf2ffff           call 0x401000
// 00401d26  56                   push esi
// 00401d27  ff15b4d27700         call dword ptr [0x77d2b4]
// 00401d2d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00401d31  8b17                 mov edx, dword ptr [edi]
// 00401d33  83c001               add eax, 1
// 00401d36  50                   push eax
// 00401d37  8b442418             mov eax, dword ptr [esp + 0x18]
// 00401d3b  56                   push esi
// 00401d3c  50                   push eax
// 00401d3d  6a00                 push 0
// 00401d3f  51                   push ecx
// 00401d40  52                   push edx
// 00401d41  ff1520d07700         call dword ptr [0x77d020]
// 00401d47  5f                   pop edi
// 00401d48  5e                   pop esi
// 00401d49  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function ?SetStringValue@CRegKey@ATL@@QAEJPBD0K@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
