// from server: 100% by auto
// roc 2010-06 006319c0  unit: std::D::DU?$char_traits::?$basic_ifstream  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006319c0
//
// 006319c0  8b442404             mov eax, dword ptr [esp + 4]
// 006319c4  56                   push esi
// 006319c5  8bf1                 mov esi, ecx
// 006319c7  50                   push eax
// 006319c8  56                   push esi
// 006319c9  e8f27deaff           call 0x4d97c0
// 006319ce  83c408               add esp, 8
// 006319d1  8bc6                 mov eax, esi
// 006319d3  5e                   pop esi
// 006319d4  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$time_duration@V0posix_time@boost@@V?$time_resolution_traits@Utime_resolution_traits_adapted64_impl@date_time@boost@@$04$0PECEA@$05J@date_time@2@@date_time@boost@@QAE@W4special_values@12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
