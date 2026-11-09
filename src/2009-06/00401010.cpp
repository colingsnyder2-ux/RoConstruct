// from server: 100% by auto
// roc 2009-06 00401010  unit: RBX::Security::VContext::?$thread_specific_ptr::delete_data  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00401010
//
// 00401010  8b442404             mov eax, dword ptr [esp + 4]
// 00401014  50                   push eax
// 00401015  e8187a3100           call 0x718a32
// 0040101a  59                   pop ecx
// 0040101b  c20400               ret 4
// library rbx2016-g3d/MemoryManager.cpp (function ?free@MemoryManager@G3D@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d MemoryManager.cpp
