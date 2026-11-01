// from server: 100% by auto
// roc 2009-12 0086b400  unit: CXTPPropertyGridItemBool  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086b400
//
// 0086b400  83ec10               sub esp, 0x10
// 0086b403  8b01                 mov eax, dword ptr [ecx]
// 0086b405  8b405c               mov eax, dword ptr [eax + 0x5c]
// 0086b408  8d1424               lea edx, [esp]
// 0086b40b  52                   push edx
// 0086b40c  ffd0                 call eax
// 0086b40e  8b0c24               mov ecx, dword ptr [esp]
// 0086b411  8b542418             mov edx, dword ptr [esp + 0x18]
// 0086b415  8b442414             mov eax, dword ptr [esp + 0x14]
// 0086b419  83c10f               add ecx, 0xf
// 0086b41c  52                   push edx
// 0086b41d  894c240c             mov dword ptr [esp + 0xc], ecx
// 0086b421  50                   push eax
// 0086b422  8d4c2408             lea ecx, [esp + 8]
// 0086b426  51                   push ecx
// 0086b427  ff155cca9800         call dword ptr [0x98ca5c]
// 0086b42d  83c410               add esp, 0x10
// 0086b430  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItemBool.cpp (function ?PtInCheckBoxRect@CXTPPropertyGridItemBool@@IAEHVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItemBool.cpp
