// from server: 100% by auto
// roc 2007-08 0069e490  unit: CXTPPropertyGridItemBool  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0069e490
//
// 0069e490  83ec10               sub esp, 0x10
// 0069e493  8b01                 mov eax, dword ptr [ecx]
// 0069e495  8b405c               mov eax, dword ptr [eax + 0x5c]
// 0069e498  8d1424               lea edx, [esp]
// 0069e49b  52                   push edx
// 0069e49c  ffd0                 call eax
// 0069e49e  8b0c24               mov ecx, dword ptr [esp]
// 0069e4a1  8b542418             mov edx, dword ptr [esp + 0x18]
// 0069e4a5  8b442414             mov eax, dword ptr [esp + 0x14]
// 0069e4a9  83c10f               add ecx, 0xf
// 0069e4ac  52                   push edx
// 0069e4ad  894c240c             mov dword ptr [esp + 0xc], ecx
// 0069e4b1  50                   push eax
// 0069e4b2  8d4c2408             lea ecx, [esp + 8]
// 0069e4b6  51                   push ecx
// 0069e4b7  ff1594ed7700         call dword ptr [0x77ed94]
// 0069e4bd  83c410               add esp, 0x10
// 0069e4c0  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItemBool.cpp (function ?PtInCheckBoxRect@CXTPPropertyGridItemBool@@IAEHVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItemBool.cpp
