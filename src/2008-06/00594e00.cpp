// from server: 100% by auto
// roc 2008-06 00594e00  unit: RBX::Lua::ThreadRef::VNode::?$sp_counted_impl_p  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00594e00
//
// 00594e00  8b442404             mov eax, dword ptr [esp + 4]
// 00594e04  56                   push esi
// 00594e05  8bf1                 mov esi, ecx
// 00594e07  50                   push eax
// 00594e08  56                   push esi
// 00594e09  e8323c0800           call 0x618a40
// 00594e0e  83c408               add esp, 8
// 00594e11  8bc6                 mov eax, esi
// 00594e13  5e                   pop esi
// 00594e14  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$time_duration@V0posix_time@boost@@V?$time_resolution_traits@Utime_resolution_traits_adapted64_impl@date_time@boost@@$04$0PECEA@$05J@date_time@2@@date_time@boost@@QAE@W4special_values@12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
