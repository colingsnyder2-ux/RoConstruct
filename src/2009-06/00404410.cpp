// from server: 100% by auto
// roc 2009-06 00404410  unit: ATL::CRegObject  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00404410
//
// 00404410  56                   push esi
// 00404411  8bf1                 mov esi, ecx
// 00404413  8b06                 mov eax, dword ptr [esi]
// 00404415  50                   push eax
// 00404416  e8c3483100           call 0x718cde
// 0040441b  83c404               add esp, 4
// 0040441e  c70600000000         mov dword ptr [esi], 0
// 00404424  5e                   pop esi
// 00404425  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dcprev.cpp (function ?Free@?$CAutoVectorPtr@D@ATL@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dcprev.cpp
