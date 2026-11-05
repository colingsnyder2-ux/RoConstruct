// from server: 100% by auto
// roc 2008-06 0040e370  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040e370
//
// 0040e370  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040e374  8b542404             mov edx, dword ptr [esp + 4]
// 0040e378  50                   push eax
// 0040e379  83ec10               sub esp, 0x10
// 0040e37c  8bc4                 mov eax, esp
// 0040e37e  8910                 mov dword ptr [eax], edx
// 0040e380  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0040e384  895004               mov dword ptr [eax + 4], edx
// 0040e387  8b542420             mov edx, dword ptr [esp + 0x20]
// 0040e38b  895008               mov dword ptr [eax + 8], edx
// 0040e38e  8b542424             mov edx, dword ptr [esp + 0x24]
// 0040e392  89500c               mov dword ptr [eax + 0xc], edx
// 0040e395  e85c282900           call 0x6a0bf6
// 0040e39a  c21400               ret 0x14
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp (function ?get_accChild@CFormView@@UAEJUtagVARIANT@@PAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewform.cpp
