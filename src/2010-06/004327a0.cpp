// from server: 100% by auto
// roc 2010-06 004327a0  unit: CStandardOutputView  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004327a0
//
// 004327a0  8b442404             mov eax, dword ptr [esp + 4]
// 004327a4  83c004               add eax, 4
// 004327a7  b901000000           mov ecx, 1
// 004327ac  f00fc108             lock xadd dword ptr [eax], ecx
// 004327b0  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?intrusive_ptr_add_ref@@YAXPAUthread_data_base@detail@boost@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
