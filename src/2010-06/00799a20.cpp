// from server: 100% by auto
// roc 2010-06 00799a20  unit: RBX::Security::VContext::?$thread_specific_ptr::delete_data  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00799a20
//
// 00799a20  8b442404             mov eax, dword ptr [esp + 4]
// 00799a24  50                   push eax
// 00799a25  e870df0000           call 0x7a799a
// 00799a2a  59                   pop ecx
// 00799a2b  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
