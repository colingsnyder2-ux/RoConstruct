// from server: 100% by auto
// roc 2009-06 0077f3a0  unit: CXTThemeManagerStyleHost  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077f3a0
//
// 0077f3a0  56                   push esi
// 0077f3a1  8bf1                 mov esi, ecx
// 0077f3a3  6a0a                 push 0xa
// 0077f3a5  8d4e04               lea ecx, [esi + 4]
// 0077f3a8  c70620cd8f00         mov dword ptr [esi], 0x8fcd20
// 0077f3ae  e8d7d10c00           call 0x84c58a
// 0077f3b3  33c0                 xor eax, eax
// 0077f3b5  894624               mov dword ptr [esi + 0x24], eax
// 0077f3b8  894620               mov dword ptr [esi + 0x20], eax
// 0077f3bb  c7462810000000       mov dword ptr [esi + 0x28], 0x10
// 0077f3c2  8bc6                 mov eax, esi
// 0077f3c4  5e                   pop esi
// 0077f3c5  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ??0CXTThemeManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
