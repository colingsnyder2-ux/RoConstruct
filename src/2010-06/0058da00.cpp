// from server: 100% by auto
// roc 2010-06 0058da00  unit: seg_00580000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0058da00
//
// 0058da00  8b442404             mov eax, dword ptr [esp + 4]
// 0058da04  50                   push eax
// 0058da05  e8168b0a00           call 0x636520
// 0058da0a  59                   pop ecx
// 0058da0b  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
