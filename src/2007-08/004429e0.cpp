// from server: 100% by auto
// roc 2007-08 004429e0  unit: RBXImage  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004429e0
//
// 004429e0  8b442410             mov eax, dword ptr [esp + 0x10]
// 004429e4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004429e8  50                   push eax
// 004429e9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004429ed  6a00                 push 0
// 004429ef  6a00                 push 0
// 004429f1  52                   push edx
// 004429f2  8b542414             mov edx, dword ptr [esp + 0x14]
// 004429f6  50                   push eax
// 004429f7  52                   push edx
// 004429f8  e863feffff           call 0x442860
// 004429fd  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ?Create@CImage@ATL@@QAEHHHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
