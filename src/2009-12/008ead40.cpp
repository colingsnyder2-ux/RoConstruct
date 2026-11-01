// from server: 100% by auto
// roc 2009-12 008ead40  unit: CXTPScrollBase  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ead40
//
// 008ead40  83ec2c               sub esp, 0x2c
// 008ead43  56                   push esi
// 008ead44  8bf1                 mov esi, ecx
// 008ead46  8b06                 mov eax, dword ptr [esi]
// 008ead48  8b5010               mov edx, dword ptr [eax + 0x10]
// 008ead4b  8d4c2404             lea ecx, [esp + 4]
// 008ead4f  51                   push ecx
// 008ead50  8bce                 mov ecx, esi
// 008ead52  ffd2                 call edx
// 008ead54  8b06                 mov eax, dword ptr [esi]
// 008ead56  8b5014               mov edx, dword ptr [eax + 0x14]
// 008ead59  8d4c2414             lea ecx, [esp + 0x14]
// 008ead5d  51                   push ecx
// 008ead5e  8bce                 mov ecx, esi
// 008ead60  ffd2                 call edx
// 008ead62  8b06                 mov eax, dword ptr [esi]
// 008ead64  8d4c2414             lea ecx, [esp + 0x14]
// 008ead68  51                   push ecx
// 008ead69  8d5604               lea edx, [esi + 4]
// 008ead6c  52                   push edx
// 008ead6d  8b5020               mov edx, dword ptr [eax + 0x20]
// 008ead70  8d4c240c             lea ecx, [esp + 0xc]
// 008ead74  51                   push ecx
// 008ead75  8bce                 mov ecx, esi
// 008ead77  ffd2                 call edx
// 008ead79  5e                   pop esi
// 008ead7a  83c42c               add esp, 0x2c
// 008ead7d  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?SetupScrollInfo@CXTPScrollBase@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPScrollBase.cpp
