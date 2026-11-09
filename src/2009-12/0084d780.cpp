// from server: 100% by auto
// roc 2009-12 0084d780  unit: XTP_PRINT_STATE  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084d780
//
// 0084d780  f644240401           test byte ptr [esp + 4], 1
// 0084d785  56                   push esi
// 0084d786  8bf1                 mov esi, ecx
// 0084d788  7406                 je 0x84d790
// 0084d78a  56                   push esi
// 0084d78b  e8948c0d00           call 0x926424
// 0084d790  8bc6                 mov eax, esi
// 0084d792  5e                   pop esi
// 0084d793  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxtls.cpp (function ??_GCThreadData@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxtls.cpp
