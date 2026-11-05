// from server: 100% by auto
// roc 2008-06 00402f90  unit: ATL::CRegObject  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402f90
//
// 00402f90  56                   push esi
// 00402f91  8bf1                 mov esi, ecx
// 00402f93  8b06                 mov eax, dword ptr [esi]
// 00402f95  50                   push eax
// 00402f96  e8afd92900           call 0x6a094a
// 00402f9b  83c404               add esp, 4
// 00402f9e  c70600000000         mov dword ptr [esi], 0
// 00402fa4  5e                   pop esi
// 00402fa5  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dcprev.cpp (function ?Free@?$CAutoVectorPtr@D@ATL@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dcprev.cpp
