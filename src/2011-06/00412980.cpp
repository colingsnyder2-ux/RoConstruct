// from server: 100% by auto
// roc 2011-06 00412980  unit: CDeclarationView  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00412980
//
// 00412980  8b442414             mov eax, dword ptr [esp + 0x14]
// 00412984  8b542404             mov edx, dword ptr [esp + 4]
// 00412988  50                   push eax
// 00412989  83ec10               sub esp, 0x10
// 0041298c  8bc4                 mov eax, esp
// 0041298e  8910                 mov dword ptr [eax], edx
// 00412990  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00412994  895004               mov dword ptr [eax + 4], edx
// 00412997  8b542420             mov edx, dword ptr [esp + 0x20]
// 0041299b  895008               mov dword ptr [eax + 8], edx
// 0041299e  8b542424             mov edx, dword ptr [esp + 0x24]
// 004129a2  89500c               mov dword ptr [eax + 0xc], edx
// 004129a5  e8127c3f00           call 0x80a5bc
// 004129aa  c21400               ret 0x14
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp (function ?get_accChild@CFormView@@UAEJUtagVARIANT@@PAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewform.cpp
