// from server: 100% by auto
// roc 2011-06 008d5990  unit: CXTPTabPaintManager  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008d5990
//
// 008d5990  8b442404             mov eax, dword ptr [esp + 4]
// 008d5994  50                   push eax
// 008d5995  e84664f8ff           call 0x85bde0
// 008d599a  59                   pop ecx
// 008d599b  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
