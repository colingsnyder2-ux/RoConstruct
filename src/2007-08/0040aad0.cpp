// from server: 100% by auto
// roc 2007-08 0040aad0  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040aad0
//
// 0040aad0  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040aad4  8b542404             mov edx, dword ptr [esp + 4]
// 0040aad8  50                   push eax
// 0040aad9  83ec10               sub esp, 0x10
// 0040aadc  8bc4                 mov eax, esp
// 0040aade  8910                 mov dword ptr [eax], edx
// 0040aae0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0040aae4  895004               mov dword ptr [eax + 4], edx
// 0040aae7  8b542420             mov edx, dword ptr [esp + 0x20]
// 0040aaeb  895008               mov dword ptr [eax + 8], edx
// 0040aaee  8b542424             mov edx, dword ptr [esp + 0x24]
// 0040aaf2  89500c               mov dword ptr [eax + 0xc], edx
// 0040aaf5  e8d8562200           call 0x6301d2
// 0040aafa  c21400               ret 0x14
// library mfc-8.0/atlmfc\src\mfc\viewform.cpp (function ?get_accChild@CFormView@@UAEJUtagVARIANT@@PAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewform.cpp
