// from server: 100% by auto
// roc 2009-12 0042de70  unit: CRobloxTreeCtrl  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0042de70
//
// 0042de70  8b442404             mov eax, dword ptr [esp + 4]
// 0042de74  8b542408             mov edx, dword ptr [esp + 8]
// 0042de78  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 0042de7b  50                   push eax
// 0042de7c  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0042de7f  52                   push edx
// 0042de80  680a110000           push 0x110a
// 0042de85  50                   push eax
// 0042de86  ff15c4cb9800         call dword ptr [0x98cbc4]
// 0042de8c  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeBase.cpp (function ?GetNextItem@CXTPTreeBase@@UBEPAU_TREEITEM@@PAU2@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeBase.cpp
