// from server: 100% by auto
// roc 2009-12 007f6230  unit: CPatchedControlComboBox  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f6230
//
// 007f6230  56                   push esi
// 007f6231  8b742408             mov esi, dword ptr [esp + 8]
// 007f6235  85f6                 test esi, esi
// 007f6237  7509                 jne 0x7f6242
// 007f6239  b857000780           mov eax, 0x80070057
// 007f623e  5e                   pop esi
// 007f623f  c20400               ret 4
// 007f6242  8b41e0               mov eax, dword ptr [ecx - 0x20]
// 007f6245  8b908c000000         mov edx, dword ptr [eax + 0x8c]
// 007f624b  83c1e0               add ecx, -0x20
// 007f624e  ffd2                 call edx
// 007f6250  f7d8                 neg eax
// 007f6252  1bc0                 sbb eax, eax
// 007f6254  f7d8                 neg eax
// 007f6256  8906                 mov dword ptr [esi], eax
// 007f6258  33c0                 xor eax, eax
// 007f625a  5e                   pop esi
// 007f625b  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ?GetAccessibleChildCount@CXTPControl@@MAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
