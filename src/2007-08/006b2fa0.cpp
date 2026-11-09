// from server: 100% by auto
// roc 2007-08 006b2fa0  unit: CXTPResourceManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006b2fa0
//
// 006b2fa0  56                   push esi
// 006b2fa1  8bf1                 mov esi, ecx
// 006b2fa3  e878ffffff           call 0x6b2f20
// 006b2fa8  f644240801           test byte ptr [esp + 8], 1
// 006b2fad  7406                 je 0x6b2fb5
// 006b2faf  56                   push esi
// 006b2fb0  e873530800           call 0x738328
// 006b2fb5  8bc6                 mov eax, esi
// 006b2fb7  5e                   pop esi
// 006b2fb8  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
