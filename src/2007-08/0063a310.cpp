// from server: 100% by auto
// roc 2007-08 0063a310  unit: CPatchedControlComboBox  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0063a310
//
// 0063a310  56                   push esi
// 0063a311  8b742408             mov esi, dword ptr [esp + 8]
// 0063a315  85f6                 test esi, esi
// 0063a317  7509                 jne 0x63a322
// 0063a319  b857000780           mov eax, 0x80070057
// 0063a31e  5e                   pop esi
// 0063a31f  c20400               ret 4
// 0063a322  8b41e0               mov eax, dword ptr [ecx - 0x20]
// 0063a325  8b908c000000         mov edx, dword ptr [eax + 0x8c]
// 0063a32b  83c1e0               add ecx, -0x20
// 0063a32e  ffd2                 call edx
// 0063a330  f7d8                 neg eax
// 0063a332  1bc0                 sbb eax, eax
// 0063a334  f7d8                 neg eax
// 0063a336  8906                 mov dword ptr [esi], eax
// 0063a338  33c0                 xor eax, eax
// 0063a33a  5e                   pop esi
// 0063a33b  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ?GetAccessibleChildCount@CXTPControl@@MAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
