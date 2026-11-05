// from server: 100% by colin
// roc 2007-03 00442370  unit: seg_00440000  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00442370
//
// 00442370  8b442410             mov eax, dword ptr [esp + 0x10]
// 00442374  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00442378  50                   push eax
// 00442379  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0044237d  6a00                 push 0
// 0044237f  6a00                 push 0
// 00442381  52                   push edx
// 00442382  8b542414             mov edx, dword ptr [esp + 0x14]
// 00442386  50                   push eax
// 00442387  52                   push edx
// 00442388  e863feffff           call 0x4421f0
// 0044238d  c21000               ret 0x10
// copied from an identical function in another client (function ?Create@CImage@ATL@@QAEHHHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp