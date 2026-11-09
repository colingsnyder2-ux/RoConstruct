// from server: 100% by auto
// roc 2008-06 00438030  unit: CPropertyGridItemBrickColor  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00438030
//
// 00438030  56                   push esi
// 00438031  8bf1                 mov esi, ecx
// 00438033  8b4604               mov eax, dword ptr [esi + 4]
// 00438036  57                   push edi
// 00438037  33ff                 xor edi, edi
// 00438039  3bc7                 cmp eax, edi
// 0043803b  7409                 je 0x438046
// 0043803d  8d4900               lea ecx, [ecx]
// 00438040  8b00                 mov eax, dword ptr [eax]
// 00438042  3bc7                 cmp eax, edi
// 00438044  75fa                 jne 0x438040
// 00438046  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00438049  897e0c               mov dword ptr [esi + 0xc], edi
// 0043804c  897e10               mov dword ptr [esi + 0x10], edi
// 0043804f  897e08               mov dword ptr [esi + 8], edi
// 00438052  897e04               mov dword ptr [esi + 4], edi
// 00438055  e8be902600           call 0x6a1118
// 0043805a  897e14               mov dword ptr [esi + 0x14], edi
// 0043805d  5f                   pop edi
// 0043805e  5e                   pop esi
// 0043805f  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ?RemoveAll@?$CList@KK@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
