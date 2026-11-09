// from server: 100% by auto
// roc 2010-06 00803780  unit: CXTPPropertyGrid  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00803780
//
// 00803780  8b4138               mov eax, dword ptr [ecx + 0x38]
// 00803783  85c0                 test eax, eax
// 00803785  750a                 jne 0x803791
// 00803787  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0080378a  50                   push eax
// 0080378b  ff154cba9e00         call dword ptr [0x9eba4c]
// 00803791  50                   push eax
// 00803792  e8d344faff           call 0x7a7c6a
// 00803797  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0080379b  8b542404             mov edx, dword ptr [esp + 4]
// 0080379f  8b4020               mov eax, dword ptr [eax + 0x20]
// 008037a2  51                   push ecx
// 008037a3  52                   push edx
// 008037a4  68df2a0000           push 0x2adf
// 008037a9  50                   push eax
// 008037aa  ff1554ba9e00         call dword ptr [0x9eba54]
// 008037b0  c20800               ret 8
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?SendNotifyMessageA@CXTPPropertyGrid@@UAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
