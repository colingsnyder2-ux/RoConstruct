// from server: 100% by auto
// roc 2012-06 006c80e0  unit: RBX::GlobalAdvancedSettings  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c80e0
//
// 006c80e0  33c0                 xor eax, eax
// 006c80e2  3b4c2404             cmp ecx, dword ptr [esp + 4]
// 006c80e6  0f94c0               sete al
// 006c80e9  c20400               ret 4
// library boost-1.36.0/libs\system\src\error_code.cpp (function ??8error_category@system@boost@@QBE_NABV012@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/system/src/error_code.cpp
