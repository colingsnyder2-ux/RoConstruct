// from server: 100% by auto
// roc 2011-06 00860450  unit: CXTCaptionButtonTheme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00860450
//
// 00860450  56                   push esi
// 00860451  8b742408             mov esi, dword ptr [esp + 8]
// 00860455  6a08                 push 8
// 00860457  8d442410             lea eax, [esp + 0x10]
// 0086045b  50                   push eax
// 0086045c  8bce                 mov ecx, esi
// 0086045e  e87da7faff           call 0x80abe0
// 00860463  8bc6                 mov eax, esi
// 00860465  5e                   pop esi
// 00860466  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxmdiclientareawnd.cpp (function ??6@YGAAVCArchive@@AAV0@UtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmdiclientareawnd.cpp
