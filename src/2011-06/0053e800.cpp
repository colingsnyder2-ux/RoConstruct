// from server: 100% by auto
// roc 2011-06 0053e800  unit: G3D::MemoryManager  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053e800
//
// 0053e800  8b442404             mov eax, dword ptr [esp + 4]
// 0053e804  50                   push eax
// 0053e805  e836040000           call 0x53ec40
// 0053e80a  59                   pop ecx
// 0053e80b  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
