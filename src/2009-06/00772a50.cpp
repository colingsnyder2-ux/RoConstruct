// from server: 100% by auto
// roc 2009-06 00772a50  unit: XTP_PRINT_STATE  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00772a50
//
// 00772a50  f644240401           test byte ptr [esp + 4], 1
// 00772a55  56                   push esi
// 00772a56  8bf1                 mov esi, ecx
// 00772a58  7406                 je 0x772a60
// 00772a5a  56                   push esi
// 00772a5b  e864940d00           call 0x84bec4
// 00772a60  8bc6                 mov eax, esi
// 00772a62  5e                   pop esi
// 00772a63  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtls.cpp (function ??_GCThreadData@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtls.cpp
