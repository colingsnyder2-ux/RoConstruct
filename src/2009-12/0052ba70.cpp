// from server: 100% by auto
// roc 2009-12 0052ba70  unit: RBX::Network::PhysicsSender::Job  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052ba70
//
// 0052ba70  8bc1                 mov eax, ecx
// 0052ba72  c70044c79b00         mov dword ptr [eax], 0x9bc744
// 0052ba78  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??0Thank_you@Define_the_symbol__ATL_MIXED@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
