// from server: 100% by auto
// roc 2009-06 007dafd0  unit: XTPDockingPanePaintThemes::CXTPDockingPaneWhidbeyTheme::CColorSetVisualStudio2005  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007dafd0
//
// 007dafd0  56                   push esi
// 007dafd1  8bf1                 mov esi, ecx
// 007dafd3  e8e8feffff           call 0x7daec0
// 007dafd8  c7861802000000000000 mov dword ptr [esi + 0x218], 0
// 007dafe2  c7861402000000000000 mov dword ptr [esi + 0x214], 0
// 007dafec  e82f9bf7ff           call 0x754b20
// 007daff1  8bc8                 mov ecx, eax
// 007daff3  e8d898f7ff           call 0x7548d0
// 007daff8  48                   dec eax
// 007daff9  83f802               cmp eax, 2
// 007daffc  771a                 ja 0x7db018
// 007daffe  83be2002000000       cmp dword ptr [esi + 0x220], 0
// 007db005  b8716f6400           mov eax, 0x646f71
// 007db00a  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 007db010  7506                 jne 0x7db018
// 007db012  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 007db018  5e                   pop esi
// 007db019  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?RefreshMetrics@CColorSetVisualStudio2003@CXTPDockingPaneVisualStudio2005Beta1Theme@XTPDockingPanePaintThemes@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
