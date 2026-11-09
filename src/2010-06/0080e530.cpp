// from server: 100% by auto
// roc 2010-06 0080e530  unit: CXTThemeManager  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080e530
//
// 0080e530  33c0                 xor eax, eax
// 0080e532  56                   push esi
// 0080e533  8bf1                 mov esi, ecx
// 0080e535  c7069014a600         mov dword ptr [esi], 0xa61490
// 0080e53b  894604               mov dword ptr [esi + 4], eax
// 0080e53e  894608               mov dword ptr [esi + 8], eax
// 0080e541  89460c               mov dword ptr [esi + 0xc], eax
// 0080e544  894610               mov dword ptr [esi + 0x10], eax
// 0080e547  e8c4ffffff           call 0x80e510
// 0080e54c  83c024               add eax, 0x24
// 0080e54f  56                   push esi
// 0080e550  8bc8                 mov ecx, eax
// 0080e552  e8c3ee1600           call 0x97d41a
// 0080e557  c7460c14000000       mov dword ptr [esi + 0xc], 0x14
// 0080e55e  8bc6                 mov eax, esi
// 0080e560  5e                   pop esi
// 0080e561  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ??0CXTThemeManagerStyleFactory@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
