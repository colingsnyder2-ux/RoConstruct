// from server: 100% by auto
// roc 2010-06 008824e0  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008824e0
//
// 008824e0  8b442404             mov eax, dword ptr [esp + 4]
// 008824e4  8b405c               mov eax, dword ptr [eax + 0x5c]
// 008824e7  8d88000000ff         lea ecx, [eax - 0x1000000]
// 008824ed  83f907               cmp ecx, 7
// 008824f0  7709                 ja 0x8824fb
// 008824f2  50                   push eax
// 008824f3  e8a8240000           call 0x8849a0
// 008824f8  83c404               add esp, 4
// 008824fb  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?GetItemColor@CXTPTabManager@@UBEKPBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
