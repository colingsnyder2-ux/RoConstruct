// from server: 100% by auto
// roc 2010-06 00404160  unit: ATL::CRegObject  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00404160
//
// 00404160  56                   push esi
// 00404161  8bf1                 mov esi, ecx
// 00404163  8b06                 mov eax, dword ptr [esi]
// 00404165  50                   push eax
// 00404166  e8db3a3a00           call 0x7a7c46
// 0040416b  83c404               add esp, 4
// 0040416e  c70600000000         mov dword ptr [esi], 0
// 00404174  5e                   pop esi
// 00404175  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dcprev.cpp (function ?Free@?$CAutoVectorPtr@D@ATL@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dcprev.cpp
