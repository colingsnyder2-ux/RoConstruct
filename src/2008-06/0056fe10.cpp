// from server: 100% by auto
// roc 2008-06 0056fe10  unit: RBX::W4NormalId::?$EnumDesc  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056fe10
//
// 0056fe10  33c0                 xor eax, eax
// 0056fe12  3b4c2404             cmp ecx, dword ptr [esp + 4]
// 0056fe16  0f94c0               sete al
// 0056fe19  c20400               ret 4
// library boost-1.36.0/libs\system\src\error_code.cpp (function ??8error_category@system@boost@@QBE_NABV012@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/system/src/error_code.cpp
