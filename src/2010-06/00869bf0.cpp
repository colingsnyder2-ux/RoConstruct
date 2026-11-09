// from server: 100% by auto
// roc 2010-06 00869bf0  unit: XTPDockingPanePaintThemes::CXTPDockingPaneWhidbeyTheme::CColorSetVisualStudio2005  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00869bf0
//
// 00869bf0  56                   push esi
// 00869bf1  8bf1                 mov esi, ecx
// 00869bf3  e8e8feffff           call 0x869ae0
// 00869bf8  c7861802000000000000 mov dword ptr [esi + 0x218], 0
// 00869c02  c7861402000000000000 mov dword ptr [esi + 0x214], 0
// 00869c0c  e80f9ff7ff           call 0x7e3b20
// 00869c11  8bc8                 mov ecx, eax
// 00869c13  e8b89cf7ff           call 0x7e38d0
// 00869c18  48                   dec eax
// 00869c19  83f802               cmp eax, 2
// 00869c1c  771a                 ja 0x869c38
// 00869c1e  83be2002000000       cmp dword ptr [esi + 0x220], 0
// 00869c25  b8716f6400           mov eax, 0x646f71
// 00869c2a  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 00869c30  7506                 jne 0x869c38
// 00869c32  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 00869c38  5e                   pop esi
// 00869c39  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?RefreshMetrics@CColorSetVisualStudio2003@CXTPDockingPaneVisualStudio2005Beta1Theme@XTPDockingPanePaintThemes@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
