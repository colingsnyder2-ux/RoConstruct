// from server: 100% by auto
// roc 2009-12 008ce300  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ce300
//
// 008ce300  8b442404             mov eax, dword ptr [esp + 4]
// 008ce304  8b405c               mov eax, dword ptr [eax + 0x5c]
// 008ce307  8d88000000ff         lea ecx, [eax - 0x1000000]
// 008ce30d  83f907               cmp ecx, 7
// 008ce310  7709                 ja 0x8ce31b
// 008ce312  50                   push eax
// 008ce313  e8c8240000           call 0x8d07e0
// 008ce318  83c404               add esp, 4
// 008ce31b  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?GetItemColor@CXTPTabManager@@UBEKPBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
