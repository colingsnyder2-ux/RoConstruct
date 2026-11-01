// from server: 100% by auto
// roc 2007-03 00434520  unit: seg_00430000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00434520
//
// 00434520  8b442404             mov eax, dword ptr [esp + 4]
// 00434524  8b542408             mov edx, dword ptr [esp + 8]
// 00434528  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 0043452b  50                   push eax
// 0043452c  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0043452f  52                   push edx
// 00434530  680a110000           push 0x110a
// 00434535  50                   push eax
// 00434536  ff1550ee7700         call dword ptr [0x77ee50]
// 0043453c  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeBase.cpp (function ?GetNextItem@CXTPTreeBase@@UBEPAU_TREEITEM@@PAU2@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeBase.cpp
