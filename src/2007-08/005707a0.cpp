// from server: 100% by auto
// roc 2007-08 005707a0  unit: RBX::Reflection::VGenericSlotWrapper::?$sp_counted_impl_p  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005707a0
//
// 005707a0  33c0                 xor eax, eax
// 005707a2  3b4c2404             cmp ecx, dword ptr [esp + 4]
// 005707a6  0f94c0               sete al
// 005707a9  c20400               ret 4
// library boost-1.36.0/libs\system\src\error_code.cpp (function ??8error_category@system@boost@@QBE_NABV012@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/system/src/error_code.cpp
