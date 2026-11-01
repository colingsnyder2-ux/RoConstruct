// from server: 100% by auto
// roc 2009-12 0085a5a0  unit: CXTThemeManager  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085a5a0
//
// 0085a5a0  33c0                 xor eax, eax
// 0085a5a2  56                   push esi
// 0085a5a3  8bf1                 mov esi, ecx
// 0085a5a5  c706d0d19f00         mov dword ptr [esi], 0x9fd1d0
// 0085a5ab  894604               mov dword ptr [esi + 4], eax
// 0085a5ae  894608               mov dword ptr [esi + 8], eax
// 0085a5b1  89460c               mov dword ptr [esi + 0xc], eax
// 0085a5b4  894610               mov dword ptr [esi + 0x10], eax
// 0085a5b7  e8c4ffffff           call 0x85a580
// 0085a5bc  83c024               add eax, 0x24
// 0085a5bf  56                   push esi
// 0085a5c0  8bc8                 mov ecx, eax
// 0085a5c2  e811c50c00           call 0x926ad8
// 0085a5c7  c7460c14000000       mov dword ptr [esi + 0xc], 0x14
// 0085a5ce  8bc6                 mov eax, esi
// 0085a5d0  5e                   pop esi
// 0085a5d1  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTThemeManager.cpp (function ??0CXTThemeManagerStyleFactory@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTThemeManager.cpp
