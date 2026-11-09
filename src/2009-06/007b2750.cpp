// from server: 100% by auto
// roc 2009-06 007b2750  unit: CXTPDockBar  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b2750
//
// 007b2750  56                   push esi
// 007b2751  57                   push edi
// 007b2752  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007b2756  8bf1                 mov esi, ecx
// 007b2758  3bf7                 cmp esi, edi
// 007b275a  741c                 je 0x7b2778
// 007b275c  8b4708               mov eax, dword ptr [edi + 8]
// 007b275f  6aff                 push -1
// 007b2761  50                   push eax
// 007b2762  e8a9fdf9ff           call 0x752510
// 007b2767  8b4f08               mov ecx, dword ptr [edi + 8]
// 007b276a  8b5704               mov edx, dword ptr [edi + 4]
// 007b276d  8b4604               mov eax, dword ptr [esi + 4]
// 007b2770  51                   push ecx
// 007b2771  52                   push edx
// 007b2772  50                   push eax
// 007b2773  e898590100           call 0x7c8110
// 007b2778  5f                   pop edi
// 007b2779  5e                   pop esi
// 007b277a  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribboncategory.cpp (function ?Copy@?$CArray@HH@@QAEXABV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribboncategory.cpp
