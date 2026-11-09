// from server: 100% by auto
// roc 2012-06 00a2fca0  unit: CXTPReportHeaderDragWnd  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a2fca0
//
// 00a2fca0  56                   push esi
// 00a2fca1  8bf1                 mov esi, ecx
// 00a2fca3  e8f825f5ff           call 0x9822a0
// 00a2fca8  85f6                 test esi, esi
// 00a2fcaa  740b                 je 0xa2fcb7
// 00a2fcac  8b06                 mov eax, dword ptr [esi]
// 00a2fcae  8b5004               mov edx, dword ptr [eax + 4]
// 00a2fcb1  6a01                 push 1
// 00a2fcb3  8bce                 mov ecx, esi
// 00a2fcb5  ffd2                 call edx
// 00a2fcb7  5e                   pop esi
// 00a2fcb8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ?OnNcDestroy@CMFCDesktopAlertWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
