// from server: 100% by auto
// roc 2012-06 009931f0  unit: CXTPCommandBar  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009931f0
//
// 009931f0  8b442410             mov eax, dword ptr [esp + 0x10]
// 009931f4  8b542408             mov edx, dword ptr [esp + 8]
// 009931f8  56                   push esi
// 009931f9  50                   push eax
// 009931fa  8b44240c             mov eax, dword ptr [esp + 0xc]
// 009931fe  8bf1                 mov esi, ecx
// 00993200  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00993204  51                   push ecx
// 00993205  52                   push edx
// 00993206  50                   push eax
// 00993207  ff15c820b200         call dword ptr [0xb220c8]
// 0099320d  50                   push eax
// 0099320e  8bce                 mov ecx, esi
// 00993210  e8c3f4feff           call 0x9826d8
// 00993215  5e                   pop esi
// 00993216  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxpanedivider.cpp (function ?CreateRectRgn@CRgn@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpanedivider.cpp
