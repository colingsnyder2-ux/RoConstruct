// from server: 100% by auto
// roc 2007-03 0068a6f0  unit: seg_00680000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068a6f0
//
// 0068a6f0  83ec10               sub esp, 0x10
// 0068a6f3  8b01                 mov eax, dword ptr [ecx]
// 0068a6f5  8b405c               mov eax, dword ptr [eax + 0x5c]
// 0068a6f8  8d1424               lea edx, [esp]
// 0068a6fb  52                   push edx
// 0068a6fc  ffd0                 call eax
// 0068a6fe  8b0c24               mov ecx, dword ptr [esp]
// 0068a701  8b542418             mov edx, dword ptr [esp + 0x18]
// 0068a705  8b442414             mov eax, dword ptr [esp + 0x14]
// 0068a709  83c10f               add ecx, 0xf
// 0068a70c  52                   push edx
// 0068a70d  894c240c             mov dword ptr [esp + 0xc], ecx
// 0068a711  50                   push eax
// 0068a712  8d4c2408             lea ecx, [esp + 8]
// 0068a716  51                   push ecx
// 0068a717  ff1598ed7700         call dword ptr [0x77ed98]
// 0068a71d  83c410               add esp, 0x10
// 0068a720  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItemBool.cpp (function ?PtInCheckBoxRect@CXTPPropertyGridItemBool@@IAEHVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItemBool.cpp
