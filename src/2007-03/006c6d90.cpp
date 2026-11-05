// from server: 100% by auto
// roc 2007-03 006c6d90  unit: seg_006c0000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c6d90
//
// 006c6d90  56                   push esi
// 006c6d91  8bf1                 mov esi, ecx
// 006c6d93  e858ffffff           call 0x6c6cf0
// 006c6d98  f644240801           test byte ptr [esp + 8], 1
// 006c6d9d  7406                 je 0x6c6da5
// 006c6d9f  56                   push esi
// 006c6da0  e8cf3c0700           call 0x73aa74
// 006c6da5  8bc6                 mov eax, esi
// 006c6da7  5e                   pop esi
// 006c6da8  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
