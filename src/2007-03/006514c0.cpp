// from server: 100% by auto
// roc 2007-03 006514c0  unit: seg_00650000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006514c0
//
// 006514c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006514c4  8b542408             mov edx, dword ptr [esp + 8]
// 006514c8  6a00                 push 0
// 006514ca  50                   push eax
// 006514cb  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006514cf  52                   push edx
// 006514d0  6a00                 push 0
// 006514d2  6a00                 push 0
// 006514d4  6a00                 push 0
// 006514d6  6a08                 push 8
// 006514d8  50                   push eax
// 006514d9  e8ead5fcff           call 0x61eac8
// 006514de  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellPidl.cpp (function ?SetItemState@CTreeCtrl@@QAEHPAU_TREEITEM@@II@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellPidl.cpp
