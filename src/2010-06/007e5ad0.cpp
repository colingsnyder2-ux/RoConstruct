// from server: 100% by auto
// roc 2010-06 007e5ad0  unit: CXTTreeBase  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e5ad0
//
// 007e5ad0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e5ad4  8b542408             mov edx, dword ptr [esp + 8]
// 007e5ad8  6a00                 push 0
// 007e5ada  50                   push eax
// 007e5adb  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e5adf  52                   push edx
// 007e5ae0  6a00                 push 0
// 007e5ae2  6a00                 push 0
// 007e5ae4  6a00                 push 0
// 007e5ae6  6a08                 push 8
// 007e5ae8  50                   push eax
// 007e5ae9  e83628fcff           call 0x7a8324
// 007e5aee  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTShellPidl.cpp (function ?SetItemState@CTreeCtrl@@QAEHPAU_TREEITEM@@II@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTShellPidl.cpp
