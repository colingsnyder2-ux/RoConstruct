// from server: 100% by auto
// roc 2010-06 0089b1a0  unit: CXTPScrollBase  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089b1a0
//
// 0089b1a0  83ec2c               sub esp, 0x2c
// 0089b1a3  56                   push esi
// 0089b1a4  8bf1                 mov esi, ecx
// 0089b1a6  8b06                 mov eax, dword ptr [esi]
// 0089b1a8  8b5010               mov edx, dword ptr [eax + 0x10]
// 0089b1ab  8d4c2404             lea ecx, [esp + 4]
// 0089b1af  51                   push ecx
// 0089b1b0  8bce                 mov ecx, esi
// 0089b1b2  ffd2                 call edx
// 0089b1b4  8b06                 mov eax, dword ptr [esi]
// 0089b1b6  8b5014               mov edx, dword ptr [eax + 0x14]
// 0089b1b9  8d4c2414             lea ecx, [esp + 0x14]
// 0089b1bd  51                   push ecx
// 0089b1be  8bce                 mov ecx, esi
// 0089b1c0  ffd2                 call edx
// 0089b1c2  8b06                 mov eax, dword ptr [esi]
// 0089b1c4  8d4c2414             lea ecx, [esp + 0x14]
// 0089b1c8  51                   push ecx
// 0089b1c9  8d5604               lea edx, [esi + 4]
// 0089b1cc  52                   push edx
// 0089b1cd  8b5020               mov edx, dword ptr [eax + 0x20]
// 0089b1d0  8d4c240c             lea ecx, [esp + 0xc]
// 0089b1d4  51                   push ecx
// 0089b1d5  8bce                 mov ecx, esi
// 0089b1d7  ffd2                 call edx
// 0089b1d9  5e                   pop esi
// 0089b1da  83c42c               add esp, 0x2c
// 0089b1dd  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?SetupScrollInfo@CXTPScrollBase@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPScrollBase.cpp
