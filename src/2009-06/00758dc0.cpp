// from server: 100% by auto
// roc 2009-06 00758dc0  unit: CRobloxTreeCtrl  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00758dc0
//
// 00758dc0  8b442404             mov eax, dword ptr [esp + 4]
// 00758dc4  8b5014               mov edx, dword ptr [eax + 0x14]
// 00758dc7  52                   push edx
// 00758dc8  83c118               add ecx, 0x18
// 00758dcb  e890f4ffff           call 0x758260
// 00758dd0  8b442408             mov eax, dword ptr [esp + 8]
// 00758dd4  c70000000000         mov dword ptr [eax], 0
// 00758dda  33c0                 xor eax, eax
// 00758ddc  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnDeleteItem@CXTPTreeBase@@IAEHPAUtagNMHDR@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
