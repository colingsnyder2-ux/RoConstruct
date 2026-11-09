// from server: 100% by auto
// roc 2007-08 00418c70  unit: boost::signals::detail::slot_base::Udata_t::?$sp_counted_impl_p  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00418c70
//
// 00418c70  e85bf8ffff           call 0x4184d0
// 00418c75  a3ccaf8b00           mov dword ptr [0x8bafcc], eax
// 00418c7a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
