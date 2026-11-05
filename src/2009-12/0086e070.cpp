// from server: 100% by auto
// roc 2009-12 0086e070  unit: CXTPReportColumns  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086e070
//
// 0086e070  8b01                 mov eax, dword ptr [ecx]
// 0086e072  50                   push eax
// 0086e073  e88e5af8ff           call 0x7f3b06
// 0086e078  59                   pop ecx
// 0086e079  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ?FreeHeap@?$CTempBuffer@D$0IA@VCCRTAllocator@ATL@@@ATL@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
