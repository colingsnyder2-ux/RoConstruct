// from server: 100% by auto
// roc 2009-06 0040cf10  unit: CDeclarationView  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040cf10
//
// 0040cf10  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040cf14  8b542404             mov edx, dword ptr [esp + 4]
// 0040cf18  50                   push eax
// 0040cf19  83ec10               sub esp, 0x10
// 0040cf1c  8bc4                 mov eax, esp
// 0040cf1e  8910                 mov dword ptr [eax], edx
// 0040cf20  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0040cf24  895004               mov dword ptr [eax + 4], edx
// 0040cf27  8b542420             mov edx, dword ptr [esp + 0x20]
// 0040cf2b  895008               mov dword ptr [eax + 8], edx
// 0040cf2e  8b542424             mov edx, dword ptr [esp + 0x24]
// 0040cf32  89500c               mov dword ptr [eax + 0xc], edx
// 0040cf35  e850c03000           call 0x718f8a
// 0040cf3a  c21400               ret 0x14
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp (function ?get_accChild@CFormView@@UAEJUtagVARIANT@@PAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewform.cpp
