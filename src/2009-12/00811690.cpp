// from server: 100% by auto
// roc 2009-12 00811690  unit: CXTPToolBar  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00811690
//
// 00811690  8b442408             mov eax, dword ptr [esp + 8]
// 00811694  56                   push esi
// 00811695  8b742408             mov esi, dword ptr [esp + 8]
// 00811699  50                   push eax
// 0081169a  56                   push esi
// 0081169b  e8f02effff           call 0x804590
// 008116a0  8bc8                 mov ecx, eax
// 008116a2  e8a9c9feff           call 0x7fe050
// 008116a7  8bc6                 mov eax, esi
// 008116a9  5e                   pop esi
// 008116aa  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPToolBar.cpp (function ?GetAutoIconSize@CXTPCommandBar@@IBE?AVCSize@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPToolBar.cpp
