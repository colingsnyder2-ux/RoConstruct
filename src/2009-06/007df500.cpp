// from server: 100% by auto
// roc 2009-06 007df500  unit: XTPDockingPanePaintThemes::CXTPDockingPaneWhidbeyTheme::CColorSetWhidbey  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007df500
//
// 007df500  83b91c02000000       cmp dword ptr [ecx + 0x21c], 0
// 007df507  8b442418             mov eax, dword ptr [esp + 0x18]
// 007df50b  7417                 je 0x7df524
// 007df50d  83b92002000000       cmp dword ptr [ecx + 0x220], 0
// 007df514  7408                 je 0x7df51e
// 007df516  8b5060               mov edx, dword ptr [eax + 0x60]
// 007df519  394204               cmp dword ptr [edx + 4], eax
// 007df51c  7406                 je 0x7df524
// 007df51e  83c8ff               or eax, 0xffffffff
// 007df521  c21800               ret 0x18
// 007df524  8b542408             mov edx, dword ptr [esp + 8]
// 007df528  50                   push eax
// 007df529  83ec10               sub esp, 0x10
// 007df52c  83b91802000000       cmp dword ptr [ecx + 0x218], 0
// 007df533  8bc4                 mov eax, esp
// 007df535  8910                 mov dword ptr [eax], edx
// 007df537  8b542420             mov edx, dword ptr [esp + 0x20]
// 007df53b  895004               mov dword ptr [eax + 4], edx
// 007df53e  8b542424             mov edx, dword ptr [esp + 0x24]
// 007df542  895008               mov dword ptr [eax + 8], edx
// 007df545  8b542428             mov edx, dword ptr [esp + 0x28]
// 007df549  89500c               mov dword ptr [eax + 0xc], edx
// 007df54c  8b442418             mov eax, dword ptr [esp + 0x18]
// 007df550  50                   push eax
// 007df551  7408                 je 0x7df55b
// 007df553  e818e30200           call 0x80d870
// 007df558  c21800               ret 0x18
// 007df55b  e820d70200           call 0x80cc80
// 007df560  c21800               ret 0x18
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?FillPropertyButton@CColorSetVisualStudio2005@CXTPDockingPaneVisualStudio2005Beta1Theme@XTPDockingPanePaintThemes@@UAEKPAVCDC@@VCRect@@PAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
