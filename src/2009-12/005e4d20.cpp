// from server: 100% by auto
// roc 2009-12 005e4d20  unit: RBX::VBeveledBlockMesh::?$CustomizableMesh  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005e4d20
//
// 005e4d20  8b442408             mov eax, dword ptr [esp + 8]
// 005e4d24  56                   push esi
// 005e4d25  8bf1                 mov esi, ecx
// 005e4d27  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005e4d2b  50                   push eax
// 005e4d2c  51                   push ecx
// 005e4d2d  8bce                 mov ecx, esi
// 005e4d2f  e8bcfcffff           call 0x5e49f0
// 005e4d34  c7061c189c00         mov dword ptr [esi], 0x9c181c
// 005e4d3a  8bc6                 mov eax, esi
// 005e4d3c  5e                   pop esi
// 005e4d3d  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\ctltrack.cpp (function ??0CControlRectTracker@@QAE@PBUtagRECT@@I@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctltrack.cpp
