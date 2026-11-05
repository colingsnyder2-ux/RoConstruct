// from server: 100% by auto
// roc 2007-08 004e7e50  unit: TorsoBuilder  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e7e50
//
// 004e7e50  56                   push esi
// 004e7e51  8b742408             mov esi, dword ptr [esp + 8]
// 004e7e55  56                   push esi
// 004e7e56  e895ffffff           call 0x4e7df0
// 004e7e5b  8bc6                 mov eax, esi
// 004e7e5d  5e                   pop esi
// 004e7e5e  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?date@?$base_time@Vptime@posix_time@boost@@V?$counted_time_system@U?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@@date_time@3@@date_time@boost@@QBE?AV0gregorian@3@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
