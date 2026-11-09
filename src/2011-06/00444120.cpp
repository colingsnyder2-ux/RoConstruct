// from server: 100% by auto
// roc 2011-06 00444120  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00444120
//
// 00444120  56                   push esi
// 00444121  8bf1                 mov esi, ecx
// 00444123  8b4604               mov eax, dword ptr [esi + 4]
// 00444126  57                   push edi
// 00444127  33ff                 xor edi, edi
// 00444129  3bc7                 cmp eax, edi
// 0044412b  7409                 je 0x444136
// 0044412d  8d4900               lea ecx, [ecx]
// 00444130  8b00                 mov eax, dword ptr [eax]
// 00444132  3bc7                 cmp eax, edi
// 00444134  75fa                 jne 0x444130
// 00444136  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00444139  897e0c               mov dword ptr [esi + 0xc], edi
// 0044413c  897e10               mov dword ptr [esi + 0x10], edi
// 0044413f  897e08               mov dword ptr [esi + 8], edi
// 00444142  897e04               mov dword ptr [esi + 4], edi
// 00444145  e87e6a3c00           call 0x80abc8
// 0044414a  897e14               mov dword ptr [esi + 0x14], edi
// 0044414d  5f                   pop edi
// 0044414e  5e                   pop esi
// 0044414f  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ?RemoveAll@?$CList@KK@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
