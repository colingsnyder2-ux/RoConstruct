// from server: 100% by auto
// roc 2009-12 0048a090  unit: seg_00480000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048a090
//
// 0048a090  8b01                 mov eax, dword ptr [ecx]
// 0048a092  50                   push eax
// 0048a093  e8a8fcffff           call 0x489d40
// 0048a098  59                   pop ecx
// 0048a099  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ?FreeHeap@?$CTempBuffer@D$0IA@VCCRTAllocator@ATL@@@ATL@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
