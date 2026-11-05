// from server: 100% by auto
// roc 2011-06 0045b5c0  unit: RBX::Security::VContext::?$thread_specific_ptr::delete_data  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0045b5c0
//
// 0045b5c0  8b442404             mov eax, dword ptr [esp + 4]
// 0045b5c4  50                   push eax
// 0045b5c5  e88eea3a00           call 0x80a058
// 0045b5ca  59                   pop ecx
// 0045b5cb  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
