// from server: 100% by auto
// roc 2010-06 00721ac0  unit: RBX::UniversalTool  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721ac0
//
// 00721ac0  8b442408             mov eax, dword ptr [esp + 8]
// 00721ac4  53                   push ebx
// 00721ac5  56                   push esi
// 00721ac6  57                   push edi
// 00721ac7  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00721acb  8bcf                 mov ecx, edi
// 00721acd  e8cef2ffff           call 0x720da0
// 00721ad2  8b7708               mov esi, dword ptr [edi + 8]
// 00721ad5  8bd8                 mov ebx, eax
// 00721ad7  8b442418             mov eax, dword ptr [esp + 0x18]
// 00721adb  8b0b                 mov ecx, dword ptr [ebx]
// 00721add  50                   push eax
// 00721ade  51                   push ecx
// 00721adf  57                   push edi
// 00721ae0  83ee10               sub esi, 0x10
// 00721ae3  e8b8bb0500           call 0x77d6a0
// 00721ae8  8b16                 mov edx, dword ptr [esi]
// 00721aea  8910                 mov dword ptr [eax], edx
// 00721aec  8b4e04               mov ecx, dword ptr [esi + 4]
// 00721aef  894804               mov dword ptr [eax + 4], ecx
// 00721af2  8b5608               mov edx, dword ptr [esi + 8]
// 00721af5  895008               mov dword ptr [eax + 8], edx
// 00721af8  8b4708               mov eax, dword ptr [edi + 8]
// 00721afb  b904000000           mov ecx, 4
// 00721b00  83c40c               add esp, 0xc
// 00721b03  3948f8               cmp dword ptr [eax - 8], ecx
// 00721b06  7c1a                 jl 0x721b22
// 00721b08  8b40f0               mov eax, dword ptr [eax - 0x10]
// 00721b0b  f6400503             test byte ptr [eax + 5], 3
// 00721b0f  7411                 je 0x721b22
// 00721b11  8b1b                 mov ebx, dword ptr [ebx]
// 00721b13  844b05               test byte ptr [ebx + 5], cl
// 00721b16  740a                 je 0x721b22
// 00721b18  53                   push ebx
// 00721b19  57                   push edi
// 00721b1a  e871940500           call 0x77af90
// 00721b1f  83c408               add esp, 8
// 00721b22  834708f0             add dword ptr [edi + 8], -0x10
// 00721b26  5f                   pop edi
// 00721b27  5e                   pop esi
// 00721b28  5b                   pop ebx
// 00721b29  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawseti)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
