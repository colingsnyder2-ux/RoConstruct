// from server: 100% by auto
// roc 2010-06 0081dbf0  unit: CXTPPropertyGridView  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081dbf0
//
// 0081dbf0  56                   push esi
// 0081dbf1  8b742408             mov esi, dword ptr [esp + 8]
// 0081dbf5  85f6                 test esi, esi
// 0081dbf7  7509                 jne 0x81dc02
// 0081dbf9  b857000780           mov eax, 0x80070057
// 0081dbfe  5e                   pop esi
// 0081dbff  c20400               ret 4
// 0081dc02  8b41cc               mov eax, dword ptr [ecx - 0x34]
// 0081dc05  6a00                 push 0
// 0081dc07  6a00                 push 0
// 0081dc09  688b010000           push 0x18b
// 0081dc0e  50                   push eax
// 0081dc0f  ff1554ba9e00         call dword ptr [0x9eba54]
// 0081dc15  8906                 mov dword ptr [esi], eax
// 0081dc17  33c0                 xor eax, eax
// 0081dc19  5e                   pop esi
// 0081dc1a  c20400               ret 4
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleChildCount@CXTPPropertyGridView@@MAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
