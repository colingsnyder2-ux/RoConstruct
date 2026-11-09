// from server: 100% by auto
// roc 2008-06 006fd880  unit: CXTCaptionButtonTheme  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006fd880
//
// 006fd880  8b442408             mov eax, dword ptr [esp + 8]
// 006fd884  56                   push esi
// 006fd885  8b742408             mov esi, dword ptr [esp + 8]
// 006fd889  6a08                 push 8
// 006fd88b  50                   push eax
// 006fd88c  8bce                 mov ecx, esi
// 006fd88e  e89738faff           call 0x6a112a
// 006fd893  83f808               cmp eax, 8
// 006fd896  7409                 je 0x6fd8a1
// 006fd898  6a00                 push 0
// 006fd89a  6a03                 push 3
// 006fd89c  e88338faff           call 0x6a1124
// 006fd8a1  8bc6                 mov eax, esi
// 006fd8a3  5e                   pop esi
// 006fd8a4  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxmdiclientareawnd.cpp (function ??5@YGAAVCArchive@@AAV0@AAUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmdiclientareawnd.cpp
