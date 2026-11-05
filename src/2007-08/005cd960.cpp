// from server: 100% by auto
// roc 2007-08 005cd960  unit: RBX::Contact  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005cd960
//
// 005cd960  8b442404             mov eax, dword ptr [esp + 4]
// 005cd964  56                   push esi
// 005cd965  50                   push eax
// 005cd966  8bf1                 mov esi, ecx
// 005cd968  e8c3b70300           call 0x609130
// 005cd96d  8bce                 mov ecx, esi
// 005cd96f  e8acfeffff           call 0x5cd820
// 005cd974  5e                   pop esi
// 005cd975  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonedit.cpp (function ?OnAfterChangeRect@CMFCRibbonEdit@@UAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonedit.cpp
