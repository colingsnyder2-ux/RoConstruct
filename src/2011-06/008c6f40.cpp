// from server: 100% by auto
// roc 2011-06 008c6f40  unit: XTPDockingPanePaintThemes::CXTPDockingPaneOfficeTheme::COfficePanelColorSet  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008c6f40
//
// 008c6f40  56                   push esi
// 008c6f41  8bf1                 mov esi, ecx
// 008c6f43  e8a8e50200           call 0x8f54f0
// 008c6f48  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 008c6f4e  e86dea0000           call 0x8d59c0
// 008c6f53  83f806               cmp eax, 6
// 008c6f56  751c                 jne 0x8c6f74
// 008c6f58  57                   push edi
// 008c6f59  8b3d181ba400         mov edi, dword ptr [0xa41b18]
// 008c6f5f  6a15                 push 0x15
// 008c6f61  ffd7                 call edi
// 008c6f63  6a15                 push 0x15
// 008c6f65  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 008c6f6b  ffd7                 call edi
// 008c6f6d  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 008c6f73  5f                   pop edi
// 008c6f74  5e                   pop esi
// 008c6f75  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?RefreshMetrics@COfficePanelColorSet@CXTPDockingPaneVisualStudio2003Theme@XTPDockingPanePaintThemes@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
