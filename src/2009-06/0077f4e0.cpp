// from server: 100% by auto
// roc 2009-06 0077f4e0  unit: CXTThemeManager  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077f4e0
//
// 0077f4e0  33c0                 xor eax, eax
// 0077f4e2  56                   push esi
// 0077f4e3  8bf1                 mov esi, ecx
// 0077f4e5  c70628cd8f00         mov dword ptr [esi], 0x8fcd28
// 0077f4eb  894604               mov dword ptr [esi + 4], eax
// 0077f4ee  894608               mov dword ptr [esi + 8], eax
// 0077f4f1  89460c               mov dword ptr [esi + 0xc], eax
// 0077f4f4  894610               mov dword ptr [esi + 0x10], eax
// 0077f4f7  e8c4ffffff           call 0x77f4c0
// 0077f4fc  83c024               add eax, 0x24
// 0077f4ff  56                   push esi
// 0077f500  8bc8                 mov ecx, eax
// 0077f502  e865d00c00           call 0x84c56c
// 0077f507  c7460c14000000       mov dword ptr [esi + 0xc], 0x14
// 0077f50e  8bc6                 mov eax, esi
// 0077f510  5e                   pop esi
// 0077f511  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTThemeManager.cpp (function ??0CXTThemeManagerStyleFactory@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTThemeManager.cpp
