// from server: 100% by auto
// roc 2007-03 0045ac00  unit: seg_00450000  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0045ac00
//
// 0045ac00  8b01                 mov eax, dword ptr [ecx]
// 0045ac02  8b90a8010000         mov edx, dword ptr [eax + 0x1a8]
// 0045ac08  6a00                 push 0
// 0045ac0a  ffd2                 call edx
// 0045ac0c  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\winsplit.cpp (function ?OnCancelMode@CSplitterWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/winsplit.cpp
