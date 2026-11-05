// from server: 100% by auto
// roc 2009-06 005f8970  unit: RBX::Reflection::EnumDescriptor  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005f8970
//
// 005f8970  33c0                 xor eax, eax
// 005f8972  3b4c2404             cmp ecx, dword ptr [esp + 4]
// 005f8976  0f94c0               sete al
// 005f8979  c20400               ret 4
// library boost-1.36.0/libs\system\src\error_code.cpp (function ??8error_category@system@boost@@QBE_NABV012@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/system/src/error_code.cpp
