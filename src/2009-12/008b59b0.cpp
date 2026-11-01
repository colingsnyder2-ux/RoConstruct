// from server: 100% by auto
// roc 2009-12 008b59b0  unit: XTPDockingPanePaintThemes::CXTPDockingPaneOfficeTheme::COfficePanelColorSet  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b59b0
//
// 008b59b0  56                   push esi
// 008b59b1  8bf1                 mov esi, ecx
// 008b59b3  e8b8210300           call 0x8e7b70
// 008b59b8  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 008b59be  e81deffaff           call 0x8648e0
// 008b59c3  83f806               cmp eax, 6
// 008b59c6  751c                 jne 0x8b59e4
// 008b59c8  57                   push edi
// 008b59c9  8b3dd8ca9800         mov edi, dword ptr [0x98cad8]
// 008b59cf  6a15                 push 0x15
// 008b59d1  ffd7                 call edi
// 008b59d3  6a15                 push 0x15
// 008b59d5  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 008b59db  ffd7                 call edi
// 008b59dd  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 008b59e3  5f                   pop edi
// 008b59e4  5e                   pop esi
// 008b59e5  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?RefreshMetrics@COfficePanelColorSet@CXTPDockingPaneVisualStudio2003Theme@XTPDockingPanePaintThemes@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
