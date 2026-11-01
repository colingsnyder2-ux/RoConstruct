// from server: 100% by auto
// roc 2009-12 00867b90  unit: CXTPPropertyGridView  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00867b90
//
// 00867b90  56                   push esi
// 00867b91  8b742408             mov esi, dword ptr [esp + 8]
// 00867b95  57                   push edi
// 00867b96  8bf9                 mov edi, ecx
// 00867b98  85f6                 test esi, esi
// 00867b9a  7d05                 jge 0x867ba1
// 00867b9c  e86bbff8ff           call 0x7f3b0c
// 00867ba1  3b7708               cmp esi, dword ptr [edi + 8]
// 00867ba4  7c0b                 jl 0x867bb1
// 00867ba6  6aff                 push -1
// 00867ba8  8d4601               lea eax, [esi + 1]
// 00867bab  50                   push eax
// 00867bac  e87ffeffff           call 0x867a30
// 00867bb1  8b5704               mov edx, dword ptr [edi + 4]
// 00867bb4  8d0cb6               lea ecx, [esi + esi*4]
// 00867bb7  8d048a               lea eax, [edx + ecx*4]
// 00867bba  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00867bbe  8b11                 mov edx, dword ptr [ecx]
// 00867bc0  8910                 mov dword ptr [eax], edx
// 00867bc2  8b5104               mov edx, dword ptr [ecx + 4]
// 00867bc5  895004               mov dword ptr [eax + 4], edx
// 00867bc8  8b5108               mov edx, dword ptr [ecx + 8]
// 00867bcb  895008               mov dword ptr [eax + 8], edx
// 00867bce  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00867bd1  89500c               mov dword ptr [eax + 0xc], edx
// 00867bd4  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 00867bd7  5f                   pop edi
// 00867bd8  894810               mov dword ptr [eax + 0x10], ecx
// 00867bdb  5e                   pop esi
// 00867bdc  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?SetAtGrow@?$CArray@UWNDRECT@CXTPPropertyGridView@@AAU12@@@QAEXHAAUWNDRECT@CXTPPropertyGridView@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
