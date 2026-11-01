// from server: 100% by auto
// roc 2007-03 006c9400  unit: seg_006c0000  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c9400
//
// 006c9400  8b542408             mov edx, dword ptr [esp + 8]
// 006c9404  8b442418             mov eax, dword ptr [esp + 0x18]
// 006c9408  53                   push ebx
// 006c9409  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006c940d  56                   push esi
// 006c940e  8b742414             mov esi, dword ptr [esp + 0x14]
// 006c9412  89511c               mov dword ptr [ecx + 0x1c], edx
// 006c9415  897120               mov dword ptr [ecx + 0x20], esi
// 006c9418  57                   push edi
// 006c9419  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 006c941d  897924               mov dword ptr [ecx + 0x24], edi
// 006c9420  895928               mov dword ptr [ecx + 0x28], ebx
// 006c9423  895004               mov dword ptr [eax + 4], edx
// 006c9426  897008               mov dword ptr [eax + 8], esi
// 006c9429  89780c               mov dword ptr [eax + 0xc], edi
// 006c942c  5f                   pop edi
// 006c942d  5e                   pop esi
// 006c942e  895810               mov dword ptr [eax + 0x10], ebx
// 006c9431  5b                   pop ebx
// 006c9432  c21800               ret 0x18
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBase.cpp (function ?OnSizeParent@CXTPDockingPaneBase@@MAEXPAVCWnd@@VCRect@@PAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBase.cpp
