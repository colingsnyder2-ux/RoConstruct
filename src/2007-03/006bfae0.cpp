// from server: 100% by auto
// roc 2007-03 006bfae0  unit: seg_006b0000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006bfae0
//
// 006bfae0  56                   push esi
// 006bfae1  8bf1                 mov esi, ecx
// 006bfae3  e894e7f5ff           call 0x61e27c
// 006bfae8  85f6                 test esi, esi
// 006bfaea  740b                 je 0x6bfaf7
// 006bfaec  8b06                 mov eax, dword ptr [esi]
// 006bfaee  8b5004               mov edx, dword ptr [eax + 4]
// 006bfaf1  6a01                 push 1
// 006bfaf3  8bce                 mov ecx, esi
// 006bfaf5  ffd2                 call edx
// 006bfaf7  5e                   pop esi
// 006bfaf8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ?OnNcDestroy@CMFCDesktopAlertWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
