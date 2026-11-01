// from server: 100% by auto
// roc 2011-06 008c7090  unit: XTPDockingPanePaintThemes::CXTPDockingPaneWhidbeyTheme::CColorSetVisualStudio2005  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008c7090
//
// 008c7090  56                   push esi
// 008c7091  8bf1                 mov esi, ecx
// 008c7093  e8e8feffff           call 0x8c6f80
// 008c7098  c7861802000000000000 mov dword ptr [esi + 0x218], 0
// 008c70a2  c7861402000000000000 mov dword ptr [esi + 0x214], 0
// 008c70ac  e82fe3f7ff           call 0x8453e0
// 008c70b1  8bc8                 mov ecx, eax
// 008c70b3  e828e1f7ff           call 0x8451e0
// 008c70b8  48                   dec eax
// 008c70b9  83f802               cmp eax, 2
// 008c70bc  771a                 ja 0x8c70d8
// 008c70be  83be2002000000       cmp dword ptr [esi + 0x220], 0
// 008c70c5  b8716f6400           mov eax, 0x646f71
// 008c70ca  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 008c70d0  7506                 jne 0x8c70d8
// 008c70d2  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 008c70d8  5e                   pop esi
// 008c70d9  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?RefreshMetrics@CColorSetVisualStudio2003@CXTPDockingPaneVisualStudio2005Beta1Theme@XTPDockingPanePaintThemes@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
