// from server: 100% by auto
// roc 2009-06 00705630  unit: boost::thread_resource_error  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00705630
//
// 00705630  8b442408             mov eax, dword ptr [esp + 8]
// 00705634  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00705638  83ec10               sub esp, 0x10
// 0070563b  6a00                 push 0
// 0070563d  50                   push eax
// 0070563e  51                   push ecx
// 0070563f  6a00                 push 0
// 00705641  ff15f4e28900         call dword ptr [0x89e2f4]
// 00705647  85c0                 test eax, eax
// 00705649  7517                 jne 0x705662
// 0070564b  8d0c24               lea ecx, [esp]
// 0070564e  e89dffffff           call 0x7055f0
// 00705653  68e8af9700           push 0x97afe8
// 00705658  8d542404             lea edx, [esp + 4]
// 0070565c  52                   push edx
// 0070565d  e8e8430100           call 0x719a4a
// 00705662  83c410               add esp, 0x10
// 00705665  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?create_anonymous_event@win32@detail@boost@@YAPAXW4event_type@123@W4initial_event_state@123@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
