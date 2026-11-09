// from server: 100% by auto
// roc 2009-12 0085a460  unit: CXTThemeManagerStyleHost  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085a460
//
// 0085a460  56                   push esi
// 0085a461  8bf1                 mov esi, ecx
// 0085a463  6a0a                 push 0xa
// 0085a465  8d4e04               lea ecx, [esi + 4]
// 0085a468  c706c8d19f00         mov dword ptr [esi], 0x9fd1c8
// 0085a46e  e883c60c00           call 0x926af6
// 0085a473  33c0                 xor eax, eax
// 0085a475  894624               mov dword ptr [esi + 0x24], eax
// 0085a478  894620               mov dword ptr [esi + 0x20], eax
// 0085a47b  c7462810000000       mov dword ptr [esi + 0x28], 0x10
// 0085a482  8bc6                 mov eax, esi
// 0085a484  5e                   pop esi
// 0085a485  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ??0CXTThemeManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
