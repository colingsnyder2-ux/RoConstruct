// from server: 100% by auto
// roc 2011-06 004129f0  unit: CDeclarationView  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004129f0
//
// 004129f0  8b442410             mov eax, dword ptr [esp + 0x10]
// 004129f4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004129f8  50                   push eax
// 004129f9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004129fd  52                   push edx
// 004129fe  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00412a02  50                   push eax
// 00412a03  52                   push edx
// 00412a04  8b542424             mov edx, dword ptr [esp + 0x24]
// 00412a08  83ec10               sub esp, 0x10
// 00412a0b  8bc4                 mov eax, esp
// 00412a0d  8910                 mov dword ptr [eax], edx
// 00412a0f  8b542438             mov edx, dword ptr [esp + 0x38]
// 00412a13  895004               mov dword ptr [eax + 4], edx
// 00412a16  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 00412a1a  895008               mov dword ptr [eax + 8], edx
// 00412a1d  8b542440             mov edx, dword ptr [esp + 0x40]
// 00412a21  89500c               mov dword ptr [eax + 0xc], edx
// 00412a24  e8a57b3f00           call 0x80a5ce
// 00412a29  c22000               ret 0x20
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp (function ?accLocation@CFormView@@UAEJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewform.cpp
