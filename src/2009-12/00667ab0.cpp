// from server: 100% by auto
// roc 2009-12 00667ab0  unit: RBX::SimpleThrottlingArbiter  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00667ab0
//
// 00667ab0  8b01                 mov eax, dword ptr [ecx]
// 00667ab2  50                   push eax
// 00667ab3  e8a2bd1800           call 0x7f385a
// 00667ab8  59                   pop ecx
// 00667ab9  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ?FreeHeap@?$CTempBuffer@D$0IA@VCCRTAllocator@ATL@@@ATL@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
