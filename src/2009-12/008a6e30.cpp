// from server: 100% by auto
// roc 2009-12 008a6e30  unit: CXTPReportHeaderDragWnd  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a6e30
//
// 008a6e30  56                   push esi
// 008a6e31  8bf1                 mov esi, ecx
// 008a6e33  e8aecbf4ff           call 0x7f39e6
// 008a6e38  85f6                 test esi, esi
// 008a6e3a  740b                 je 0x8a6e47
// 008a6e3c  8b06                 mov eax, dword ptr [esi]
// 008a6e3e  8b5004               mov edx, dword ptr [eax + 4]
// 008a6e41  6a01                 push 1
// 008a6e43  8bce                 mov ecx, esi
// 008a6e45  ffd2                 call edx
// 008a6e47  5e                   pop esi
// 008a6e48  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ?OnNcDestroy@CMFCDesktopAlertWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
