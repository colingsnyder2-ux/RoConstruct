// from server: 100% by auto
// roc 2007-08 0065d7a0  unit: CXTPReportRow_Batch  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0065d7a0
//
// 0065d7a0  56                   push esi
// 0065d7a1  8bf1                 mov esi, ecx
// 0065d7a3  e888670700           call 0x6d3f30
// 0065d7a8  f644240801           test byte ptr [esp + 8], 1
// 0065d7ad  7406                 je 0x65d7b5
// 0065d7af  56                   push esi
// 0065d7b0  e84bd9ffff           call 0x65b100
// 0065d7b5  8bc6                 mov eax, esi
// 0065d7b7  5e                   pop esi
// 0065d7b8  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
