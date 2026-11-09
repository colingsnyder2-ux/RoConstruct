// from server: 100% by auto
// roc 2009-06 007e1640  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e1640
//
// 007e1640  56                   push esi
// 007e1641  8bf1                 mov esi, ecx
// 007e1643  8b4604               mov eax, dword ptr [esi + 4]
// 007e1646  57                   push edi
// 007e1647  33ff                 xor edi, edi
// 007e1649  3bc7                 cmp eax, edi
// 007e164b  7409                 je 0x7e1656
// 007e164d  8d4900               lea ecx, [ecx]
// 007e1650  8b00                 mov eax, dword ptr [eax]
// 007e1652  3bc7                 cmp eax, edi
// 007e1654  75fa                 jne 0x7e1650
// 007e1656  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007e1659  897e0c               mov dword ptr [esi + 0xc], edi
// 007e165c  897e10               mov dword ptr [esi + 0x10], edi
// 007e165f  897e08               mov dword ptr [esi + 8], edi
// 007e1662  897e04               mov dword ptr [esi + 4], edi
// 007e1665  e82c7ff3ff           call 0x719596
// 007e166a  897e14               mov dword ptr [esi + 0x14], edi
// 007e166d  5f                   pop edi
// 007e166e  5e                   pop esi
// 007e166f  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ?RemoveAll@?$CList@KK@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
