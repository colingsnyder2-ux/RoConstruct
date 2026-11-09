// from server: 100% by auto
// roc 2010-06 007e7e00  unit: CRobloxTreeCtrl  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e7e00
//
// 007e7e00  8b442404             mov eax, dword ptr [esp + 4]
// 007e7e04  8b5014               mov edx, dword ptr [eax + 0x14]
// 007e7e07  52                   push edx
// 007e7e08  83c118               add ecx, 0x18
// 007e7e0b  e890f4ffff           call 0x7e72a0
// 007e7e10  8b442408             mov eax, dword ptr [esp + 8]
// 007e7e14  c70000000000         mov dword ptr [eax], 0
// 007e7e1a  33c0                 xor eax, eax
// 007e7e1c  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?OnDeleteItem@CXTTreeBase@@IAEHPAUtagNMHDR@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
