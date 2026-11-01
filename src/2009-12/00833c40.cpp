// from server: 100% by auto
// roc 2009-12 00833c40  unit: CRobloxTreeCtrl  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00833c40
//
// 00833c40  8b442404             mov eax, dword ptr [esp + 4]
// 00833c44  8b5014               mov edx, dword ptr [eax + 0x14]
// 00833c47  52                   push edx
// 00833c48  83c118               add ecx, 0x18
// 00833c4b  e890f4ffff           call 0x8330e0
// 00833c50  8b442408             mov eax, dword ptr [esp + 8]
// 00833c54  c70000000000         mov dword ptr [eax], 0
// 00833c5a  33c0                 xor eax, eax
// 00833c5c  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnDeleteItem@CXTPTreeBase@@IAEHPAUtagNMHDR@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
