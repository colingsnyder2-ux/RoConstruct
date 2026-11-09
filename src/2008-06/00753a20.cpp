// from server: 100% by auto
// roc 2008-06 00753a20  unit: CXTPReportHeaderDragWnd  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00753a20
//
// 00753a20  56                   push esi
// 00753a21  8bf1                 mov esi, ecx
// 00753a23  e8e4cdf4ff           call 0x6a080c
// 00753a28  85f6                 test esi, esi
// 00753a2a  740b                 je 0x753a37
// 00753a2c  8b06                 mov eax, dword ptr [esi]
// 00753a2e  8b5004               mov edx, dword ptr [eax + 4]
// 00753a31  6a01                 push 1
// 00753a33  8bce                 mov ecx, esi
// 00753a35  ffd2                 call edx
// 00753a37  5e                   pop esi
// 00753a38  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ?OnNcDestroy@CMFCDesktopAlertWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
