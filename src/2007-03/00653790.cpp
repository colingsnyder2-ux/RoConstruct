// from server: 100% by auto
// roc 2007-03 00653790  unit: seg_00650000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00653790
//
// 00653790  8b442404             mov eax, dword ptr [esp + 4]
// 00653794  8b5014               mov edx, dword ptr [eax + 0x14]
// 00653797  52                   push edx
// 00653798  83c118               add ecx, 0x18
// 0065379b  e890f4ffff           call 0x652c30
// 006537a0  8b442408             mov eax, dword ptr [esp + 8]
// 006537a4  c70000000000         mov dword ptr [eax], 0
// 006537aa  33c0                 xor eax, eax
// 006537ac  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnDeleteItem@CXTPTreeBase@@IAEHPAUtagNMHDR@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
