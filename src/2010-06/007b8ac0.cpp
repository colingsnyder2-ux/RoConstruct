// from server: 100% by auto
// roc 2010-06 007b8ac0  unit: CXTPCommandBar  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b8ac0
//
// 007b8ac0  8b442410             mov eax, dword ptr [esp + 0x10]
// 007b8ac4  8b542408             mov edx, dword ptr [esp + 8]
// 007b8ac8  56                   push esi
// 007b8ac9  50                   push eax
// 007b8aca  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007b8ace  8bf1                 mov esi, ecx
// 007b8ad0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007b8ad4  51                   push ecx
// 007b8ad5  52                   push edx
// 007b8ad6  50                   push eax
// 007b8ad7  ff1554a19e00         call dword ptr [0x9ea154]
// 007b8add  50                   push eax
// 007b8ade  8bce                 mov ecx, esi
// 007b8ae0  e885f4feff           call 0x7a7f6a
// 007b8ae5  5e                   pop esi
// 007b8ae6  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxpanedivider.cpp (function ?CreateRectRgn@CRgn@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpanedivider.cpp
