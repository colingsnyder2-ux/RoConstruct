// from server: 100% by auto
// roc 2007-03 0067b8b0  unit: seg_00670000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067b8b0
//
// 0067b8b0  56                   push esi
// 0067b8b1  8bf1                 mov esi, ecx
// 0067b8b3  6a0a                 push 0xa
// 0067b8b5  8d4e04               lea ecx, [esi + 4]
// 0067b8b8  c706c0d47c00         mov dword ptr [esi], 0x7cd4c0
// 0067b8be  e8c1f90b00           call 0x73b284
// 0067b8c3  33c0                 xor eax, eax
// 0067b8c5  894624               mov dword ptr [esi + 0x24], eax
// 0067b8c8  894620               mov dword ptr [esi + 0x20], eax
// 0067b8cb  c7462810000000       mov dword ptr [esi + 0x28], 0x10
// 0067b8d2  8bc6                 mov eax, esi
// 0067b8d4  5e                   pop esi
// 0067b8d5  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ??0CXTThemeManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
