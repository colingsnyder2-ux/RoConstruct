// from server: 100% by auto
// roc 2008-06 004bd540  unit: ProfiledRakPeer  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bd540
//
// 004bd540  53                   push ebx
// 004bd541  8b5c2408             mov ebx, dword ptr [esp + 8]
// 004bd545  56                   push esi
// 004bd546  57                   push edi
// 004bd547  8bf9                 mov edi, ecx
// 004bd549  8b97ac020000         mov edx, dword ptr [edi + 0x2ac]
// 004bd54f  8d8fa8020000         lea ecx, [edi + 0x2a8]
// 004bd555  33c0                 xor eax, eax
// 004bd557  85d2                 test edx, edx
// 004bd559  7618                 jbe 0x4bd573
// 004bd55b  8b31                 mov esi, dword ptr [ecx]
// 004bd55d  8d4900               lea ecx, [ecx]
// 004bd560  391e                 cmp dword ptr [esi], ebx
// 004bd562  740a                 je 0x4bd56e
// 004bd564  40                   inc eax
// 004bd565  83c604               add esi, 4
// 004bd568  3bc2                 cmp eax, edx
// 004bd56a  72f4                 jb 0x4bd560
// 004bd56c  eb05                 jmp 0x4bd573
// 004bd56e  83f8ff               cmp eax, -1
// 004bd571  7510                 jne 0x4bd583
// 004bd573  53                   push ebx
// 004bd574  e8a7ebffff           call 0x4bc120
// 004bd579  8b03                 mov eax, dword ptr [ebx]
// 004bd57b  8b5004               mov edx, dword ptr [eax + 4]
// 004bd57e  57                   push edi
// 004bd57f  8bcb                 mov ecx, ebx
// 004bd581  ffd2                 call edx
// 004bd583  5f                   pop edi
// 004bd584  5e                   pop esi
// 004bd585  5b                   pop ebx
// 004bd586  c20400               ret 4
// library openrbx-raknet/RakPeer.cpp (function ?AttachPlugin@RakPeer@@UAEXPAVPluginInterface@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
