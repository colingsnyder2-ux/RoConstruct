// from server: 100% by auto
// roc 2011-06 008f0570  unit: PAVCXTShadowWnd::?$CList  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f0570
//
// 008f0570  56                   push esi
// 008f0571  8bf1                 mov esi, ecx
// 008f0573  8b4608               mov eax, dword ptr [esi + 8]
// 008f0576  6a00                 push 0
// 008f0578  50                   push eax
// 008f0579  e812feffff           call 0x8f0390
// 008f057e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008f0582  894808               mov dword ptr [eax + 8], ecx
// 008f0585  8b4e08               mov ecx, dword ptr [esi + 8]
// 008f0588  85c9                 test ecx, ecx
// 008f058a  7409                 je 0x8f0595
// 008f058c  8901                 mov dword ptr [ecx], eax
// 008f058e  894608               mov dword ptr [esi + 8], eax
// 008f0591  5e                   pop esi
// 008f0592  c20400               ret 4
// 008f0595  894604               mov dword ptr [esi + 4], eax
// 008f0598  894608               mov dword ptr [esi + 8], eax
// 008f059b  5e                   pop esi
// 008f059c  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?AddTail@?$CList@II@@QAEPAU__POSITION@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
