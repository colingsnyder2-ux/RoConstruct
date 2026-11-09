// from server: 100% by auto
// roc 2011-06 0058bfc0  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0058bfc0
//
// 0058bfc0  8b442404             mov eax, dword ptr [esp + 4]
// 0058bfc4  50                   push eax
// 0058bfc5  e826ef0d00           call 0x66aef0
// 0058bfca  59                   pop ecx
// 0058bfcb  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
