// from server: 100% by auto
// roc 2010-06 0086e140  unit: XTPDockingPanePaintThemes::CXTPDockingPaneWhidbeyTheme::CColorSetWhidbey  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0086e140
//
// 0086e140  83b91c02000000       cmp dword ptr [ecx + 0x21c], 0
// 0086e147  8b442418             mov eax, dword ptr [esp + 0x18]
// 0086e14b  7417                 je 0x86e164
// 0086e14d  83b92002000000       cmp dword ptr [ecx + 0x220], 0
// 0086e154  7408                 je 0x86e15e
// 0086e156  8b5060               mov edx, dword ptr [eax + 0x60]
// 0086e159  394204               cmp dword ptr [edx + 4], eax
// 0086e15c  7406                 je 0x86e164
// 0086e15e  83c8ff               or eax, 0xffffffff
// 0086e161  c21800               ret 0x18
// 0086e164  8b542408             mov edx, dword ptr [esp + 8]
// 0086e168  50                   push eax
// 0086e169  83ec10               sub esp, 0x10
// 0086e16c  83b91802000000       cmp dword ptr [ecx + 0x218], 0
// 0086e173  8bc4                 mov eax, esp
// 0086e175  8910                 mov dword ptr [eax], edx
// 0086e177  8b542420             mov edx, dword ptr [esp + 0x20]
// 0086e17b  895004               mov dword ptr [eax + 4], edx
// 0086e17e  8b542424             mov edx, dword ptr [esp + 0x24]
// 0086e182  895008               mov dword ptr [eax + 8], edx
// 0086e185  8b542428             mov edx, dword ptr [esp + 0x28]
// 0086e189  89500c               mov dword ptr [eax + 0xc], edx
// 0086e18c  8b442418             mov eax, dword ptr [esp + 0x18]
// 0086e190  50                   push eax
// 0086e191  7408                 je 0x86e19b
// 0086e193  e8e8ef0200           call 0x89d180
// 0086e198  c21800               ret 0x18
// 0086e19b  e8f0e30200           call 0x89c590
// 0086e1a0  c21800               ret 0x18
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?FillPropertyButton@CColorSetVisualStudio2005@CXTPDockingPaneVisualStudio2005Beta1Theme@XTPDockingPanePaintThemes@@UAEKPAVCDC@@VCRect@@PAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
