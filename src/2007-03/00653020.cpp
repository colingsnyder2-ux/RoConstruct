// from server: 100% by auto
// roc 2007-03 00653020  unit: seg_00650000  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00653020
//
// 00653020  83ec10               sub esp, 0x10
// 00653023  57                   push edi
// 00653024  8bf9                 mov edi, ecx
// 00653026  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00653029  e8a4b6fcff           call 0x61e6d2
// 0065302e  837f0400             cmp dword ptr [edi + 4], 0
// 00653032  744c                 je 0x653080
// 00653034  56                   push esi
// 00653035  8bcf                 mov ecx, edi
// 00653037  e874f0ffff           call 0x6520b0
// 0065303c  8bf0                 mov esi, eax
// 0065303e  85f6                 test esi, esi
// 00653040  743d                 je 0x65307f
// 00653042  53                   push ebx
// 00653043  8b1d54ee7700         mov ebx, dword ptr [0x77ee54]
// 00653049  8da42400000000       lea esp, [esp]
// 00653050  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00653053  6a01                 push 1
// 00653055  8d442410             lea eax, [esp + 0x10]
// 00653059  50                   push eax
// 0065305a  56                   push esi
// 0065305b  e8b2b8fcff           call 0x61e912
// 00653060  8b5734               mov edx, dword ptr [edi + 0x34]
// 00653063  8b4220               mov eax, dword ptr [edx + 0x20]
// 00653066  6a01                 push 1
// 00653068  8d4c2410             lea ecx, [esp + 0x10]
// 0065306c  51                   push ecx
// 0065306d  50                   push eax
// 0065306e  ffd3                 call ebx
// 00653070  56                   push esi
// 00653071  8bcf                 mov ecx, edi
// 00653073  e888f0ffff           call 0x652100
// 00653078  8bf0                 mov esi, eax
// 0065307a  85f6                 test esi, esi
// 0065307c  75d2                 jne 0x653050
// 0065307e  5b                   pop ebx
// 0065307f  5e                   pop esi
// 00653080  5f                   pop edi
// 00653081  83c410               add esp, 0x10
// 00653084  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnKillFocus@CXTPTreeBase@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
