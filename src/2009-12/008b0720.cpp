// from server: 100% by auto
// roc 2009-12 008b0720  unit: CXTPDockingPaneAutoHidePanel  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b0720
//
// 008b0720  8b542408             mov edx, dword ptr [esp + 8]
// 008b0724  8b442418             mov eax, dword ptr [esp + 0x18]
// 008b0728  53                   push ebx
// 008b0729  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 008b072d  56                   push esi
// 008b072e  8b742414             mov esi, dword ptr [esp + 0x14]
// 008b0732  89511c               mov dword ptr [ecx + 0x1c], edx
// 008b0735  897120               mov dword ptr [ecx + 0x20], esi
// 008b0738  57                   push edi
// 008b0739  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 008b073d  897924               mov dword ptr [ecx + 0x24], edi
// 008b0740  895928               mov dword ptr [ecx + 0x28], ebx
// 008b0743  895004               mov dword ptr [eax + 4], edx
// 008b0746  897008               mov dword ptr [eax + 8], esi
// 008b0749  89780c               mov dword ptr [eax + 0xc], edi
// 008b074c  5f                   pop edi
// 008b074d  5e                   pop esi
// 008b074e  895810               mov dword ptr [eax + 0x10], ebx
// 008b0751  5b                   pop ebx
// 008b0752  c21800               ret 0x18
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBase.cpp (function ?OnSizeParent@CXTPDockingPaneBase@@MAEXPAVCWnd@@VCRect@@PAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBase.cpp
