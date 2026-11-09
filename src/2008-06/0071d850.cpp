// from server: 100% by auto
// roc 2008-06 0071d850  unit: CXTPMouseManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0071d850
//
// 0071d850  56                   push esi
// 0071d851  8bf1                 mov esi, ecx
// 0071d853  e888ffffff           call 0x71d7e0
// 0071d858  f644240801           test byte ptr [esp + 8], 1
// 0071d85d  7406                 je 0x71d865
// 0071d85f  56                   push esi
// 0071d860  e839e70900           call 0x7bbf9e
// 0071d865  8bc6                 mov eax, esi
// 0071d867  5e                   pop esi
// 0071d868  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
