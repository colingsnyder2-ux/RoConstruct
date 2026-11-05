// from server: 100% by auto
// roc 2012-06 00405260  unit: VCApp::?$CComObject  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00405260
//
// 00405260  56                   push esi
// 00405261  8bf1                 mov esi, ecx
// 00405263  8b06                 mov eax, dword ptr [esi]
// 00405265  50                   push eax
// 00405266  e84fd15700           call 0x9823ba
// 0040526b  83c404               add esp, 4
// 0040526e  c70600000000         mov dword ptr [esi], 0
// 00405274  5e                   pop esi
// 00405275  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dcprev.cpp (function ?Free@?$CAutoVectorPtr@D@ATL@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dcprev.cpp
