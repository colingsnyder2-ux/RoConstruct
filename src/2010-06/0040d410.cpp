// from server: 100% by auto
// roc 2010-06 0040d410  unit: CDeclarationView  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040d410
//
// 0040d410  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040d414  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0040d418  50                   push eax
// 0040d419  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040d41d  52                   push edx
// 0040d41e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0040d422  50                   push eax
// 0040d423  52                   push edx
// 0040d424  8b542424             mov edx, dword ptr [esp + 0x24]
// 0040d428  83ec10               sub esp, 0x10
// 0040d42b  8bc4                 mov eax, esp
// 0040d42d  8910                 mov dword ptr [eax], edx
// 0040d42f  8b542438             mov edx, dword ptr [esp + 0x38]
// 0040d433  895004               mov dword ptr [eax + 4], edx
// 0040d436  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0040d43a  895008               mov dword ptr [eax + 8], edx
// 0040d43d  8b542440             mov edx, dword ptr [esp + 0x40]
// 0040d441  89500c               mov dword ptr [eax + 0xc], edx
// 0040d444  e8c7aa3900           call 0x7a7f10
// 0040d449  c22000               ret 0x20
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp (function ?accLocation@CFormView@@UAEJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewform.cpp
