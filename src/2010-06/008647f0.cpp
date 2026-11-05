// from server: 100% by auto
// roc 2010-06 008647f0  unit: CXTPDockingPaneAutoHidePanel  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008647f0
//
// 008647f0  8b542408             mov edx, dword ptr [esp + 8]
// 008647f4  8b442418             mov eax, dword ptr [esp + 0x18]
// 008647f8  53                   push ebx
// 008647f9  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 008647fd  56                   push esi
// 008647fe  8b742414             mov esi, dword ptr [esp + 0x14]
// 00864802  89511c               mov dword ptr [ecx + 0x1c], edx
// 00864805  897120               mov dword ptr [ecx + 0x20], esi
// 00864808  57                   push edi
// 00864809  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0086480d  897924               mov dword ptr [ecx + 0x24], edi
// 00864810  895928               mov dword ptr [ecx + 0x28], ebx
// 00864813  895004               mov dword ptr [eax + 4], edx
// 00864816  897008               mov dword ptr [eax + 8], esi
// 00864819  89780c               mov dword ptr [eax + 0xc], edi
// 0086481c  5f                   pop edi
// 0086481d  5e                   pop esi
// 0086481e  895810               mov dword ptr [eax + 0x10], ebx
// 00864821  5b                   pop ebx
// 00864822  c21800               ret 0x18
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneBase.cpp (function ?OnSizeParent@CXTPDockingPaneBase@@MAEXPAVCWnd@@VCRect@@PAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneBase.cpp
