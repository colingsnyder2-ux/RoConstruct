// from server: 100% by auto
// roc 2011-06 004129c0  unit: CDeclarationView  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004129c0
//
// 004129c0  8b442414             mov eax, dword ptr [esp + 0x14]
// 004129c4  8b542404             mov edx, dword ptr [esp + 4]
// 004129c8  50                   push eax
// 004129c9  83ec10               sub esp, 0x10
// 004129cc  8bc4                 mov eax, esp
// 004129ce  8910                 mov dword ptr [eax], edx
// 004129d0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004129d4  895004               mov dword ptr [eax + 4], edx
// 004129d7  8b542420             mov edx, dword ptr [esp + 0x20]
// 004129db  895008               mov dword ptr [eax + 8], edx
// 004129de  8b542424             mov edx, dword ptr [esp + 0x24]
// 004129e2  89500c               mov dword ptr [eax + 0xc], edx
// 004129e5  e8de7b3f00           call 0x80a5c8
// 004129ea  c21400               ret 0x14
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp (function ?get_accChild@CFormView@@UAEJUtagVARIANT@@PAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewform.cpp
