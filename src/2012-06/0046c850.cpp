// from server: 100% by auto
// roc 2012-06 0046c850  unit: RBX::TeleportCallback  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046c850
//
// 0046c850  57                   push edi
// 0046c851  8b7c2408             mov edi, dword ptr [esp + 8]
// 0046c855  85ff                 test edi, edi
// 0046c857  7509                 jne 0x46c862
// 0046c859  b857000780           mov eax, 0x80070057
// 0046c85e  5f                   pop edi
// 0046c85f  c20400               ret 4
// 0046c862  56                   push esi
// 0046c863  8b7708               mov esi, dword ptr [edi + 8]
// 0046c866  33c0                 xor eax, eax
// 0046c868  3b770c               cmp esi, dword ptr [edi + 0xc]
// 0046c86b  7324                 jae 0x46c891
// 0046c86d  53                   push ebx
// 0046c86e  8b1d4851b200         mov ebx, dword ptr [0xb25148]
// 0046c874  85c0                 test eax, eax
// 0046c876  7518                 jne 0x46c890
// 0046c878  8b0e                 mov ecx, dword ptr [esi]
// 0046c87a  85c9                 test ecx, ecx
// 0046c87c  740a                 je 0x46c888
// 0046c87e  8b4114               mov eax, dword ptr [ecx + 0x14]
// 0046c881  85c0                 test eax, eax
// 0046c883  7403                 je 0x46c888
// 0046c885  50                   push eax
// 0046c886  ffd3                 call ebx
// 0046c888  83c604               add esi, 4
// 0046c88b  3b770c               cmp esi, dword ptr [edi + 0xc]
// 0046c88e  72e4                 jb 0x46c874
// 0046c890  5b                   pop ebx
// 0046c891  5e                   pop esi
// 0046c892  5f                   pop edi
// 0046c893  c20400               ret 4
// library atl-8.0/atl.cpp (function _AtlComModuleRevokeClassObjects@4)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
