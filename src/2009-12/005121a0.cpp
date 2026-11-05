// from server: 100% by auto
// roc 2009-12 005121a0  unit: boost::detail::thread_data_base  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005121a0
//
// 005121a0  33c0                 xor eax, eax
// 005121a2  83c104               add ecx, 4
// 005121a5  8701                 xchg dword ptr [ecx], eax
// 005121a7  85c0                 test eax, eax
// 005121a9  7407                 je 0x5121b2
// 005121ab  50                   push eax
// 005121ac  ff155cb29800         call dword ptr [0x98b25c]
// 005121b2  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?destroy@basic_timed_mutex@detail@boost@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
