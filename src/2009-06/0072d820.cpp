// from server: 100% by auto
// roc 2009-06 0072d820  unit: CXTPCommandBar  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0072d820
//
// 0072d820  8b442410             mov eax, dword ptr [esp + 0x10]
// 0072d824  8b542408             mov edx, dword ptr [esp + 8]
// 0072d828  56                   push esi
// 0072d829  50                   push eax
// 0072d82a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0072d82e  8bf1                 mov esi, ecx
// 0072d830  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0072d834  51                   push ecx
// 0072d835  52                   push edx
// 0072d836  50                   push eax
// 0072d837  ff15cce08900         call dword ptr [0x89e0cc]
// 0072d83d  50                   push eax
// 0072d83e  8bce                 mov ecx, esi
// 0072d840  e8bdb7feff           call 0x719002
// 0072d845  5e                   pop esi
// 0072d846  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxpanedivider.cpp (function ?CreateRectRgn@CRgn@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpanedivider.cpp
