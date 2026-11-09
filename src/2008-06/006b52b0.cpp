// from server: 100% by auto
// roc 2008-06 006b52b0  unit: CXTPCommandBar  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006b52b0
//
// 006b52b0  8b442410             mov eax, dword ptr [esp + 0x10]
// 006b52b4  8b542408             mov edx, dword ptr [esp + 8]
// 006b52b8  56                   push esi
// 006b52b9  50                   push eax
// 006b52ba  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006b52be  8bf1                 mov esi, ecx
// 006b52c0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006b52c4  51                   push ecx
// 006b52c5  52                   push edx
// 006b52c6  50                   push eax
// 006b52c7  ff15ac208000         call dword ptr [0x8020ac]
// 006b52cd  50                   push eax
// 006b52ce  8bce                 mov ecx, esi
// 006b52d0  e88db9feff           call 0x6a0c62
// 006b52d5  5e                   pop esi
// 006b52d6  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxpanedivider.cpp (function ?CreateRectRgn@CRgn@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpanedivider.cpp
