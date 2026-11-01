// from server: 100% by auto
// roc 2009-06 0071bf90  unit: CXTPEdit  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071bf90
//
// 0071bf90  56                   push esi
// 0071bf91  8bf1                 mov esi, ecx
// 0071bf93  e870d0ffff           call 0x719008
// 0071bf98  c7465400000000       mov dword ptr [esi + 0x54], 0
// 0071bf9f  5e                   pop esi
// 0071bfa0  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?OnKillFocus@CXTPCommandBarEditCtrl@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
