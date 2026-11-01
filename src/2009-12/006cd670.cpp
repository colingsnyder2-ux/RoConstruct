// from server: 100% by auto
// roc 2009-12 006cd670  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006cd670
//
// 006cd670  56                   push esi
// 006cd671  8b742408             mov esi, dword ptr [esp + 8]
// 006cd675  56                   push esi
// 006cd676  e8c5f9ffff           call 0x6cd040
// 006cd67b  8bc6                 mov eax, esi
// 006cd67d  5e                   pop esi
// 006cd67e  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?date@?$base_time@Vptime@posix_time@boost@@V?$counted_time_system@U?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@@date_time@3@@date_time@boost@@QBE?AV0gregorian@3@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
