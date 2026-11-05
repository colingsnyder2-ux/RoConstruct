// from server: 100% by auto
// roc 2011-06 0081af20  unit: CXTPCommandBar  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0081af20
//
// 0081af20  8b442410             mov eax, dword ptr [esp + 0x10]
// 0081af24  8b542408             mov edx, dword ptr [esp + 8]
// 0081af28  56                   push esi
// 0081af29  50                   push eax
// 0081af2a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0081af2e  8bf1                 mov esi, ecx
// 0081af30  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0081af34  51                   push ecx
// 0081af35  52                   push edx
// 0081af36  50                   push eax
// 0081af37  ff154401a400         call dword ptr [0xa40144]
// 0081af3d  50                   push eax
// 0081af3e  8bce                 mov ecx, esi
// 0081af40  e8e3f6feff           call 0x80a628
// 0081af45  5e                   pop esi
// 0081af46  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxpanedivider.cpp (function ?CreateRectRgn@CRgn@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpanedivider.cpp
