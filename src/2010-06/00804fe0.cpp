// from server: 100% by auto
// roc 2010-06 00804fe0  unit: CXTCaptionButtonTheme  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804fe0
//
// 00804fe0  8b442408             mov eax, dword ptr [esp + 8]
// 00804fe4  56                   push esi
// 00804fe5  8b742408             mov esi, dword ptr [esp + 8]
// 00804fe9  6a10                 push 0x10
// 00804feb  50                   push eax
// 00804fec  8bce                 mov ecx, esi
// 00804fee  e82335faff           call 0x7a8516
// 00804ff3  83f810               cmp eax, 0x10
// 00804ff6  7409                 je 0x805001
// 00804ff8  6a00                 push 0
// 00804ffa  6a03                 push 3
// 00804ffc  e80f35faff           call 0x7a8510
// 00805001  8bc6                 mov eax, esi
// 00805003  5e                   pop esi
// 00805004  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxdockablepane.cpp (function ??5@YGAAVCArchive@@AAV0@AAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockablepane.cpp
