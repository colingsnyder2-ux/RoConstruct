// from server: 100% by auto
// roc 2009-12 008c7f40  unit: VCEdit::?$CXTMaskEditT  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c7f40
//
// 008c7f40  56                   push esi
// 008c7f41  8bf1                 mov esi, ecx
// 008c7f43  8b4620               mov eax, dword ptr [esi + 0x20]
// 008c7f46  85c0                 test eax, eax
// 008c7f48  7450                 je 0x8c7f9a
// 008c7f4a  53                   push ebx
// 008c7f4b  57                   push edi
// 008c7f4c  8d7e58               lea edi, [esi + 0x58]
// 008c7f4f  57                   push edi
// 008c7f50  8d5e54               lea ebx, [esi + 0x54]
// 008c7f53  53                   push ebx
// 008c7f54  68b0000000           push 0xb0
// 008c7f59  50                   push eax
// 008c7f5a  ff15c4cb9800         call dword ptr [0x98cbc4]
// 008c7f60  8d8680000000         lea eax, [esi + 0x80]
// 008c7f66  50                   push eax
// 008c7f67  8bce                 mov ecx, esi
// 008c7f69  e8dabef2ff           call 0x7f3e48
// 008c7f6e  8bce                 mov ecx, esi
// 008c7f70  e80bebffff           call 0x8c6a80
// 008c7f75  837c241000           cmp dword ptr [esp + 0x10], 0
// 008c7f7a  741c                 je 0x8c7f98
// 008c7f7c  6a01                 push 1
// 008c7f7e  53                   push ebx
// 008c7f7f  8bce                 mov ecx, esi
// 008c7f81  e87afeffff           call 0x8c7e00
// 008c7f86  6a01                 push 1
// 008c7f88  57                   push edi
// 008c7f89  8bce                 mov ecx, esi
// 008c7f8b  e870feffff           call 0x8c7e00
// 008c7f90  8b1b                 mov ebx, dword ptr [ebx]
// 008c7f92  391f                 cmp dword ptr [edi], ebx
// 008c7f94  7d02                 jge 0x8c7f98
// 008c7f96  891f                 mov dword ptr [edi], ebx
// 008c7f98  5f                   pop edi
// 008c7f99  5b                   pop ebx
// 008c7f9a  5e                   pop esi
// 008c7f9b  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTFlatComboBox.cpp (function ?GetMaskState@?$CXTPMaskEditT@VCEdit@@@@IAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTFlatComboBox.cpp
