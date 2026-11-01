// from server: 100% by auto
// roc 2009-12 00838950  unit: CXTPDockingPaneManager  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00838950
//
// 00838950  56                   push esi
// 00838951  8bf1                 mov esi, ecx
// 00838953  8b4604               mov eax, dword ptr [esi + 4]
// 00838956  57                   push edi
// 00838957  33ff                 xor edi, edi
// 00838959  3bc7                 cmp eax, edi
// 0083895b  7409                 je 0x838966
// 0083895d  8d4900               lea ecx, [ecx]
// 00838960  8b00                 mov eax, dword ptr [eax]
// 00838962  3bc7                 cmp eax, edi
// 00838964  75fa                 jne 0x838960
// 00838966  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00838969  897e0c               mov dword ptr [esi + 0xc], edi
// 0083896c  897e10               mov dword ptr [esi + 0x10], edi
// 0083896f  897e08               mov dword ptr [esi + 8], edi
// 00838972  897e04               mov dword ptr [esi + 4], edi
// 00838975  e84abafbff           call 0x7f43c4
// 0083897a  897e14               mov dword ptr [esi + 0x14], edi
// 0083897d  5f                   pop edi
// 0083897e  5e                   pop esi
// 0083897f  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\occmgr.cpp (function ?RemoveAll@?$CList@PAVIControlSiteFactory@@PAV1@@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/occmgr.cpp
