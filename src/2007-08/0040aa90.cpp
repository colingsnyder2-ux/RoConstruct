// from server: 100% by auto
// roc 2007-08 0040aa90  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040aa90
//
// 0040aa90  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040aa94  8b542404             mov edx, dword ptr [esp + 4]
// 0040aa98  50                   push eax
// 0040aa99  83ec10               sub esp, 0x10
// 0040aa9c  8bc4                 mov eax, esp
// 0040aa9e  8910                 mov dword ptr [eax], edx
// 0040aaa0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0040aaa4  895004               mov dword ptr [eax + 4], edx
// 0040aaa7  8b542420             mov edx, dword ptr [esp + 0x20]
// 0040aaab  895008               mov dword ptr [eax + 8], edx
// 0040aaae  8b542424             mov edx, dword ptr [esp + 0x24]
// 0040aab2  89500c               mov dword ptr [eax + 0xc], edx
// 0040aab5  e80c572200           call 0x6301c6
// 0040aaba  c21400               ret 0x14
// library mfc-8.0/atlmfc\src\mfc\viewform.cpp (function ?get_accChild@CFormView@@UAEJUtagVARIANT@@PAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewform.cpp
