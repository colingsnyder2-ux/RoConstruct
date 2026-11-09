// from server: 100% by auto
// roc 2010-06 0085f260  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085f260
//
// 0085f260  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0085f264  57                   push edi
// 0085f265  8bf9                 mov edi, ecx
// 0085f267  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0085f26b  50                   push eax
// 0085f26c  51                   push ecx
// 0085f26d  8bcf                 mov ecx, edi
// 0085f26f  e87cfeffff           call 0x85f0f0
// 0085f274  85c0                 test eax, eax
// 0085f276  741c                 je 0x85f294
// 0085f278  56                   push esi
// 0085f279  8d4f54               lea ecx, [edi + 0x54]
// 0085f27c  8d7020               lea esi, [eax + 0x20]
// 0085f27f  e88c560000           call 0x864910
// 0085f284  8b10                 mov edx, dword ptr [eax]
// 0085f286  56                   push esi
// 0085f287  8bc8                 mov ecx, eax
// 0085f289  8b8248010000         mov eax, dword ptr [edx + 0x148]
// 0085f28f  6a02                 push 2
// 0085f291  ffd0                 call eax
// 0085f293  5e                   pop esi
// 0085f294  5f                   pop edi
// 0085f295  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp (function ?OnRButtonDown@CXTPDockingPaneAutoHidePanel@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/DockingPane/XTPDockingPaneAutoHidePanel.cpp
