// from server: 100% by auto
// roc 2008-06 00442f70  unit: RBXImage  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00442f70
//
// 00442f70  8b442410             mov eax, dword ptr [esp + 0x10]
// 00442f74  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00442f78  50                   push eax
// 00442f79  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00442f7d  6a00                 push 0
// 00442f7f  6a00                 push 0
// 00442f81  52                   push edx
// 00442f82  8b542414             mov edx, dword ptr [esp + 0x14]
// 00442f86  50                   push eax
// 00442f87  52                   push edx
// 00442f88  e863feffff           call 0x442df0
// 00442f8d  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ?Create@CImage@ATL@@QAEHHHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
