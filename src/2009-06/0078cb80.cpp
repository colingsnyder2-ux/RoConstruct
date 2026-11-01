// from server: 100% by auto
// roc 2009-06 0078cb80  unit: CXTPPropertyGridView  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078cb80
//
// 0078cb80  56                   push esi
// 0078cb81  8b742408             mov esi, dword ptr [esp + 8]
// 0078cb85  57                   push edi
// 0078cb86  8bf9                 mov edi, ecx
// 0078cb88  85f6                 test esi, esi
// 0078cb8a  7d05                 jge 0x78cb91
// 0078cb8c  e853c1f8ff           call 0x718ce4
// 0078cb91  3b7708               cmp esi, dword ptr [edi + 8]
// 0078cb94  7c0b                 jl 0x78cba1
// 0078cb96  6aff                 push -1
// 0078cb98  8d4601               lea eax, [esi + 1]
// 0078cb9b  50                   push eax
// 0078cb9c  e87ffeffff           call 0x78ca20
// 0078cba1  8b5704               mov edx, dword ptr [edi + 4]
// 0078cba4  8d0cb6               lea ecx, [esi + esi*4]
// 0078cba7  8d048a               lea eax, [edx + ecx*4]
// 0078cbaa  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0078cbae  8b11                 mov edx, dword ptr [ecx]
// 0078cbb0  8910                 mov dword ptr [eax], edx
// 0078cbb2  8b5104               mov edx, dword ptr [ecx + 4]
// 0078cbb5  895004               mov dword ptr [eax + 4], edx
// 0078cbb8  8b5108               mov edx, dword ptr [ecx + 8]
// 0078cbbb  895008               mov dword ptr [eax + 8], edx
// 0078cbbe  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0078cbc1  89500c               mov dword ptr [eax + 0xc], edx
// 0078cbc4  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 0078cbc7  5f                   pop edi
// 0078cbc8  894810               mov dword ptr [eax + 0x10], ecx
// 0078cbcb  5e                   pop esi
// 0078cbcc  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?SetAtGrow@?$CArray@UWNDRECT@CXTPPropertyGridView@@AAU12@@@QAEXHAAUWNDRECT@CXTPPropertyGridView@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
