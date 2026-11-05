// from server: 100% by auto
// roc 2010-06 00432810  unit: boost::detail::thread_data_base  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00432810
//
// 00432810  33c0                 xor eax, eax
// 00432812  83c104               add ecx, 4
// 00432815  8701                 xchg dword ptr [ecx], eax
// 00432817  85c0                 test eax, eax
// 00432819  7407                 je 0x432822
// 0043281b  50                   push eax
// 0043281c  ff15cca39e00         call dword ptr [0x9ea3cc]
// 00432822  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?destroy@basic_timed_mutex@detail@boost@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
