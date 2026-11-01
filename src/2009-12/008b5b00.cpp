// from server: 100% by auto
// roc 2009-12 008b5b00  unit: XTPDockingPanePaintThemes::CXTPDockingPaneWhidbeyTheme::CColorSetVisualStudio2005  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b5b00
//
// 008b5b00  56                   push esi
// 008b5b01  8bf1                 mov esi, ecx
// 008b5b03  e8e8feffff           call 0x8b59f0
// 008b5b08  c7861802000000000000 mov dword ptr [esi + 0x218], 0
// 008b5b12  c7861402000000000000 mov dword ptr [esi + 0x214], 0
// 008b5b1c  e8af9ef7ff           call 0x82f9d0
// 008b5b21  8bc8                 mov ecx, eax
// 008b5b23  e8089cf7ff           call 0x82f730
// 008b5b28  48                   dec eax
// 008b5b29  83f802               cmp eax, 2
// 008b5b2c  771a                 ja 0x8b5b48
// 008b5b2e  83be2002000000       cmp dword ptr [esi + 0x220], 0
// 008b5b35  b8716f6400           mov eax, 0x646f71
// 008b5b3a  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 008b5b40  7506                 jne 0x8b5b48
// 008b5b42  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 008b5b48  5e                   pop esi
// 008b5b49  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?RefreshMetrics@CColorSetVisualStudio2003@CXTPDockingPaneVisualStudio2005Beta1Theme@XTPDockingPanePaintThemes@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
