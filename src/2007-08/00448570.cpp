// from server: 100% by tester
// roc 2007-03 00447bf0  unit: seg_00440000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00447bf0
//
// 00447bf0  57                   push edi
// 00447bf1  8b7c2408             mov edi, dword ptr [esp + 8]
// 00447bf5  85ff                 test edi, edi
// 00447bf7  7509                 jne 0x447c02
// 00447bf9  b857000780           mov eax, 0x80070057
// 00447bfe  5f                   pop edi
// 00447bff  c20400               ret 4
// 00447c02  56                   push esi
// 00447c03  8b7708               mov esi, dword ptr [edi + 8]
// 00447c06  33c0                 xor eax, eax
// 00447c08  3b770c               cmp esi, dword ptr [edi + 0xc]
// 00447c0b  7324                 jae 0x447c31
// 00447c0d  53                   push ebx
// 00447c0e  8b1d0cf17700         mov ebx, dword ptr [0x77f10c]
// 00447c14  85c0                 test eax, eax
// 00447c16  7518                 jne 0x447c30
// 00447c18  8b0e                 mov ecx, dword ptr [esi]
// 00447c1a  85c9                 test ecx, ecx
// 00447c1c  740a                 je 0x447c28
// 00447c1e  8b4114               mov eax, dword ptr [ecx + 0x14]
// 00447c21  85c0                 test eax, eax
// 00447c23  7403                 je 0x447c28
// 00447c25  50                   push eax
// 00447c26  ffd3                 call ebx
// 00447c28  83c604               add esi, 4
// 00447c2b  3b770c               cmp esi, dword ptr [edi + 0xc]
// 00447c2e  72e4                 jb 0x447c14
// 00447c30  5b                   pop ebx
// 00447c31  5e                   pop esi
// 00447c32  5f                   pop edi
// 00447c33  c20400               ret 4
// library atl-8.0/atl.cpp (function _AtlComModuleRevokeClassObjects@4)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
