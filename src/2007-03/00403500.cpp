// from server: 100% by auto
// roc 2007-03 00403500  unit: seg_00400000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00403500
//
// 00403500  56                   push esi
// 00403501  8bf1                 mov esi, ecx
// 00403503  8b06                 mov eax, dword ptr [esi]
// 00403505  50                   push eax
// 00403506  e8a9ae2100           call 0x61e3b4
// 0040350b  83c404               add esp, 4
// 0040350e  c70600000000         mov dword ptr [esi], 0
// 00403514  5e                   pop esi
// 00403515  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\occsite.cpp (function ?Free@?$CAutoVectorPtr@UtagDBBINDING@@@ATL@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/occsite.cpp
