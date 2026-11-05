// from server: 100% by auto
// roc 2007-08 00682720  unit: XTP_PRINT_STATE  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00682720
//
// 00682720  f644240401           test byte ptr [esp + 4], 1
// 00682725  56                   push esi
// 00682726  8bf1                 mov esi, ecx
// 00682728  7406                 je 0x682730
// 0068272a  56                   push esi
// 0068272b  e8f85b0b00           call 0x738328
// 00682730  8bc6                 mov eax, esi
// 00682732  5e                   pop esi
// 00682733  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxtls.cpp (function ??_GCThreadData@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxtls.cpp
