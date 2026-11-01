// from server: 100% by auto
// roc 2009-06 007749c0  unit: CXTPPropertyGrid  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007749c0
//
// 007749c0  8b4138               mov eax, dword ptr [ecx + 0x38]
// 007749c3  85c0                 test eax, eax
// 007749c5  750a                 jne 0x7749d1
// 007749c7  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007749ca  50                   push eax
// 007749cb  ff1598ee8900         call dword ptr [0x89ee98]
// 007749d1  50                   push eax
// 007749d2  e82b43faff           call 0x718d02
// 007749d7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007749db  8b542404             mov edx, dword ptr [esp + 4]
// 007749df  8b4020               mov eax, dword ptr [eax + 0x20]
// 007749e2  51                   push ecx
// 007749e3  52                   push edx
// 007749e4  68df2a0000           push 0x2adf
// 007749e9  50                   push eax
// 007749ea  ff1590ee8900         call dword ptr [0x89ee90]
// 007749f0  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?SendNotifyMessageA@CXTPPropertyGrid@@UAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
