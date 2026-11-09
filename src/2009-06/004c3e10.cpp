// from server: 100% by auto
// roc 2009-06 004c3e10  unit: RBX::Network::VPlayer::?$EventDesc  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c3e10
//
// 004c3e10  33c0                 xor eax, eax
// 004c3e12  83c104               add ecx, 4
// 004c3e15  8701                 xchg dword ptr [ecx], eax
// 004c3e17  85c0                 test eax, eax
// 004c3e19  7407                 je 0x4c3e22
// 004c3e1b  50                   push eax
// 004c3e1c  ff1588e38900         call dword ptr [0x89e388]
// 004c3e22  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?destroy@basic_timed_mutex@detail@boost@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
