// from server: 100% by auto
// roc 2011-06 006905d0  unit: RBX::VGuiBase::?$NonFactoryProduct  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006905d0
//
// 006905d0  56                   push esi
// 006905d1  8b742408             mov esi, dword ptr [esp + 8]
// 006905d5  56                   push esi
// 006905d6  e855190900           call 0x721f30
// 006905db  8bc6                 mov eax, esi
// 006905dd  5e                   pop esi
// 006905de  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?date@?$base_time@Vptime@posix_time@boost@@V?$counted_time_system@U?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@@date_time@3@@date_time@boost@@QBE?AV0gregorian@3@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
