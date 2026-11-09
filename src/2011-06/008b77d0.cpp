// from server: 100% by auto
// roc 2011-06 008b77d0  unit: CXTPReportHeaderDragWnd  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b77d0
//
// 008b77d0  56                   push esi
// 008b77d1  8bf1                 mov esi, ecx
// 008b77d3  e80c2af5ff           call 0x80a1e4
// 008b77d8  85f6                 test esi, esi
// 008b77da  740b                 je 0x8b77e7
// 008b77dc  8b06                 mov eax, dword ptr [esi]
// 008b77de  8b5004               mov edx, dword ptr [eax + 4]
// 008b77e1  6a01                 push 1
// 008b77e3  8bce                 mov ecx, esi
// 008b77e5  ffd2                 call edx
// 008b77e7  5e                   pop esi
// 008b77e8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ?OnNcDestroy@CMFCDesktopAlertWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
