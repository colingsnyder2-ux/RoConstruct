// from server: 100% by auto
// roc 2009-06 007f5cf0  unit: CXTPTabPaintManager  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f5cf0
//
// 007f5cf0  8b442404             mov eax, dword ptr [esp + 4]
// 007f5cf4  50                   push eax
// 007f5cf5  e83698f7ff           call 0x76f530
// 007f5cfa  59                   pop ecx
// 007f5cfb  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
