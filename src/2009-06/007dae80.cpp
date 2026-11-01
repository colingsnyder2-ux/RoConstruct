// from server: 100% by auto
// roc 2009-06 007dae80  unit: XTPDockingPanePaintThemes::CXTPDockingPaneOfficeTheme::COfficePanelColorSet  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007dae80
//
// 007dae80  56                   push esi
// 007dae81  8bf1                 mov esi, ecx
// 007dae83  e8f8210300           call 0x80d080
// 007dae88  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 007dae8e  e88dae0100           call 0x7f5d20
// 007dae93  83f806               cmp eax, 6
// 007dae96  751c                 jne 0x7daeb4
// 007dae98  57                   push edi
// 007dae99  8b3de4ee8900         mov edi, dword ptr [0x89eee4]
// 007dae9f  6a15                 push 0x15
// 007daea1  ffd7                 call edi
// 007daea3  6a15                 push 0x15
// 007daea5  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 007daeab  ffd7                 call edi
// 007daead  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 007daeb3  5f                   pop edi
// 007daeb4  5e                   pop esi
// 007daeb5  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?RefreshMetrics@COfficePanelColorSet@CXTPDockingPaneVisualStudio2003Theme@XTPDockingPanePaintThemes@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
