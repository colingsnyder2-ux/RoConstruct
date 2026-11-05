// from server: 100% by auto
// roc 2009-06 007761a0  unit: CXTPPropExchangeXMLNode  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007761a0
//
// 007761a0  56                   push esi
// 007761a1  8b742408             mov esi, dword ptr [esp + 8]
// 007761a5  6a08                 push 8
// 007761a7  8d442410             lea eax, [esp + 0x10]
// 007761ab  50                   push eax
// 007761ac  8bce                 mov ecx, esi
// 007761ae  e8fb33faff           call 0x7195ae
// 007761b3  8bc6                 mov eax, esi
// 007761b5  5e                   pop esi
// 007761b6  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxmdiclientareawnd.cpp (function ??6@YGAAVCArchive@@AAV0@UtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmdiclientareawnd.cpp
