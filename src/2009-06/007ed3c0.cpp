// from server: 100% by auto
// roc 2009-06 007ed3c0  unit: VCEdit::?$CXTMaskEditT  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ed3c0
//
// 007ed3c0  56                   push esi
// 007ed3c1  8bf1                 mov esi, ecx
// 007ed3c3  8b4620               mov eax, dword ptr [esi + 0x20]
// 007ed3c6  85c0                 test eax, eax
// 007ed3c8  7450                 je 0x7ed41a
// 007ed3ca  53                   push ebx
// 007ed3cb  57                   push edi
// 007ed3cc  8d7e58               lea edi, [esi + 0x58]
// 007ed3cf  57                   push edi
// 007ed3d0  8d5e54               lea ebx, [esi + 0x54]
// 007ed3d3  53                   push ebx
// 007ed3d4  68b0000000           push 0xb0
// 007ed3d9  50                   push eax
// 007ed3da  ff1590ee8900         call dword ptr [0x89ee90]
// 007ed3e0  8d8680000000         lea eax, [esi + 0x80]
// 007ed3e6  50                   push eax
// 007ed3e7  8bce                 mov ecx, esi
// 007ed3e9  e832bcf2ff           call 0x719020
// 007ed3ee  8bce                 mov ecx, esi
// 007ed3f0  e8fbeaffff           call 0x7ebef0
// 007ed3f5  837c241000           cmp dword ptr [esp + 0x10], 0
// 007ed3fa  741c                 je 0x7ed418
// 007ed3fc  6a01                 push 1
// 007ed3fe  53                   push ebx
// 007ed3ff  8bce                 mov ecx, esi
// 007ed401  e87afeffff           call 0x7ed280
// 007ed406  6a01                 push 1
// 007ed408  57                   push edi
// 007ed409  8bce                 mov ecx, esi
// 007ed40b  e870feffff           call 0x7ed280
// 007ed410  8b1b                 mov ebx, dword ptr [ebx]
// 007ed412  391f                 cmp dword ptr [edi], ebx
// 007ed414  7d02                 jge 0x7ed418
// 007ed416  891f                 mov dword ptr [edi], ebx
// 007ed418  5f                   pop edi
// 007ed419  5b                   pop ebx
// 007ed41a  5e                   pop esi
// 007ed41b  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTFlatComboBox.cpp (function ?GetMaskState@?$CXTPMaskEditT@VCEdit@@@@IAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTFlatComboBox.cpp
