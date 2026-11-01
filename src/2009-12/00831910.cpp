// from server: 100% by auto
// roc 2009-12 00831910  unit: CXTTreeBase  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00831910
//
// 00831910  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00831914  8b542408             mov edx, dword ptr [esp + 8]
// 00831918  6a00                 push 0
// 0083191a  50                   push eax
// 0083191b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0083191f  52                   push edx
// 00831920  6a00                 push 0
// 00831922  6a00                 push 0
// 00831924  6a00                 push 0
// 00831926  6a08                 push 8
// 00831928  50                   push eax
// 00831929  e8b628fcff           call 0x7f41e4
// 0083192e  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellPidl.cpp (function ?SetItemState@CTreeCtrl@@QAEHPAU_TREEITEM@@II@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellPidl.cpp
