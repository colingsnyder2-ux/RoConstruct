// from server: 100% by auto
// roc 2009-12 0086e830  unit: CXTPResourceManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086e830
//
// 0086e830  56                   push esi
// 0086e831  8bf1                 mov esi, ecx
// 0086e833  e8e8feffff           call 0x86e720
// 0086e838  f644240801           test byte ptr [esp + 8], 1
// 0086e83d  7406                 je 0x86e845
// 0086e83f  56                   push esi
// 0086e840  e8df7b0b00           call 0x926424
// 0086e845  8bc6                 mov eax, esi
// 0086e847  5e                   pop esi
// 0086e848  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
