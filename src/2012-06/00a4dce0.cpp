// from server: 100% by auto
// roc 2012-06 00a4dce0  unit: CXTPTabPaintManager  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a4dce0
//
// 00a4dce0  8b442404             mov eax, dword ptr [esp + 4]
// 00a4dce4  50                   push eax
// 00a4dce5  e8d664f8ff           call 0x9d41c0
// 00a4dcea  59                   pop ecx
// 00a4dceb  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
