// from server: 100% by auto
// roc 2007-03 006dfef0  unit: seg_006d0000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006dfef0
//
// 006dfef0  56                   push esi
// 006dfef1  8bf1                 mov esi, ecx
// 006dfef3  8b4604               mov eax, dword ptr [esi + 4]
// 006dfef6  57                   push edi
// 006dfef7  33ff                 xor edi, edi
// 006dfef9  3bc7                 cmp eax, edi
// 006dfefb  7409                 je 0x6dff06
// 006dfefd  8d4900               lea ecx, [ecx]
// 006dff00  8b00                 mov eax, dword ptr [eax]
// 006dff02  3bc7                 cmp eax, edi
// 006dff04  75fa                 jne 0x6dff00
// 006dff06  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 006dff09  897e0c               mov dword ptr [esi + 0xc], edi
// 006dff0c  897e10               mov dword ptr [esi + 0x10], edi
// 006dff0f  897e08               mov dword ptr [esi + 8], edi
// 006dff12  897e04               mov dword ptr [esi + 4], edi
// 006dff15  e8f0ebf3ff           call 0x61eb0a
// 006dff1a  897e14               mov dword ptr [esi + 0x14], edi
// 006dff1d  5f                   pop edi
// 006dff1e  5e                   pop esi
// 006dff1f  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\occmgr.cpp (function ?RemoveAll@?$CList@PAVIControlSiteFactory@@PAV1@@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/occmgr.cpp
