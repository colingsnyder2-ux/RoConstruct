// from server: 100% by auto
// roc 2009-06 007e58d0  unit: CXTPShadowsManager::PAVCShadowWnd::?$CList  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e58d0
//
// 007e58d0  56                   push esi
// 007e58d1  8bf1                 mov esi, ecx
// 007e58d3  8b4608               mov eax, dword ptr [esi + 8]
// 007e58d6  6a00                 push 0
// 007e58d8  50                   push eax
// 007e58d9  e812ffffff           call 0x7e57f0
// 007e58de  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007e58e2  894808               mov dword ptr [eax + 8], ecx
// 007e58e5  8b4e08               mov ecx, dword ptr [esi + 8]
// 007e58e8  85c9                 test ecx, ecx
// 007e58ea  7409                 je 0x7e58f5
// 007e58ec  8901                 mov dword ptr [ecx], eax
// 007e58ee  894608               mov dword ptr [esi + 8], eax
// 007e58f1  5e                   pop esi
// 007e58f2  c20400               ret 4
// 007e58f5  894604               mov dword ptr [esi + 4], eax
// 007e58f8  894608               mov dword ptr [esi + 8], eax
// 007e58fb  5e                   pop esi
// 007e58fc  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?AddTail@?$CList@II@@QAEPAU__POSITION@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
