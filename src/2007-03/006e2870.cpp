// from server: 100% by auto
// roc 2007-03 006e2870  unit: seg_006e0000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e2870
//
// 006e2870  56                   push esi
// 006e2871  8bf1                 mov esi, ecx
// 006e2873  8b4608               mov eax, dword ptr [esi + 8]
// 006e2876  6a00                 push 0
// 006e2878  50                   push eax
// 006e2879  e842efffff           call 0x6e17c0
// 006e287e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006e2882  894808               mov dword ptr [eax + 8], ecx
// 006e2885  8b4e08               mov ecx, dword ptr [esi + 8]
// 006e2888  85c9                 test ecx, ecx
// 006e288a  7409                 je 0x6e2895
// 006e288c  8901                 mov dword ptr [ecx], eax
// 006e288e  894608               mov dword ptr [esi + 8], eax
// 006e2891  5e                   pop esi
// 006e2892  c20400               ret 4
// 006e2895  894604               mov dword ptr [esi + 4], eax
// 006e2898  894608               mov dword ptr [esi + 8], eax
// 006e289b  5e                   pop esi
// 006e289c  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ?AddTail@CObList@@QAEPAU__POSITION@@PAVCObject@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
