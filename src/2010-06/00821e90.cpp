// from server: 100% by auto
// roc 2010-06 00821e90  unit: CSelectionCaption  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00821e90
//
// 00821e90  56                   push esi
// 00821e91  8bf1                 mov esi, ecx
// 00821e93  f686c800000004       test byte ptr [esi + 0xc8], 4
// 00821e9a  7441                 je 0x821edd
// 00821e9c  8b4638               mov eax, dword ptr [esi + 0x38]
// 00821e9f  57                   push edi
// 00821ea0  85c0                 test eax, eax
// 00821ea2  750a                 jne 0x821eae
// 00821ea4  8b4620               mov eax, dword ptr [esi + 0x20]
// 00821ea7  50                   push eax
// 00821ea8  ff154cba9e00         call dword ptr [0x9eba4c]
// 00821eae  50                   push eax
// 00821eaf  e8b65df8ff           call 0x7a7c6a
// 00821eb4  8bf8                 mov edi, eax
// 00821eb6  85ff                 test edi, edi
// 00821eb8  7420                 je 0x821eda
// 00821eba  53                   push ebx
// 00821ebb  8b5e20               mov ebx, dword ptr [esi + 0x20]
// 00821ebe  8bce                 mov ecx, esi
// 00821ec0  e841b11500           call 0x97d006
// 00821ec5  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 00821ec8  0fb7c0               movzx eax, ax
// 00821ecb  53                   push ebx
// 00821ecc  50                   push eax
// 00821ecd  6811010000           push 0x111
// 00821ed2  51                   push ecx
// 00821ed3  ff1554ba9e00         call dword ptr [0x9eba54]
// 00821ed9  5b                   pop ebx
// 00821eda  5f                   pop edi
// 00821edb  5e                   pop esi
// 00821edc  c3                   ret 
// 00821edd  8b16                 mov edx, dword ptr [esi]
// 00821edf  8b825c010000         mov eax, dword ptr [edx + 0x15c]
// 00821ee5  5e                   pop esi
// 00821ee6  ffe0                 jmp eax
// library xtp-13.2.1-shared-mfc/Source\Controls\XTCaption.cpp (function ?OnCaptButton@CXTCaption@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTCaption.cpp
