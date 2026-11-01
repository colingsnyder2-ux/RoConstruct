// from server: 100% by auto
// roc 2007-03 006d2a20  unit: seg_006d0000  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006d2a20
//
// 006d2a20  83b91c02000000       cmp dword ptr [ecx + 0x21c], 0
// 006d2a27  8b442418             mov eax, dword ptr [esp + 0x18]
// 006d2a2b  7417                 je 0x6d2a44
// 006d2a2d  83b92002000000       cmp dword ptr [ecx + 0x220], 0
// 006d2a34  7408                 je 0x6d2a3e
// 006d2a36  8b5060               mov edx, dword ptr [eax + 0x60]
// 006d2a39  394204               cmp dword ptr [edx + 4], eax
// 006d2a3c  7406                 je 0x6d2a44
// 006d2a3e  83c8ff               or eax, 0xffffffff
// 006d2a41  c21800               ret 0x18
// 006d2a44  8b542408             mov edx, dword ptr [esp + 8]
// 006d2a48  50                   push eax
// 006d2a49  83ec10               sub esp, 0x10
// 006d2a4c  83b91802000000       cmp dword ptr [ecx + 0x218], 0
// 006d2a53  8bc4                 mov eax, esp
// 006d2a55  8910                 mov dword ptr [eax], edx
// 006d2a57  8b542420             mov edx, dword ptr [esp + 0x20]
// 006d2a5b  895004               mov dword ptr [eax + 4], edx
// 006d2a5e  8b542424             mov edx, dword ptr [esp + 0x24]
// 006d2a62  895008               mov dword ptr [eax + 8], edx
// 006d2a65  8b542428             mov edx, dword ptr [esp + 0x28]
// 006d2a69  89500c               mov dword ptr [eax + 0xc], edx
// 006d2a6c  8b442418             mov eax, dword ptr [esp + 0x18]
// 006d2a70  50                   push eax
// 006d2a71  7408                 je 0x6d2a7b
// 006d2a73  e868aa0300           call 0x70d4e0
// 006d2a78  c21800               ret 0x18
// 006d2a7b  e8a09e0300           call 0x70c920
// 006d2a80  c21800               ret 0x18
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?FillPropertyButton@CColorSetVisualStudio2005@CXTPDockingPaneVisualStudio2005Beta1Theme@XTPDockingPanePaintThemes@@UAEKPAVCDC@@VCRect@@PAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
