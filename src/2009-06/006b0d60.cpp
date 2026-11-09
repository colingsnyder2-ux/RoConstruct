// from server: 100% by auto
// roc 2009-06 006b0d60  unit: RBX::BallBallContact  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b0d60
//
// 006b0d60  8b442404             mov eax, dword ptr [esp + 4]
// 006b0d64  56                   push esi
// 006b0d65  50                   push eax
// 006b0d66  8bf1                 mov esi, ecx
// 006b0d68  e8034f0200           call 0x6d5c70
// 006b0d6d  8bce                 mov ecx, esi
// 006b0d6f  e8ececffff           call 0x6afa60
// 006b0d74  5e                   pop esi
// 006b0d75  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonedit.cpp (function ?OnAfterChangeRect@CMFCRibbonEdit@@UAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonedit.cpp
