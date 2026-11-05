// from server: 100% by auto
// roc 2009-12 0040ce70  unit: CDeclarationView  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0040ce70
//
// 0040ce70  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040ce74  8b542404             mov edx, dword ptr [esp + 4]
// 0040ce78  50                   push eax
// 0040ce79  83ec10               sub esp, 0x10
// 0040ce7c  8bc4                 mov eax, esp
// 0040ce7e  8910                 mov dword ptr [eax], edx
// 0040ce80  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0040ce84  895004               mov dword ptr [eax + 4], edx
// 0040ce87  8b542420             mov edx, dword ptr [esp + 0x20]
// 0040ce8b  895008               mov dword ptr [eax + 8], edx
// 0040ce8e  8b542424             mov edx, dword ptr [esp + 0x24]
// 0040ce92  89500c               mov dword ptr [eax + 0xc], edx
// 0040ce95  e8246f3e00           call 0x7f3dbe
// 0040ce9a  c21400               ret 0x14
// library mfc-8.0/atlmfc\src\mfc\viewform.cpp (function ?get_accChild@CFormView@@UAEJUtagVARIANT@@PAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewform.cpp
