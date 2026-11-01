// from server: 100% by auto
// roc 2009-06 0073a5a0  unit: CXTPToolBar  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073a5a0
//
// 0073a5a0  8b442408             mov eax, dword ptr [esp + 8]
// 0073a5a4  56                   push esi
// 0073a5a5  8b742408             mov esi, dword ptr [esp + 8]
// 0073a5a9  50                   push eax
// 0073a5aa  56                   push esi
// 0073a5ab  e8a02effff           call 0x72d450
// 0073a5b0  8bc8                 mov ecx, eax
// 0073a5b2  e8e98bfeff           call 0x7231a0
// 0073a5b7  8bc6                 mov eax, esi
// 0073a5b9  5e                   pop esi
// 0073a5ba  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPToolBar.cpp (function ?GetAutoIconSize@CXTPCommandBar@@IBE?AVCSize@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPToolBar.cpp
