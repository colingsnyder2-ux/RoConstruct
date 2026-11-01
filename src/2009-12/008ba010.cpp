// from server: 100% by auto
// roc 2009-12 008ba010  unit: XTPDockingPanePaintThemes::CXTPDockingPaneWhidbeyTheme::CColorSetWhidbey  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ba010
//
// 008ba010  83b91c02000000       cmp dword ptr [ecx + 0x21c], 0
// 008ba017  8b442418             mov eax, dword ptr [esp + 0x18]
// 008ba01b  7417                 je 0x8ba034
// 008ba01d  83b92002000000       cmp dword ptr [ecx + 0x220], 0
// 008ba024  7408                 je 0x8ba02e
// 008ba026  8b5060               mov edx, dword ptr [eax + 0x60]
// 008ba029  394204               cmp dword ptr [edx + 4], eax
// 008ba02c  7406                 je 0x8ba034
// 008ba02e  83c8ff               or eax, 0xffffffff
// 008ba031  c21800               ret 0x18
// 008ba034  8b542408             mov edx, dword ptr [esp + 8]
// 008ba038  50                   push eax
// 008ba039  83ec10               sub esp, 0x10
// 008ba03c  83b91802000000       cmp dword ptr [ecx + 0x218], 0
// 008ba043  8bc4                 mov eax, esp
// 008ba045  8910                 mov dword ptr [eax], edx
// 008ba047  8b542420             mov edx, dword ptr [esp + 0x20]
// 008ba04b  895004               mov dword ptr [eax + 4], edx
// 008ba04e  8b542424             mov edx, dword ptr [esp + 0x24]
// 008ba052  895008               mov dword ptr [eax + 8], edx
// 008ba055  8b542428             mov edx, dword ptr [esp + 0x28]
// 008ba059  89500c               mov dword ptr [eax + 0xc], edx
// 008ba05c  8b442418             mov eax, dword ptr [esp + 0x18]
// 008ba060  50                   push eax
// 008ba061  7408                 je 0x8ba06b
// 008ba063  e8f8e20200           call 0x8e8360
// 008ba068  c21800               ret 0x18
// 008ba06b  e800d70200           call 0x8e7770
// 008ba070  c21800               ret 0x18
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?FillPropertyButton@CColorSetVisualStudio2005@CXTPDockingPaneVisualStudio2005Beta1Theme@XTPDockingPanePaintThemes@@UAEKPAVCDC@@VCRect@@PAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
