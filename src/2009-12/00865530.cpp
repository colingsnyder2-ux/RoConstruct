// from server: 100% by auto
// roc 2009-12 00865530  unit: CXTPPropertyGridItem  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00865530
//
// 00865530  8b01                 mov eax, dword ptr [ecx]
// 00865532  8b405c               mov eax, dword ptr [eax + 0x5c]
// 00865535  83ec10               sub esp, 0x10
// 00865538  8d1424               lea edx, [esp]
// 0086553b  52                   push edx
// 0086553c  ffd0                 call eax
// 0086553e  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00865542  8b542414             mov edx, dword ptr [esp + 0x14]
// 00865546  51                   push ecx
// 00865547  52                   push edx
// 00865548  8d442408             lea eax, [esp + 8]
// 0086554c  50                   push eax
// 0086554d  ff155cca9800         call dword ptr [0x98ca5c]
// 00865553  83c410               add esp, 0x10
// 00865556  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?PtInValueRect@CXTPPropertyGridItem@@IAEHVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
