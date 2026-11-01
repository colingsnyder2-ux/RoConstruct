// from server: 100% by auto
// roc 2009-12 006c5c20  unit: std::D::DU?$char_traits::?$basic_istringstream  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c5c20
//
// 006c5c20  8b442404             mov eax, dword ptr [esp + 4]
// 006c5c24  56                   push esi
// 006c5c25  8bf1                 mov esi, ecx
// 006c5c27  50                   push eax
// 006c5c28  56                   push esi
// 006c5c29  e802a7d4ff           call 0x410330
// 006c5c2e  83c408               add esp, 8
// 006c5c31  8bc6                 mov eax, esi
// 006c5c33  5e                   pop esi
// 006c5c34  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$time_duration@V0posix_time@boost@@V?$time_resolution_traits@Utime_resolution_traits_adapted64_impl@date_time@boost@@$04$0PECEA@$05J@date_time@2@@date_time@boost@@QAE@W4special_values@12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
