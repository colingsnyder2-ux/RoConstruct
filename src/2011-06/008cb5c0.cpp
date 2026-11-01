// from server: 100% by auto
// roc 2011-06 008cb5c0  unit: XTPDockingPanePaintThemes::CXTPDockingPaneWhidbeyTheme::CColorSetWhidbey  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008cb5c0
//
// 008cb5c0  83b91c02000000       cmp dword ptr [ecx + 0x21c], 0
// 008cb5c7  8b442418             mov eax, dword ptr [esp + 0x18]
// 008cb5cb  7417                 je 0x8cb5e4
// 008cb5cd  83b92002000000       cmp dword ptr [ecx + 0x220], 0
// 008cb5d4  7408                 je 0x8cb5de
// 008cb5d6  8b5060               mov edx, dword ptr [eax + 0x60]
// 008cb5d9  394204               cmp dword ptr [edx + 4], eax
// 008cb5dc  7406                 je 0x8cb5e4
// 008cb5de  83c8ff               or eax, 0xffffffff
// 008cb5e1  c21800               ret 0x18
// 008cb5e4  8b542408             mov edx, dword ptr [esp + 8]
// 008cb5e8  50                   push eax
// 008cb5e9  83ec10               sub esp, 0x10
// 008cb5ec  83b91802000000       cmp dword ptr [ecx + 0x218], 0
// 008cb5f3  8bc4                 mov eax, esp
// 008cb5f5  8910                 mov dword ptr [eax], edx
// 008cb5f7  8b542420             mov edx, dword ptr [esp + 0x20]
// 008cb5fb  895004               mov dword ptr [eax + 4], edx
// 008cb5fe  8b542424             mov edx, dword ptr [esp + 0x24]
// 008cb602  895008               mov dword ptr [eax + 8], edx
// 008cb605  8b542428             mov edx, dword ptr [esp + 0x28]
// 008cb609  89500c               mov dword ptr [eax + 0xc], edx
// 008cb60c  8b442418             mov eax, dword ptr [esp + 0x18]
// 008cb610  50                   push eax
// 008cb611  7408                 je 0x8cb61b
// 008cb613  e8c8a60200           call 0x8f5ce0
// 008cb618  c21800               ret 0x18
// 008cb61b  e8d09a0200           call 0x8f50f0
// 008cb620  c21800               ret 0x18
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?FillPropertyButton@CColorSetVisualStudio2005@CXTPDockingPaneVisualStudio2005Beta1Theme@XTPDockingPanePaintThemes@@UAEKPAVCDC@@VCRect@@PAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
