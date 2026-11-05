// from server: 100% by auto
// roc 2007-08 006d6880  unit: CXTPReportHeaderDragWnd  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d6880
//
// 006d6880  56                   push esi
// 006d6881  8bf1                 mov esi, ecx
// 006d6883  e86095f5ff           call 0x62fde8
// 006d6888  85f6                 test esi, esi
// 006d688a  740b                 je 0x6d6897
// 006d688c  8b06                 mov eax, dword ptr [esi]
// 006d688e  8b5004               mov edx, dword ptr [eax + 4]
// 006d6891  6a01                 push 1
// 006d6893  8bce                 mov ecx, esi
// 006d6895  ffd2                 call edx
// 006d6897  5e                   pop esi
// 006d6898  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ?OnNcDestroy@CMFCDesktopAlertWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
