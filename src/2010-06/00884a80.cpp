// from server: 100% by auto
// roc 2010-06 00884a80  unit: CXTPTabPaintManager  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00884a80
//
// 00884a80  8b442404             mov eax, dword ptr [esp + 4]
// 00884a84  50                   push eax
// 00884a85  e8d698f7ff           call 0x7fe360
// 00884a8a  59                   pop ecx
// 00884a8b  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
