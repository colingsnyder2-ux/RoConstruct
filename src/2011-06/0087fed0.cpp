// from server: 100% by auto
// roc 2011-06 0087fed0  unit: CXTPResourceManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0087fed0
//
// 0087fed0  56                   push esi
// 0087fed1  8bf1                 mov esi, ecx
// 0087fed3  e8e8feffff           call 0x87fdc0
// 0087fed8  f644240801           test byte ptr [esp + 8], 1
// 0087fedd  7406                 je 0x87fee5
// 0087fedf  56                   push esi
// 0087fee0  e8c7c61400           call 0x9cc5ac
// 0087fee5  8bc6                 mov eax, esi
// 0087fee7  5e                   pop esi
// 0087fee8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
