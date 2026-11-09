// from server: 100% by auto
// roc 2008-06 0060cb10  unit: RBX::BallBallContact  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060cb10
//
// 0060cb10  8b442404             mov eax, dword ptr [esp + 4]
// 0060cb14  56                   push esi
// 0060cb15  50                   push eax
// 0060cb16  8bf1                 mov esi, ecx
// 0060cb18  e8138d0300           call 0x645830
// 0060cb1d  8bce                 mov ecx, esi
// 0060cb1f  e8acafffff           call 0x607ad0
// 0060cb24  5e                   pop esi
// 0060cb25  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonedit.cpp (function ?OnAfterChangeRect@CMFCRibbonEdit@@UAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonedit.cpp
