// from server: 100% by auto
// roc 2009-12 0084b6e0  unit: CXTPBitmapDC  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084b6e0
//
// 0084b6e0  56                   push esi
// 0084b6e1  8bf1                 mov esi, ecx
// 0084b6e3  c706b0bb9f00         mov dword ptr [esi], 0x9fbbb0
// 0084b6e9  e8f2eaffff           call 0x84a1e0
// 0084b6ee  8bce                 mov ecx, esi
// 0084b6f0  5e                   pop esi
// 0084b6f1  e91aebffff           jmp 0x84a210
// library mfc-8.0/atlmfc\src\mfc\bardlg.cpp (function ??1CDialogBar@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bardlg.cpp
