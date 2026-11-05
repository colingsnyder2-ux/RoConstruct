// from server: 100% by auto
// roc 2008-06 00401110  unit: CAboutRobloxDialog  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401110
//
// 00401110  8b442404             mov eax, dword ptr [esp + 4]
// 00401114  50                   push eax
// 00401115  e860f52900           call 0x6a067a
// 0040111a  59                   pop ecx
// 0040111b  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
