// from server: 100% by auto
// roc 2009-06 00708ae0  unit: RBX::Log  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00708ae0
//
// 00708ae0  a1fc04a500           mov eax, dword ptr [0xa504fc]
// 00708ae5  85c0                 test eax, eax
// 00708ae7  7411                 je 0x708afa
// 00708ae9  50                   push eax
// 00708aea  ff1508e38900         call dword ptr [0x89e308]
// 00708af0  c705fc04a50000000000 mov dword ptr [0xa504fc], 0
// 00708afa  c3                   ret 
// library boost-1.40.0/libs\thread\src\win32\thread.cpp (function ?cleanup_tls_key@?A0x5a945078@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/thread/src/win32/thread.cpp
