// from server: 100% by auto
// roc 2010-06 00639220  unit: G3D::VVector2int16::?$TypedPropertyDescriptor  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00639220
//
// 00639220  56                   push esi
// 00639221  8b742408             mov esi, dword ptr [esp + 8]
// 00639225  56                   push esi
// 00639226  e8c5f9ffff           call 0x638bf0
// 0063922b  8bc6                 mov eax, esi
// 0063922d  5e                   pop esi
// 0063922e  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?date@?$base_time@Vptime@posix_time@boost@@V?$counted_time_system@U?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@@date_time@3@@date_time@boost@@QBE?AV0gregorian@3@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
