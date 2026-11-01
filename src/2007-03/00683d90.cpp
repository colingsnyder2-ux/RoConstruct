// from server: 100% by auto
// roc 2007-03 00683d90  unit: seg_00680000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00683d90
//
// 00683d90  8b01                 mov eax, dword ptr [ecx]
// 00683d92  8b405c               mov eax, dword ptr [eax + 0x5c]
// 00683d95  83ec10               sub esp, 0x10
// 00683d98  8d1424               lea edx, [esp]
// 00683d9b  52                   push edx
// 00683d9c  ffd0                 call eax
// 00683d9e  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00683da2  8b542414             mov edx, dword ptr [esp + 0x14]
// 00683da6  51                   push ecx
// 00683da7  52                   push edx
// 00683da8  8d442408             lea eax, [esp + 8]
// 00683dac  50                   push eax
// 00683dad  ff1598ed7700         call dword ptr [0x77ed98]
// 00683db3  83c410               add esp, 0x10
// 00683db6  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?PtInValueRect@CXTPPropertyGridItem@@IAEHVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
