// from server: 100% by auto
// roc 2011-06 004506a0  unit: RBXImage  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004506a0
//
// 004506a0  8b442410             mov eax, dword ptr [esp + 0x10]
// 004506a4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004506a8  50                   push eax
// 004506a9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004506ad  6a00                 push 0
// 004506af  6a00                 push 0
// 004506b1  52                   push edx
// 004506b2  8b542414             mov edx, dword ptr [esp + 0x14]
// 004506b6  50                   push eax
// 004506b7  52                   push edx
// 004506b8  e863feffff           call 0x450520
// 004506bd  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ?Create@CImage@ATL@@QAEHHHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
