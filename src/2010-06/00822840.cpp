// from server: 100% by auto
// roc 2010-06 00822840  unit: CXTPResourceManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00822840
//
// 00822840  56                   push esi
// 00822841  8bf1                 mov esi, ecx
// 00822843  e8e8feffff           call 0x822730
// 00822848  f644240801           test byte ptr [esp + 8], 1
// 0082284d  7406                 je 0x822855
// 0082284f  56                   push esi
// 00822850  e80ba51500           call 0x97cd60
// 00822855  8bc6                 mov eax, esi
// 00822857  5e                   pop esi
// 00822858  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
