// from server: 100% by auto
// roc 2012-06 0062a750  unit: G3D::MemoryManager  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062a750
//
// 0062a750  8b442404             mov eax, dword ptr [esp + 4]
// 0062a754  50                   push eax
// 0062a755  e8e6030000           call 0x62ab40
// 0062a75a  59                   pop ecx
// 0062a75b  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
