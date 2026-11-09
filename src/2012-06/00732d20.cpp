// from server: 100% by auto
// roc 2012-06 00732d20  unit: RBX::VScreenGui::?$FactoryProduct  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00732d20
//
// 00732d20  56                   push esi
// 00732d21  8b742408             mov esi, dword ptr [esp + 8]
// 00732d25  56                   push esi
// 00732d26  e845340b00           call 0x7e6170
// 00732d2b  8bc6                 mov eax, esi
// 00732d2d  5e                   pop esi
// 00732d2e  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?date@?$base_time@Vptime@posix_time@boost@@V?$counted_time_system@U?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@@date_time@3@@date_time@boost@@QBE?AV0gregorian@3@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
