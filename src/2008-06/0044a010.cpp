// from server: 100% by auto
// roc 2008-06 0044a010  unit: CIDEDocManager  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044a010
//
// 0044a010  57                   push edi
// 0044a011  8b7c2408             mov edi, dword ptr [esp + 8]
// 0044a015  85ff                 test edi, edi
// 0044a017  7509                 jne 0x44a022
// 0044a019  b857000780           mov eax, 0x80070057
// 0044a01e  5f                   pop edi
// 0044a01f  c20400               ret 4
// 0044a022  56                   push esi
// 0044a023  8b7708               mov esi, dword ptr [edi + 8]
// 0044a026  33c0                 xor eax, eax
// 0044a028  3b770c               cmp esi, dword ptr [edi + 0xc]
// 0044a02b  7324                 jae 0x44a051
// 0044a02d  53                   push ebx
// 0044a02e  8b1d20418000         mov ebx, dword ptr [0x804120]
// 0044a034  85c0                 test eax, eax
// 0044a036  7518                 jne 0x44a050
// 0044a038  8b0e                 mov ecx, dword ptr [esi]
// 0044a03a  85c9                 test ecx, ecx
// 0044a03c  740a                 je 0x44a048
// 0044a03e  8b4114               mov eax, dword ptr [ecx + 0x14]
// 0044a041  85c0                 test eax, eax
// 0044a043  7403                 je 0x44a048
// 0044a045  50                   push eax
// 0044a046  ffd3                 call ebx
// 0044a048  83c604               add esi, 4
// 0044a04b  3b770c               cmp esi, dword ptr [edi + 0xc]
// 0044a04e  72e4                 jb 0x44a034
// 0044a050  5b                   pop ebx
// 0044a051  5e                   pop esi
// 0044a052  5f                   pop edi
// 0044a053  c20400               ret 4
// library atl-8.0/atl.cpp (function _AtlComModuleRevokeClassObjects@4)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
