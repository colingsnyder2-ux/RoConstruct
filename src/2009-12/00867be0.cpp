// from server: 100% by auto
// roc 2009-12 00867be0  unit: CXTPPropertyGridView  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00867be0
//
// 00867be0  56                   push esi
// 00867be1  8bf1                 mov esi, ecx
// 00867be3  e860c5f8ff           call 0x7f4148
// 00867be8  33c0                 xor eax, eax
// 00867bea  c70664ef9f00         mov dword ptr [esi], 0x9fef64
// 00867bf0  89465c               mov dword ptr [esi + 0x5c], eax
// 00867bf3  c7465898019b00       mov dword ptr [esi + 0x58], 0x9b0198
// 00867bfa  894654               mov dword ptr [esi + 0x54], eax
// 00867bfd  8bc6                 mov eax, esi
// 00867bff  5e                   pop esi
// 00867c00  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ??0CXTPPropertyGridToolTip@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
