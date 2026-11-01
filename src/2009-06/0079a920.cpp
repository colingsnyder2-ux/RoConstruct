// from server: 100% by auto
// roc 2009-06 0079a920  unit: CXTPRibbonTheme  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079a920
//
// 0079a920  56                   push esi
// 0079a921  8bf1                 mov esi, ecx
// 0079a923  803e00               cmp byte ptr [esi], 0
// 0079a926  740e                 je 0x79a936
// 0079a928  e8c9e3f7ff           call 0x718cf6
// 0079a92d  8b4e04               mov ecx, dword ptr [esi + 4]
// 0079a930  89480c               mov dword ptr [eax + 0xc], ecx
// 0079a933  c60600               mov byte ptr [esi], 0
// 0079a936  5e                   pop esi
// 0079a937  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?Undo@CManageState@CXTPResourceManager@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
