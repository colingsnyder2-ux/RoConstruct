// from server: 100% by auto
// roc 2010-06 0040d3e0  unit: CDeclarationView  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040d3e0
//
// 0040d3e0  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040d3e4  8b542404             mov edx, dword ptr [esp + 4]
// 0040d3e8  50                   push eax
// 0040d3e9  83ec10               sub esp, 0x10
// 0040d3ec  8bc4                 mov eax, esp
// 0040d3ee  8910                 mov dword ptr [eax], edx
// 0040d3f0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0040d3f4  895004               mov dword ptr [eax + 4], edx
// 0040d3f7  8b542420             mov edx, dword ptr [esp + 0x20]
// 0040d3fb  895008               mov dword ptr [eax + 8], edx
// 0040d3fe  8b542424             mov edx, dword ptr [esp + 0x24]
// 0040d402  89500c               mov dword ptr [eax + 0xc], edx
// 0040d405  e800ab3900           call 0x7a7f0a
// 0040d40a  c21400               ret 0x14
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp (function ?get_accChild@CFormView@@UAEJUtagVARIANT@@PAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewform.cpp
