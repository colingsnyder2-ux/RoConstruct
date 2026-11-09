// from server: 100% by auto
// roc 2008-06 0040e3e0  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040e3e0
//
// 0040e3e0  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040e3e4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0040e3e8  50                   push eax
// 0040e3e9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040e3ed  52                   push edx
// 0040e3ee  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0040e3f2  50                   push eax
// 0040e3f3  52                   push edx
// 0040e3f4  8b542424             mov edx, dword ptr [esp + 0x24]
// 0040e3f8  83ec10               sub esp, 0x10
// 0040e3fb  8bc4                 mov eax, esp
// 0040e3fd  8910                 mov dword ptr [eax], edx
// 0040e3ff  8b542438             mov edx, dword ptr [esp + 0x38]
// 0040e403  895004               mov dword ptr [eax + 4], edx
// 0040e406  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0040e40a  895008               mov dword ptr [eax + 8], edx
// 0040e40d  8b542440             mov edx, dword ptr [esp + 0x40]
// 0040e411  89500c               mov dword ptr [eax + 0xc], edx
// 0040e414  e8ef272900           call 0x6a0c08
// 0040e419  c22000               ret 0x20
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp (function ?accLocation@CFormView@@UAEJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewform.cpp
