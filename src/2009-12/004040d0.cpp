// from server: 100% by auto
// roc 2009-12 004040d0  unit: ATL::CRegObject  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004040d0
//
// 004040d0  56                   push esi
// 004040d1  8bf1                 mov esi, ecx
// 004040d3  8b06                 mov eax, dword ptr [esi]
// 004040d5  50                   push eax
// 004040d6  e82bfa3e00           call 0x7f3b06
// 004040db  83c404               add esp, 4
// 004040de  c70600000000         mov dword ptr [esi], 0
// 004040e4  5e                   pop esi
// 004040e5  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\occsite.cpp (function ?Free@?$CAutoVectorPtr@UtagDBBINDING@@@ATL@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/occsite.cpp
