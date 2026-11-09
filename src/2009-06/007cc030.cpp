// from server: 100% by auto
// roc 2009-06 007cc030  unit: CXTPReportHeaderDragWnd  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cc030
//
// 007cc030  56                   push esi
// 007cc031  8bf1                 mov esi, ecx
// 007cc033  e886cbf4ff           call 0x718bbe
// 007cc038  85f6                 test esi, esi
// 007cc03a  740b                 je 0x7cc047
// 007cc03c  8b06                 mov eax, dword ptr [esi]
// 007cc03e  8b5004               mov edx, dword ptr [eax + 4]
// 007cc041  6a01                 push 1
// 007cc043  8bce                 mov ecx, esi
// 007cc045  ffd2                 call edx
// 007cc047  5e                   pop esi
// 007cc048  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ?OnNcDestroy@CMFCDesktopAlertWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
