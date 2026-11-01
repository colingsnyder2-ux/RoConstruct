// from server: 100% by auto
// roc 2009-06 008101a0  unit: CXTPScrollBase  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008101a0
//
// 008101a0  83ec2c               sub esp, 0x2c
// 008101a3  56                   push esi
// 008101a4  8bf1                 mov esi, ecx
// 008101a6  8b06                 mov eax, dword ptr [esi]
// 008101a8  8b5010               mov edx, dword ptr [eax + 0x10]
// 008101ab  8d4c2404             lea ecx, [esp + 4]
// 008101af  51                   push ecx
// 008101b0  8bce                 mov ecx, esi
// 008101b2  ffd2                 call edx
// 008101b4  8b06                 mov eax, dword ptr [esi]
// 008101b6  8b5014               mov edx, dword ptr [eax + 0x14]
// 008101b9  8d4c2414             lea ecx, [esp + 0x14]
// 008101bd  51                   push ecx
// 008101be  8bce                 mov ecx, esi
// 008101c0  ffd2                 call edx
// 008101c2  8b06                 mov eax, dword ptr [esi]
// 008101c4  8d4c2414             lea ecx, [esp + 0x14]
// 008101c8  51                   push ecx
// 008101c9  8d5604               lea edx, [esi + 4]
// 008101cc  52                   push edx
// 008101cd  8b5020               mov edx, dword ptr [eax + 0x20]
// 008101d0  8d4c240c             lea ecx, [esp + 0xc]
// 008101d4  51                   push ecx
// 008101d5  8bce                 mov ecx, esi
// 008101d7  ffd2                 call edx
// 008101d9  5e                   pop esi
// 008101da  83c42c               add esp, 0x2c
// 008101dd  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?SetupScrollInfo@CXTPScrollBase@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPScrollBase.cpp
