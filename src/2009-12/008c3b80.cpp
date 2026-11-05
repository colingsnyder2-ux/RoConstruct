// from server: 100% by auto
// roc 2009-12 008c3b80  unit: CXTPImageEditorDlg  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c3b80
//
// 008c3b80  56                   push esi
// 008c3b81  8bf1                 mov esi, ecx
// 008c3b83  8b4608               mov eax, dword ptr [esi + 8]
// 008c3b86  6a00                 push 0
// 008c3b88  50                   push eax
// 008c3b89  e852efffff           call 0x8c2ae0
// 008c3b8e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008c3b92  894808               mov dword ptr [eax + 8], ecx
// 008c3b95  8b4e08               mov ecx, dword ptr [esi + 8]
// 008c3b98  85c9                 test ecx, ecx
// 008c3b9a  7409                 je 0x8c3ba5
// 008c3b9c  8901                 mov dword ptr [ecx], eax
// 008c3b9e  894608               mov dword ptr [esi + 8], eax
// 008c3ba1  5e                   pop esi
// 008c3ba2  c20400               ret 4
// 008c3ba5  894604               mov dword ptr [esi + 4], eax
// 008c3ba8  894608               mov dword ptr [esi + 8], eax
// 008c3bab  5e                   pop esi
// 008c3bac  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ?AddTail@CObList@@QAEPAU__POSITION@@PAVCObject@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
