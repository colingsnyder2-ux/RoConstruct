// from server: 100% by auto
// roc 2007-08 00403620  unit: ATL::CRegObject  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00403620
//
// 00403620  56                   push esi
// 00403621  8bf1                 mov esi, ecx
// 00403623  8b06                 mov eax, dword ptr [esi]
// 00403625  50                   push eax
// 00403626  e8fbc82200           call 0x62ff26
// 0040362b  83c404               add esp, 4
// 0040362e  c70600000000         mov dword ptr [esi], 0
// 00403634  5e                   pop esi
// 00403635  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\occsite.cpp (function ?Free@?$CAutoVectorPtr@UtagDBBINDING@@@ATL@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/occsite.cpp
