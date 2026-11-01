// from server: 100% by auto
// roc 2007-03 006501f0  unit: seg_00650000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006501f0
//
// 006501f0  8b442408             mov eax, dword ptr [esp + 8]
// 006501f4  8b542404             mov edx, dword ptr [esp + 4]
// 006501f8  6a01                 push 1
// 006501fa  50                   push eax
// 006501fb  52                   push edx
// 006501fc  83c120               add ecx, 0x20
// 006501ff  e82cfcffff           call 0x64fe30
// 00650204  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?InsertAt@CXTPPropertyGridItems@@IAEXHPAVCXTPPropertyGridItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
