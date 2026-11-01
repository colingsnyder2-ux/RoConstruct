// from server: 100% by auto
// roc 2009-06 007f3750  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f3750
//
// 007f3750  8b442404             mov eax, dword ptr [esp + 4]
// 007f3754  8b405c               mov eax, dword ptr [eax + 0x5c]
// 007f3757  8d88000000ff         lea ecx, [eax - 0x1000000]
// 007f375d  83f907               cmp ecx, 7
// 007f3760  7709                 ja 0x7f376b
// 007f3762  50                   push eax
// 007f3763  e8a8240000           call 0x7f5c10
// 007f3768  83c404               add esp, 4
// 007f376b  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?GetItemColor@CXTPTabManager@@UBEKPBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
