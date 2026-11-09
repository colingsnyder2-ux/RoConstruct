// from server: 100% by auto
// roc 2011-06 0081af50  unit: CXTPCommandBar  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0081af50
//
// 0081af50  8b442414             mov eax, dword ptr [esp + 0x14]
// 0081af54  8b542410             mov edx, dword ptr [esp + 0x10]
// 0081af58  8b4904               mov ecx, dword ptr [ecx + 4]
// 0081af5b  50                   push eax
// 0081af5c  8b442410             mov eax, dword ptr [esp + 0x10]
// 0081af60  52                   push edx
// 0081af61  8b542410             mov edx, dword ptr [esp + 0x10]
// 0081af65  50                   push eax
// 0081af66  8b442410             mov eax, dword ptr [esp + 0x10]
// 0081af6a  52                   push edx
// 0081af6b  50                   push eax
// 0081af6c  51                   push ecx
// 0081af6d  ff150401a400         call dword ptr [0xa40104]
// 0081af73  c21400               ret 0x14
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?PatBlt@CDC@@QAEHHHHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
