// from server: 100% by auto
// roc 2010-06 0087c0e0  unit: VCEdit::?$CXTMaskEditT  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0087c0e0
//
// 0087c0e0  56                   push esi
// 0087c0e1  8bf1                 mov esi, ecx
// 0087c0e3  8b4620               mov eax, dword ptr [esi + 0x20]
// 0087c0e6  85c0                 test eax, eax
// 0087c0e8  7450                 je 0x87c13a
// 0087c0ea  53                   push ebx
// 0087c0eb  57                   push edi
// 0087c0ec  8d7e58               lea edi, [esi + 0x58]
// 0087c0ef  57                   push edi
// 0087c0f0  8d5e54               lea ebx, [esi + 0x54]
// 0087c0f3  53                   push ebx
// 0087c0f4  68b0000000           push 0xb0
// 0087c0f9  50                   push eax
// 0087c0fa  ff1554ba9e00         call dword ptr [0x9eba54]
// 0087c100  8d8680000000         lea eax, [esi + 0x80]
// 0087c106  50                   push eax
// 0087c107  8bce                 mov ecx, esi
// 0087c109  e87abef2ff           call 0x7a7f88
// 0087c10e  8bce                 mov ecx, esi
// 0087c110  e80bebffff           call 0x87ac20
// 0087c115  837c241000           cmp dword ptr [esp + 0x10], 0
// 0087c11a  741c                 je 0x87c138
// 0087c11c  6a01                 push 1
// 0087c11e  53                   push ebx
// 0087c11f  8bce                 mov ecx, esi
// 0087c121  e87afeffff           call 0x87bfa0
// 0087c126  6a01                 push 1
// 0087c128  57                   push edi
// 0087c129  8bce                 mov ecx, esi
// 0087c12b  e870feffff           call 0x87bfa0
// 0087c130  8b1b                 mov ebx, dword ptr [ebx]
// 0087c132  391f                 cmp dword ptr [edi], ebx
// 0087c134  7d02                 jge 0x87c138
// 0087c136  891f                 mov dword ptr [edi], ebx
// 0087c138  5f                   pop edi
// 0087c139  5b                   pop ebx
// 0087c13a  5e                   pop esi
// 0087c13b  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTBrowseEdit.cpp (function ?GetMaskState@?$CXTMaskEditT@VCEdit@@@@IAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTBrowseEdit.cpp
