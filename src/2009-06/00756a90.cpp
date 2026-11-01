// from server: 100% by auto
// roc 2009-06 00756a90  unit: CXTTreeBase  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00756a90
//
// 00756a90  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00756a94  8b542408             mov edx, dword ptr [esp + 8]
// 00756a98  6a00                 push 0
// 00756a9a  50                   push eax
// 00756a9b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00756a9f  52                   push edx
// 00756aa0  6a00                 push 0
// 00756aa2  6a00                 push 0
// 00756aa4  6a00                 push 0
// 00756aa6  6a08                 push 8
// 00756aa8  50                   push eax
// 00756aa9  e80e29fcff           call 0x7193bc
// 00756aae  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellPidl.cpp (function ?SetItemState@CTreeCtrl@@QAEHPAU_TREEITEM@@II@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellPidl.cpp
