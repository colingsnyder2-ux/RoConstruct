// from server: 100% by auto
// roc 2009-06 007761c0  unit: CXTPPropExchangeXMLNode  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007761c0
//
// 007761c0  8b442408             mov eax, dword ptr [esp + 8]
// 007761c4  56                   push esi
// 007761c5  8b742408             mov esi, dword ptr [esp + 8]
// 007761c9  6a10                 push 0x10
// 007761cb  50                   push eax
// 007761cc  8bce                 mov ecx, esi
// 007761ce  e8db33faff           call 0x7195ae
// 007761d3  8bc6                 mov eax, esi
// 007761d5  5e                   pop esi
// 007761d6  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxdockablepane.cpp (function ??6@YGAAVCArchive@@AAV0@ABUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockablepane.cpp
