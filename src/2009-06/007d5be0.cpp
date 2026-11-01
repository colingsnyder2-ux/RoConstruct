// from server: 100% by auto
// roc 2009-06 007d5be0  unit: CXTPDockingPaneAutoHidePanel  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d5be0
//
// 007d5be0  8b542408             mov edx, dword ptr [esp + 8]
// 007d5be4  8b442418             mov eax, dword ptr [esp + 0x18]
// 007d5be8  53                   push ebx
// 007d5be9  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007d5bed  56                   push esi
// 007d5bee  8b742414             mov esi, dword ptr [esp + 0x14]
// 007d5bf2  89511c               mov dword ptr [ecx + 0x1c], edx
// 007d5bf5  897120               mov dword ptr [ecx + 0x20], esi
// 007d5bf8  57                   push edi
// 007d5bf9  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 007d5bfd  897924               mov dword ptr [ecx + 0x24], edi
// 007d5c00  895928               mov dword ptr [ecx + 0x28], ebx
// 007d5c03  895004               mov dword ptr [eax + 4], edx
// 007d5c06  897008               mov dword ptr [eax + 8], esi
// 007d5c09  89780c               mov dword ptr [eax + 0xc], edi
// 007d5c0c  5f                   pop edi
// 007d5c0d  5e                   pop esi
// 007d5c0e  895810               mov dword ptr [eax + 0x10], ebx
// 007d5c11  5b                   pop ebx
// 007d5c12  c21800               ret 0x18
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBase.cpp (function ?OnSizeParent@CXTPDockingPaneBase@@MAEXPAVCWnd@@VCRect@@PAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBase.cpp
