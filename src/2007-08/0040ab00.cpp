// from server: 100% by auto
// roc 2007-08 0040ab00  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040ab00
//
// 0040ab00  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040ab04  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0040ab08  50                   push eax
// 0040ab09  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040ab0d  52                   push edx
// 0040ab0e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0040ab12  50                   push eax
// 0040ab13  52                   push edx
// 0040ab14  8b542424             mov edx, dword ptr [esp + 0x24]
// 0040ab18  83ec10               sub esp, 0x10
// 0040ab1b  8bc4                 mov eax, esp
// 0040ab1d  8910                 mov dword ptr [eax], edx
// 0040ab1f  8b542438             mov edx, dword ptr [esp + 0x38]
// 0040ab23  895004               mov dword ptr [eax + 4], edx
// 0040ab26  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0040ab2a  895008               mov dword ptr [eax + 8], edx
// 0040ab2d  8b542440             mov edx, dword ptr [esp + 0x40]
// 0040ab31  89500c               mov dword ptr [eax + 0xc], edx
// 0040ab34  e89f562200           call 0x6301d8
// 0040ab39  c22000               ret 0x20
// library mfc-8.0/atlmfc\src\mfc\viewform.cpp (function ?accLocation@CFormView@@UAEJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewform.cpp
