// from server: 100% by auto
// roc 2009-06 007761e0  unit: CXTPPropExchangeXMLNode  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007761e0
//
// 007761e0  8b442408             mov eax, dword ptr [esp + 8]
// 007761e4  56                   push esi
// 007761e5  8b742408             mov esi, dword ptr [esp + 8]
// 007761e9  6a08                 push 8
// 007761eb  50                   push eax
// 007761ec  8bce                 mov ecx, esi
// 007761ee  e8b533faff           call 0x7195a8
// 007761f3  83f808               cmp eax, 8
// 007761f6  7409                 je 0x776201
// 007761f8  6a00                 push 0
// 007761fa  6a03                 push 3
// 007761fc  e8a133faff           call 0x7195a2
// 00776201  8bc6                 mov eax, esi
// 00776203  5e                   pop esi
// 00776204  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxmdiclientareawnd.cpp (function ??5@YGAAVCArchive@@AAV0@AAUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmdiclientareawnd.cpp
