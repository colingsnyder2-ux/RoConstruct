// from server: 100% by auto
// roc 2007-03 0066dc10  unit: seg_00660000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066dc10
//
// 0066dc10  f644240401           test byte ptr [esp + 4], 1
// 0066dc15  56                   push esi
// 0066dc16  8bf1                 mov esi, ecx
// 0066dc18  7406                 je 0x66dc20
// 0066dc1a  56                   push esi
// 0066dc1b  e854ce0c00           call 0x73aa74
// 0066dc20  8bc6                 mov eax, esi
// 0066dc22  5e                   pop esi
// 0066dc23  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxtls.cpp (function ??_GCThreadData@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxtls.cpp
