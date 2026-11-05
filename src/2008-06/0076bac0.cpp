// from server: 100% by auto
// roc 2008-06 0076bac0  unit: CXTPDockingPaneContext  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0076bac0
//
// 0076bac0  56                   push esi
// 0076bac1  8bf1                 mov esi, ecx
// 0076bac3  8b4608               mov eax, dword ptr [esi + 8]
// 0076bac6  6a00                 push 0
// 0076bac8  50                   push eax
// 0076bac9  e862ecffff           call 0x76a730
// 0076bace  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0076bad2  894808               mov dword ptr [eax + 8], ecx
// 0076bad5  8b4e08               mov ecx, dword ptr [esi + 8]
// 0076bad8  85c9                 test ecx, ecx
// 0076bada  7409                 je 0x76bae5
// 0076badc  8901                 mov dword ptr [ecx], eax
// 0076bade  894608               mov dword ptr [esi + 8], eax
// 0076bae1  5e                   pop esi
// 0076bae2  c20400               ret 4
// 0076bae5  894604               mov dword ptr [esi + 4], eax
// 0076bae8  894608               mov dword ptr [esi + 8], eax
// 0076baeb  5e                   pop esi
// 0076baec  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?AddTail@?$CList@II@@QAEPAU__POSITION@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
