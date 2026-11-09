// from server: 100% by auto
// roc 2009-06 0040cf80  unit: CDeclarationView  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040cf80
//
// 0040cf80  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040cf84  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0040cf88  50                   push eax
// 0040cf89  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040cf8d  52                   push edx
// 0040cf8e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0040cf92  50                   push eax
// 0040cf93  52                   push edx
// 0040cf94  8b542424             mov edx, dword ptr [esp + 0x24]
// 0040cf98  83ec10               sub esp, 0x10
// 0040cf9b  8bc4                 mov eax, esp
// 0040cf9d  8910                 mov dword ptr [eax], edx
// 0040cf9f  8b542438             mov edx, dword ptr [esp + 0x38]
// 0040cfa3  895004               mov dword ptr [eax + 4], edx
// 0040cfa6  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0040cfaa  895008               mov dword ptr [eax + 8], edx
// 0040cfad  8b542440             mov edx, dword ptr [esp + 0x40]
// 0040cfb1  89500c               mov dword ptr [eax + 0xc], edx
// 0040cfb4  e8e3bf3000           call 0x718f9c
// 0040cfb9  c22000               ret 0x20
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp (function ?accLocation@CFormView@@UAEJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewform.cpp
