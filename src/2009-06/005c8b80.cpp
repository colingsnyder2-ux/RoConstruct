// from server: 100% by auto
// roc 2009-06 005c8b80  unit: seg_005c0000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c8b80
//
// 005c8b80  8b442404             mov eax, dword ptr [esp + 4]
// 005c8b84  50                   push eax
// 005c8b85  e8867f0800           call 0x650b10
// 005c8b8a  59                   pop ecx
// 005c8b8b  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
