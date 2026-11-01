// from server: 100% by auto
// roc 2007-03 0065e020  unit: seg_00650000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065e020
//
// 0065e020  8b4138               mov eax, dword ptr [ecx + 0x38]
// 0065e023  85c0                 test eax, eax
// 0065e025  750a                 jne 0x65e031
// 0065e027  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0065e02a  50                   push eax
// 0065e02b  ff15c8ec7700         call dword ptr [0x77ecc8]
// 0065e031  50                   push eax
// 0065e032  e81706fcff           call 0x61e64e
// 0065e037  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0065e03b  8b542404             mov edx, dword ptr [esp + 4]
// 0065e03f  8b4020               mov eax, dword ptr [eax + 0x20]
// 0065e042  51                   push ecx
// 0065e043  52                   push edx
// 0065e044  68df2a0000           push 0x2adf
// 0065e049  50                   push eax
// 0065e04a  ff1550ee7700         call dword ptr [0x77ee50]
// 0065e050  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?SendNotifyMessageA@CXTPPropertyGrid@@UAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
