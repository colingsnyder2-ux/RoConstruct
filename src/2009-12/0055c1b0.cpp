// from server: 100% by auto
// roc 2009-12 0055c1b0  unit: RBX::Network::NetworkOwnerJob  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0055c1b0
//
// 0055c1b0  8bc1                 mov eax, ecx
// 0055c1b2  c7002802b200         mov dword ptr [eax], 0xb20228
// 0055c1b8  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??0Thank_you@Define_the_symbol__ATL_MIXED@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
