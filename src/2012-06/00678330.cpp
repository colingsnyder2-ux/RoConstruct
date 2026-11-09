// from server: 100% by auto
// roc 2012-06 00678330  unit: DummyArbiter  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00678330
//
// 00678330  8b442404             mov eax, dword ptr [esp + 4]
// 00678334  50                   push eax
// 00678335  e8d6a61100           call 0x792a10
// 0067833a  59                   pop ecx
// 0067833b  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
