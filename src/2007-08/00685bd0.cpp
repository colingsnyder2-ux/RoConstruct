// from server: 100% by auto
// roc 2007-08 00685bd0  unit: CInstanceRecord::CNameItem  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00685bd0
//
// 00685bd0  8b442408             mov eax, dword ptr [esp + 8]
// 00685bd4  56                   push esi
// 00685bd5  8b742408             mov esi, dword ptr [esp + 8]
// 00685bd9  6a10                 push 0x10
// 00685bdb  50                   push eax
// 00685bdc  8bce                 mov ecx, esi
// 00685bde  e8b1aafaff           call 0x630694
// 00685be3  8bc6                 mov eax, esi
// 00685be5  5e                   pop esi
// 00685be6  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dockstat.cpp (function ??6@YGAAVCArchive@@AAV0@ABUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dockstat.cpp
