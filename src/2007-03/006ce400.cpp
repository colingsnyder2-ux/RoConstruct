// from server: 100% by auto
// roc 2007-03 006ce400  unit: seg_006c0000  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006ce400
//
// 006ce400  56                   push esi
// 006ce401  8bf1                 mov esi, ecx
// 006ce403  e808e90300           call 0x70cd10
// 006ce408  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 006ce40e  e8bd980100           call 0x6e7cd0
// 006ce413  83f806               cmp eax, 6
// 006ce416  751c                 jne 0x6ce434
// 006ce418  57                   push edi
// 006ce419  8b3d38ef7700         mov edi, dword ptr [0x77ef38]
// 006ce41f  6a15                 push 0x15
// 006ce421  ffd7                 call edi
// 006ce423  6a15                 push 0x15
// 006ce425  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 006ce42b  ffd7                 call edi
// 006ce42d  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 006ce433  5f                   pop edi
// 006ce434  5e                   pop esi
// 006ce435  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?RefreshMetrics@COfficePanelColorSet@CXTPDockingPaneVisualStudio2003Theme@XTPDockingPanePaintThemes@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
