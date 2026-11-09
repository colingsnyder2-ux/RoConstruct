// from server: 100% by auto
// roc 2008-06 006fd840  unit: CXTCaptionButtonTheme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006fd840
//
// 006fd840  56                   push esi
// 006fd841  8b742408             mov esi, dword ptr [esp + 8]
// 006fd845  6a08                 push 8
// 006fd847  8d442410             lea eax, [esp + 0x10]
// 006fd84b  50                   push eax
// 006fd84c  8bce                 mov ecx, esi
// 006fd84e  e8dd38faff           call 0x6a1130
// 006fd853  8bc6                 mov eax, esi
// 006fd855  5e                   pop esi
// 006fd856  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxmdiclientareawnd.cpp (function ??6@YGAAVCArchive@@AAV0@UtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmdiclientareawnd.cpp
