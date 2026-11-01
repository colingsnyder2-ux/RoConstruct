// from server: 100% by auto
// roc 2010-06 0044d170  unit: CRobloxApp  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0044d170
//
// 0044d170  57                   push edi
// 0044d171  8b7c2408             mov edi, dword ptr [esp + 8]
// 0044d175  85ff                 test edi, edi
// 0044d177  7509                 jne 0x44d182
// 0044d179  b857000780           mov eax, 0x80070057
// 0044d17e  5f                   pop edi
// 0044d17f  c20400               ret 4
// 0044d182  56                   push esi
// 0044d183  8b7708               mov esi, dword ptr [edi + 8]
// 0044d186  33c0                 xor eax, eax
// 0044d188  3b770c               cmp esi, dword ptr [edi + 0xc]
// 0044d18b  7324                 jae 0x44d1b1
// 0044d18d  53                   push ebx
// 0044d18e  8b1de4d09e00         mov ebx, dword ptr [0x9ed0e4]
// 0044d194  85c0                 test eax, eax
// 0044d196  7518                 jne 0x44d1b0
// 0044d198  8b0e                 mov ecx, dword ptr [esi]
// 0044d19a  85c9                 test ecx, ecx
// 0044d19c  740a                 je 0x44d1a8
// 0044d19e  8b4114               mov eax, dword ptr [ecx + 0x14]
// 0044d1a1  85c0                 test eax, eax
// 0044d1a3  7403                 je 0x44d1a8
// 0044d1a5  50                   push eax
// 0044d1a6  ffd3                 call ebx
// 0044d1a8  83c604               add esi, 4
// 0044d1ab  3b770c               cmp esi, dword ptr [edi + 0xc]
// 0044d1ae  72e4                 jb 0x44d194
// 0044d1b0  5b                   pop ebx
// 0044d1b1  5e                   pop esi
// 0044d1b2  5f                   pop edi
// 0044d1b3  c20400               ret 4
// library atl-8.0/atl.cpp (function _AtlComModuleRevokeClassObjects@4)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
