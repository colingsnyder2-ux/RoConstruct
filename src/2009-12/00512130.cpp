// from server: 100% by auto
// roc 2009-12 00512130  unit: RBX::Network::VPlayer::?$EventDesc  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00512130
//
// 00512130  8b442404             mov eax, dword ptr [esp + 4]
// 00512134  83c004               add eax, 4
// 00512137  b901000000           mov ecx, 1
// 0051213c  f00fc108             lock xadd dword ptr [eax], ecx
// 00512140  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?intrusive_ptr_add_ref@@YAXPAUthread_data_base@detail@boost@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
