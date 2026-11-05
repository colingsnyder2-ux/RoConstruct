// from server: 100% by auto
// roc 2007-08 006a40a0  unit: CXTPMouseManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a40a0
//
// 006a40a0  56                   push esi
// 006a40a1  8bf1                 mov esi, ecx
// 006a40a3  e888ffffff           call 0x6a4030
// 006a40a8  f644240801           test byte ptr [esp + 8], 1
// 006a40ad  7406                 je 0x6a40b5
// 006a40af  56                   push esi
// 006a40b0  e873420900           call 0x738328
// 006a40b5  8bc6                 mov eax, esi
// 006a40b7  5e                   pop esi
// 006a40b8  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
