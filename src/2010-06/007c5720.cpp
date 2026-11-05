// from server: 100% by auto
// roc 2010-06 007c5720  unit: CXTPToolBar  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c5720
//
// 007c5720  8b442408             mov eax, dword ptr [esp + 8]
// 007c5724  56                   push esi
// 007c5725  8b742408             mov esi, dword ptr [esp + 8]
// 007c5729  50                   push eax
// 007c572a  56                   push esi
// 007c572b  e8602fffff           call 0x7b8690
// 007c5730  8bc8                 mov ecx, eax
// 007c5732  e8e983feff           call 0x7adb20
// 007c5737  8bc6                 mov eax, esi
// 007c5739  5e                   pop esi
// 007c573a  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPToolBar.cpp (function ?GetAutoIconSize@CXTPCommandBar@@IBE?AVCSize@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPToolBar.cpp
