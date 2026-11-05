// from server: 100% by auto
// roc 2012-06 007504f0  unit: RBX::ContentProvider::UCachedContent::?$AsyncHttpCache  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007504f0
//
// 007504f0  8b442404             mov eax, dword ptr [esp + 4]
// 007504f4  56                   push esi
// 007504f5  8bf1                 mov esi, ecx
// 007504f7  50                   push eax
// 007504f8  56                   push esi
// 007504f9  e8e22ad1ff           call 0x462fe0
// 007504fe  83c408               add esp, 8
// 00750501  8bc6                 mov eax, esi
// 00750503  5e                   pop esi
// 00750504  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$time_duration@V0posix_time@boost@@V?$time_resolution_traits@Utime_resolution_traits_adapted64_impl@date_time@boost@@$04$0PECEA@$05J@date_time@2@@date_time@boost@@QAE@W4special_values@12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
