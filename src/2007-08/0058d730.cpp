// from server: 100% by auto
// roc 2007-08 0058d730  unit: RBX::SoundService  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0058d730
//
// 0058d730  8b442404             mov eax, dword ptr [esp + 4]
// 0058d734  56                   push esi
// 0058d735  8bf1                 mov esi, ecx
// 0058d737  50                   push eax
// 0058d738  56                   push esi
// 0058d739  e832fff0ff           call 0x49d670
// 0058d73e  83c408               add esp, 8
// 0058d741  8bc6                 mov eax, esi
// 0058d743  5e                   pop esi
// 0058d744  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$time_duration@V0posix_time@boost@@V?$time_resolution_traits@Utime_resolution_traits_adapted64_impl@date_time@boost@@$04$0PECEA@$05J@date_time@2@@date_time@boost@@QAE@W4special_values@12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
