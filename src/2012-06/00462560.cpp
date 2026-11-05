// from server: 100% by auto
// roc 2012-06 00462560  unit: RBXImage  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00462560
//
// 00462560  8b442410             mov eax, dword ptr [esp + 0x10]
// 00462564  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00462568  50                   push eax
// 00462569  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0046256d  6a00                 push 0
// 0046256f  6a00                 push 0
// 00462571  52                   push edx
// 00462572  8b542414             mov edx, dword ptr [esp + 0x14]
// 00462576  50                   push eax
// 00462577  52                   push edx
// 00462578  e863feffff           call 0x4623e0
// 0046257d  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ?Create@CImage@ATL@@QAEHHHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
