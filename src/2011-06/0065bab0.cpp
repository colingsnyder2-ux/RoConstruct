// from server: 100% by auto
// roc 2011-06 0065bab0  unit: RBX::ContentProvider::UCachedContent::?$AsyncHttpCache  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0065bab0
//
// 0065bab0  8b442404             mov eax, dword ptr [esp + 4]
// 0065bab4  56                   push esi
// 0065bab5  8bf1                 mov esi, ecx
// 0065bab7  50                   push eax
// 0065bab8  56                   push esi
// 0065bab9  e8625a0c00           call 0x721520
// 0065babe  83c408               add esp, 8
// 0065bac1  8bc6                 mov eax, esi
// 0065bac3  5e                   pop esi
// 0065bac4  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$time_duration@V0posix_time@boost@@V?$time_resolution_traits@Utime_resolution_traits_adapted64_impl@date_time@boost@@$04$0PECEA@$05J@date_time@2@@date_time@boost@@QAE@W4special_values@12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
