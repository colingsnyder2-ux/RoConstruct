// from server: 100% by auto
// roc 2012-06 0046e620  unit: RBX::Security::VContext::?$thread_specific_ptr::delete_data  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046e620
//
// 0046e620  8b442404             mov eax, dword ptr [esp + 4]
// 0046e624  50                   push eax
// 0046e625  e8ea3a5100           call 0x982114
// 0046e62a  59                   pop ecx
// 0046e62b  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
