// from server: 100% by auto
// roc 2011-06 00404c20  unit: ATL::CRegObject  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00404c20
//
// 00404c20  56                   push esi
// 00404c21  8bf1                 mov esi, ecx
// 00404c23  8b06                 mov eax, dword ptr [esi]
// 00404c25  50                   push eax
// 00404c26  e8d9564000           call 0x80a304
// 00404c2b  83c404               add esp, 4
// 00404c2e  c70600000000         mov dword ptr [esi], 0
// 00404c34  5e                   pop esi
// 00404c35  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dcprev.cpp (function ?Free@?$CAutoVectorPtr@D@ATL@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dcprev.cpp
