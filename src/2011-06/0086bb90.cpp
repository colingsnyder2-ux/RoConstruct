// from server: 100% by auto
// roc 2011-06 0086bb90  unit: CXTThemeManagerStyleHost  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086bb90
//
// 0086bb90  56                   push esi
// 0086bb91  8bf1                 mov esi, ecx
// 0086bb93  6a0a                 push 0xa
// 0086bb95  8d4e04               lea ecx, [esi + 4]
// 0086bb98  c70668bdac00         mov dword ptr [esi], 0xacbd68
// 0086bb9e  e8370f1600           call 0x9ccada
// 0086bba3  33c0                 xor eax, eax
// 0086bba5  894624               mov dword ptr [esi + 0x24], eax
// 0086bba8  894620               mov dword ptr [esi + 0x20], eax
// 0086bbab  c7462810000000       mov dword ptr [esi + 0x28], 0x10
// 0086bbb2  8bc6                 mov eax, esi
// 0086bbb4  5e                   pop esi
// 0086bbb5  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ??0CXTThemeManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
