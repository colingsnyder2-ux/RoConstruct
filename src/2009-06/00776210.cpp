// from server: 100% by auto
// roc 2009-06 00776210  unit: CXTPPropExchangeXMLNode  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00776210
//
// 00776210  8b442408             mov eax, dword ptr [esp + 8]
// 00776214  56                   push esi
// 00776215  8b742408             mov esi, dword ptr [esp + 8]
// 00776219  6a10                 push 0x10
// 0077621b  50                   push eax
// 0077621c  8bce                 mov ecx, esi
// 0077621e  e88533faff           call 0x7195a8
// 00776223  83f810               cmp eax, 0x10
// 00776226  7409                 je 0x776231
// 00776228  6a00                 push 0
// 0077622a  6a03                 push 3
// 0077622c  e87133faff           call 0x7195a2
// 00776231  8bc6                 mov eax, esi
// 00776233  5e                   pop esi
// 00776234  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxdockablepane.cpp (function ??5@YGAAVCArchive@@AAV0@AAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockablepane.cpp
