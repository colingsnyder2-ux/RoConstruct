// from server: 100% by auto
// roc 2010-06 0081bba0  unit: CXTPPropertyGridView  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081bba0
//
// 0081bba0  56                   push esi
// 0081bba1  8b742408             mov esi, dword ptr [esp + 8]
// 0081bba5  57                   push edi
// 0081bba6  8bf9                 mov edi, ecx
// 0081bba8  85f6                 test esi, esi
// 0081bbaa  7d05                 jge 0x81bbb1
// 0081bbac  e89bc0f8ff           call 0x7a7c4c
// 0081bbb1  3b7708               cmp esi, dword ptr [edi + 8]
// 0081bbb4  7c0b                 jl 0x81bbc1
// 0081bbb6  6aff                 push -1
// 0081bbb8  8d4601               lea eax, [esi + 1]
// 0081bbbb  50                   push eax
// 0081bbbc  e87ffeffff           call 0x81ba40
// 0081bbc1  8b5704               mov edx, dword ptr [edi + 4]
// 0081bbc4  8d0cb6               lea ecx, [esi + esi*4]
// 0081bbc7  8d048a               lea eax, [edx + ecx*4]
// 0081bbca  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0081bbce  8b11                 mov edx, dword ptr [ecx]
// 0081bbd0  8910                 mov dword ptr [eax], edx
// 0081bbd2  8b5104               mov edx, dword ptr [ecx + 4]
// 0081bbd5  895004               mov dword ptr [eax + 4], edx
// 0081bbd8  8b5108               mov edx, dword ptr [ecx + 8]
// 0081bbdb  895008               mov dword ptr [eax + 8], edx
// 0081bbde  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0081bbe1  89500c               mov dword ptr [eax + 0xc], edx
// 0081bbe4  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 0081bbe7  5f                   pop edi
// 0081bbe8  894810               mov dword ptr [eax + 0x10], ecx
// 0081bbeb  5e                   pop esi
// 0081bbec  c20800               ret 8
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?SetAtGrow@?$CArray@UWNDRECT@CXTPPropertyGridView@@AAU12@@@QAEXHAAUWNDRECT@CXTPPropertyGridView@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
