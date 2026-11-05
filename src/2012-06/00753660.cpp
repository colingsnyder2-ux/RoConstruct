// from server: 100% by auto
// roc 2012-06 00753660  unit: RBX::VSystemAddress::?$TypedPropertyDescriptor  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00753660
//
// 00753660  56                   push esi
// 00753661  8b742408             mov esi, dword ptr [esp + 8]
// 00753665  56                   push esi
// 00753666  e885fbffff           call 0x7531f0
// 0075366b  8bc6                 mov eax, esi
// 0075366d  5e                   pop esi
// 0075366e  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?date@?$base_time@Vptime@posix_time@boost@@V?$counted_time_system@U?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@@date_time@3@@date_time@boost@@QBE?AV0gregorian@3@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
