// from server: 100% by auto
// roc 2009-06 0078a520  unit: CXTPPropertyGridItem  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078a520
//
// 0078a520  8b01                 mov eax, dword ptr [ecx]
// 0078a522  8b405c               mov eax, dword ptr [eax + 0x5c]
// 0078a525  83ec10               sub esp, 0x10
// 0078a528  8d1424               lea edx, [esp]
// 0078a52b  52                   push edx
// 0078a52c  ffd0                 call eax
// 0078a52e  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0078a532  8b542414             mov edx, dword ptr [esp + 0x14]
// 0078a536  51                   push ecx
// 0078a537  52                   push edx
// 0078a538  8d442408             lea eax, [esp + 8]
// 0078a53c  50                   push eax
// 0078a53d  ff15c0ed8900         call dword ptr [0x89edc0]
// 0078a543  83c410               add esp, 0x10
// 0078a546  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?PtInValueRect@CXTPPropertyGridItem@@IAEHVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
