// from server: 100% by auto
// roc 2007-03 0069f200  unit: seg_00690000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0069f200
//
// 0069f200  56                   push esi
// 0069f201  8bf1                 mov esi, ecx
// 0069f203  e888ffffff           call 0x69f190
// 0069f208  f644240801           test byte ptr [esp + 8], 1
// 0069f20d  7406                 je 0x69f215
// 0069f20f  56                   push esi
// 0069f210  e85fb80900           call 0x73aa74
// 0069f215  8bc6                 mov eax, esi
// 0069f217  5e                   pop esi
// 0069f218  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
