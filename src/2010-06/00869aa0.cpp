// from server: 100% by auto
// roc 2010-06 00869aa0  unit: XTPDockingPanePaintThemes::CXTPDockingPaneOfficeTheme::COfficePanelColorSet  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00869aa0
//
// 00869aa0  56                   push esi
// 00869aa1  8bf1                 mov esi, ecx
// 00869aa3  e8e82e0300           call 0x89c990
// 00869aa8  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 00869aae  e82dccc6ff           call 0x4d66e0
// 00869ab3  83f806               cmp eax, 6
// 00869ab6  751c                 jne 0x869ad4
// 00869ab8  57                   push edi
// 00869ab9  8b3d04ba9e00         mov edi, dword ptr [0x9eba04]
// 00869abf  6a15                 push 0x15
// 00869ac1  ffd7                 call edi
// 00869ac3  6a15                 push 0x15
// 00869ac5  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 00869acb  ffd7                 call edi
// 00869acd  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 00869ad3  5f                   pop edi
// 00869ad4  5e                   pop esi
// 00869ad5  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?RefreshMetrics@COfficePanelColorSet@CXTPDockingPaneVisualStudio2003Theme@XTPDockingPanePaintThemes@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
