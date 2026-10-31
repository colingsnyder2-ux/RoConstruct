// from server: 100% by EspClaude
// roc 2009-06 00422d70  unit: VThreadLogManager::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00422d70
//
// 00422d70  8b442404             mov eax, dword ptr [esp + 4]
// 00422d74  83ec0c               sub esp, 0xc
// 00422d77  50                   push eax
// 00422d78  6a00                 push 0
// 00422d7a  ff1530e28900         call dword ptr [0x89e230]
// 00422d80  50                   push eax
// 00422d81  ff1524e28900         call dword ptr [0x89e224]
// 00422d87  85c0                 test eax, eax
// 00422d89  7528                 jne 0x422db3
// 00422d8b  6a01                 push 1
// 00422d8d  688c039e00           push 0x9e038c
// 00422d92  8d4c2408             lea ecx, [esp + 8]
// 00422d96  ff154ce98900         call dword ptr [0x89e94c]
// 00422d9c  6888919700           push 0x979188
// 00422da1  8d4c2404             lea ecx, [esp + 4]
// 00422da5  51                   push ecx
// 00422da6  c744240838c98a00     mov dword ptr [esp + 8], 0x8ac938
// 00422dae  e8976c2f00           call 0x719a4a
// 00422db3  83c40c               add esp, 0xc
// 00422db6  c3                   ret 
// copied from an identical function in another client (function ?allocate_raw_heap_memory@detail@boost@@YAPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.35.0-dll libs/thread/src/win32/thread.cpp