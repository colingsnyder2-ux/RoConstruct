// from server: 100% by auto
// roc 2012-06 0040ba20  unit: boost::exception_detail::clone_base  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040ba20
//
// 0040ba20  33c0                 xor eax, eax
// 0040ba22  83c104               add ecx, 4
// 0040ba25  8701                 xchg dword ptr [ecx], eax
// 0040ba27  85c0                 test eax, eax
// 0040ba29  7407                 je 0x40ba32
// 0040ba2b  50                   push eax
// 0040ba2c  ff15e821b200         call dword ptr [0xb221e8]
// 0040ba32  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?destroy@basic_timed_mutex@detail@boost@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
