// from server: 100% by auto
// roc 2007-08 006ffa40  unit: CXTPTabPaintManager  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006ffa40
//
// 006ffa40  8b442404             mov eax, dword ptr [esp + 4]
// 006ffa44  50                   push eax
// 006ffa45  e846faf7ff           call 0x67f490
// 006ffa4a  59                   pop ecx
// 006ffa4b  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
