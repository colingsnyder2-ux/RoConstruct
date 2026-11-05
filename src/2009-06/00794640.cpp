// from server: 100% by auto
// roc 2009-06 00794640  unit: CXTPMouseManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00794640
//
// 00794640  56                   push esi
// 00794641  8bf1                 mov esi, ecx
// 00794643  e888ffffff           call 0x7945d0
// 00794648  f644240801           test byte ptr [esp + 8], 1
// 0079464d  7406                 je 0x794655
// 0079464f  56                   push esi
// 00794650  e86f780b00           call 0x84bec4
// 00794655  8bc6                 mov eax, esi
// 00794657  5e                   pop esi
// 00794658  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
