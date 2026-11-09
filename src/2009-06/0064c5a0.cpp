// from server: 100% by auto
// roc 2009-06 0064c5a0  unit: std::D::DU?$char_traits::DV?$basic_streambuf::?$lexical_stream_limited_src  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0064c5a0
//
// 0064c5a0  8b442404             mov eax, dword ptr [esp + 4]
// 0064c5a4  56                   push esi
// 0064c5a5  8bf1                 mov esi, ecx
// 0064c5a7  50                   push eax
// 0064c5a8  56                   push esi
// 0064c5a9  e802c4fbff           call 0x6089b0
// 0064c5ae  83c408               add esp, 8
// 0064c5b1  8bc6                 mov eax, esi
// 0064c5b3  5e                   pop esi
// 0064c5b4  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$time_duration@V0posix_time@boost@@V?$time_resolution_traits@Utime_resolution_traits_adapted64_impl@date_time@boost@@$04$0PECEA@$05J@date_time@2@@date_time@boost@@QAE@W4special_values@12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
