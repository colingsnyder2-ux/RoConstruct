// from server: 100% by auto
// roc 2009-12 0040cee0  unit: CDeclarationView  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0040cee0
//
// 0040cee0  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040cee4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0040cee8  50                   push eax
// 0040cee9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040ceed  52                   push edx
// 0040ceee  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0040cef2  50                   push eax
// 0040cef3  52                   push edx
// 0040cef4  8b542424             mov edx, dword ptr [esp + 0x24]
// 0040cef8  83ec10               sub esp, 0x10
// 0040cefb  8bc4                 mov eax, esp
// 0040cefd  8910                 mov dword ptr [eax], edx
// 0040ceff  8b542438             mov edx, dword ptr [esp + 0x38]
// 0040cf03  895004               mov dword ptr [eax + 4], edx
// 0040cf06  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0040cf0a  895008               mov dword ptr [eax + 8], edx
// 0040cf0d  8b542440             mov edx, dword ptr [esp + 0x40]
// 0040cf11  89500c               mov dword ptr [eax + 0xc], edx
// 0040cf14  e8b76e3e00           call 0x7f3dd0
// 0040cf19  c22000               ret 0x20
// library mfc-8.0/atlmfc\src\mfc\viewform.cpp (function ?accLocation@CFormView@@UAEJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewform.cpp
