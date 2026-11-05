// from server: 100% by auto
// roc 2007-08 004010f0  unit: CAboutRobloxDialog  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004010f0
//
// 004010f0  8b442404             mov eax, dword ptr [esp + 4]
// 004010f4  50                   push eax
// 004010f5  e868eb2200           call 0x62fc62
// 004010fa  59                   pop ecx
// 004010fb  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
