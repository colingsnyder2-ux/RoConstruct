// from server: 100% by auto
// roc 2009-06 0071fc10  unit: CPatchedControlComboBox  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071fc10
//
// 0071fc10  56                   push esi
// 0071fc11  8b742408             mov esi, dword ptr [esp + 8]
// 0071fc15  85f6                 test esi, esi
// 0071fc17  7509                 jne 0x71fc22
// 0071fc19  b857000780           mov eax, 0x80070057
// 0071fc1e  5e                   pop esi
// 0071fc1f  c20400               ret 4
// 0071fc22  8b41e0               mov eax, dword ptr [ecx - 0x20]
// 0071fc25  8b908c000000         mov edx, dword ptr [eax + 0x8c]
// 0071fc2b  83c1e0               add ecx, -0x20
// 0071fc2e  ffd2                 call edx
// 0071fc30  f7d8                 neg eax
// 0071fc32  1bc0                 sbb eax, eax
// 0071fc34  f7d8                 neg eax
// 0071fc36  8906                 mov dword ptr [esi], eax
// 0071fc38  33c0                 xor eax, eax
// 0071fc3a  5e                   pop esi
// 0071fc3b  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ?GetAccessibleChildCount@CXTPControl@@MAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
