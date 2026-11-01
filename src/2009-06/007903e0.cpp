// from server: 100% by auto
// roc 2009-06 007903e0  unit: CXTPPropertyGridItemBool  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007903e0
//
// 007903e0  83ec10               sub esp, 0x10
// 007903e3  8b01                 mov eax, dword ptr [ecx]
// 007903e5  8b405c               mov eax, dword ptr [eax + 0x5c]
// 007903e8  8d1424               lea edx, [esp]
// 007903eb  52                   push edx
// 007903ec  ffd0                 call eax
// 007903ee  8b0c24               mov ecx, dword ptr [esp]
// 007903f1  8b542418             mov edx, dword ptr [esp + 0x18]
// 007903f5  8b442414             mov eax, dword ptr [esp + 0x14]
// 007903f9  83c10f               add ecx, 0xf
// 007903fc  52                   push edx
// 007903fd  894c240c             mov dword ptr [esp + 0xc], ecx
// 00790401  50                   push eax
// 00790402  8d4c2408             lea ecx, [esp + 8]
// 00790406  51                   push ecx
// 00790407  ff15c0ed8900         call dword ptr [0x89edc0]
// 0079040d  83c410               add esp, 0x10
// 00790410  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItemBool.cpp (function ?PtInCheckBoxRect@CXTPPropertyGridItemBool@@IAEHVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItemBool.cpp
