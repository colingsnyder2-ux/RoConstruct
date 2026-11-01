// from server: 100% by auto
// roc 2009-12 005e5050  unit: RBX::VBeveledBlockMesh::?$CustomizableMesh  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005e5050
//
// 005e5050  8b442408             mov eax, dword ptr [esp + 8]
// 005e5054  56                   push esi
// 005e5055  8bf1                 mov esi, ecx
// 005e5057  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005e505b  50                   push eax
// 005e505c  51                   push ecx
// 005e505d  8bce                 mov ecx, esi
// 005e505f  e8dcfcffff           call 0x5e4d40
// 005e5064  c70634189c00         mov dword ptr [esi], 0x9c1834
// 005e506a  8bc6                 mov eax, esi
// 005e506c  5e                   pop esi
// 005e506d  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\ctltrack.cpp (function ??0CControlRectTracker@@QAE@PBUtagRECT@@I@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctltrack.cpp
