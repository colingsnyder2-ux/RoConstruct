// from server: 100% by auto
// roc 2009-12 0040ceb0  unit: CDeclarationView  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0040ceb0
//
// 0040ceb0  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040ceb4  8b542404             mov edx, dword ptr [esp + 4]
// 0040ceb8  50                   push eax
// 0040ceb9  83ec10               sub esp, 0x10
// 0040cebc  8bc4                 mov eax, esp
// 0040cebe  8910                 mov dword ptr [eax], edx
// 0040cec0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0040cec4  895004               mov dword ptr [eax + 4], edx
// 0040cec7  8b542420             mov edx, dword ptr [esp + 0x20]
// 0040cecb  895008               mov dword ptr [eax + 8], edx
// 0040cece  8b542424             mov edx, dword ptr [esp + 0x24]
// 0040ced2  89500c               mov dword ptr [eax + 0xc], edx
// 0040ced5  e8f06e3e00           call 0x7f3dca
// 0040ceda  c21400               ret 0x14
// library mfc-8.0/atlmfc\src\mfc\viewform.cpp (function ?get_accChild@CFormView@@UAEJUtagVARIANT@@PAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewform.cpp
