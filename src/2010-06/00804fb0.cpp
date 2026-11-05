// from server: 100% by auto
// roc 2010-06 00804fb0  unit: CXTCaptionButtonTheme  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804fb0
//
// 00804fb0  8b442408             mov eax, dword ptr [esp + 8]
// 00804fb4  56                   push esi
// 00804fb5  8b742408             mov esi, dword ptr [esp + 8]
// 00804fb9  6a08                 push 8
// 00804fbb  50                   push eax
// 00804fbc  8bce                 mov ecx, esi
// 00804fbe  e85335faff           call 0x7a8516
// 00804fc3  83f808               cmp eax, 8
// 00804fc6  7409                 je 0x804fd1
// 00804fc8  6a00                 push 0
// 00804fca  6a03                 push 3
// 00804fcc  e83f35faff           call 0x7a8510
// 00804fd1  8bc6                 mov eax, esi
// 00804fd3  5e                   pop esi
// 00804fd4  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxmdiclientareawnd.cpp (function ??5@YGAAVCArchive@@AAV0@AAUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmdiclientareawnd.cpp
