// from server: 100% by auto
// roc 2010-06 0080e3f0  unit: CXTThemeManagerStyleHost  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080e3f0
//
// 0080e3f0  56                   push esi
// 0080e3f1  8bf1                 mov esi, ecx
// 0080e3f3  6a0a                 push 0xa
// 0080e3f5  8d4e04               lea ecx, [esi + 4]
// 0080e3f8  c7068814a600         mov dword ptr [esi], 0xa61488
// 0080e3fe  e835f01600           call 0x97d438
// 0080e403  33c0                 xor eax, eax
// 0080e405  894624               mov dword ptr [esi + 0x24], eax
// 0080e408  894620               mov dword ptr [esi + 0x20], eax
// 0080e40b  c7462810000000       mov dword ptr [esi + 0x28], 0x10
// 0080e412  8bc6                 mov eax, esi
// 0080e414  5e                   pop esi
// 0080e415  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ??0CXTThemeManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
