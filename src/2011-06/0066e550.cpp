// from server: 100% by auto
// roc 2011-06 0066e550  unit: RBX::VSystemAddress::?$TypedPropertyDescriptor  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0066e550
//
// 0066e550  56                   push esi
// 0066e551  8b742408             mov esi, dword ptr [esp + 8]
// 0066e555  56                   push esi
// 0066e556  e8a5f9ffff           call 0x66df00
// 0066e55b  8bc6                 mov eax, esi
// 0066e55d  5e                   pop esi
// 0066e55e  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?date@?$base_time@Vptime@posix_time@boost@@V?$counted_time_system@U?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@@date_time@3@@date_time@boost@@QBE?AV0gregorian@3@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
