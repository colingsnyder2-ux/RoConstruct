// from server: 100% by auto
// roc 2007-08 00698970  unit: CXTPPropertyGridItem  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00698970
//
// 00698970  8b01                 mov eax, dword ptr [ecx]
// 00698972  8b405c               mov eax, dword ptr [eax + 0x5c]
// 00698975  83ec10               sub esp, 0x10
// 00698978  8d1424               lea edx, [esp]
// 0069897b  52                   push edx
// 0069897c  ffd0                 call eax
// 0069897e  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00698982  8b542414             mov edx, dword ptr [esp + 0x14]
// 00698986  51                   push ecx
// 00698987  52                   push edx
// 00698988  8d442408             lea eax, [esp + 8]
// 0069898c  50                   push eax
// 0069898d  ff1594ed7700         call dword ptr [0x77ed94]
// 00698993  83c410               add esp, 0x10
// 00698996  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?PtInValueRect@CXTPPropertyGridItem@@IAEHVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
