// from server: 100% by auto
// roc 2010-06 0085af80  unit: CXTPReportHeaderDragWnd  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085af80
//
// 0085af80  56                   push esi
// 0085af81  8bf1                 mov esi, ecx
// 0085af83  e89ecbf4ff           call 0x7a7b26
// 0085af88  85f6                 test esi, esi
// 0085af8a  740b                 je 0x85af97
// 0085af8c  8b06                 mov eax, dword ptr [esi]
// 0085af8e  8b5004               mov edx, dword ptr [eax + 4]
// 0085af91  6a01                 push 1
// 0085af93  8bce                 mov ecx, esi
// 0085af95  ffd2                 call edx
// 0085af97  5e                   pop esi
// 0085af98  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ?OnNcDestroy@CMFCDesktopAlertWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
