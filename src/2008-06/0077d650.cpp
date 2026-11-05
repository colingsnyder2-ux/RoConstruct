// from server: 100% by auto
// roc 2008-06 0077d650  unit: CXTPTabPaintManager  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0077d650
//
// 0077d650  8b442404             mov eax, dword ptr [esp + 4]
// 0077d654  50                   push eax
// 0077d655  e83695f7ff           call 0x6f6b90
// 0077d65a  59                   pop ecx
// 0077d65b  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
