// from server: 100% by auto
// roc 2009-12 0044b1d0  unit: CRobloxControlColorSelector  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0044b1d0
//
// 0044b1d0  57                   push edi
// 0044b1d1  8b7c2408             mov edi, dword ptr [esp + 8]
// 0044b1d5  85ff                 test edi, edi
// 0044b1d7  7509                 jne 0x44b1e2
// 0044b1d9  b857000780           mov eax, 0x80070057
// 0044b1de  5f                   pop edi
// 0044b1df  c20400               ret 4
// 0044b1e2  56                   push esi
// 0044b1e3  8b7708               mov esi, dword ptr [edi + 8]
// 0044b1e6  33c0                 xor eax, eax
// 0044b1e8  3b770c               cmp esi, dword ptr [edi + 0xc]
// 0044b1eb  7324                 jae 0x44b211
// 0044b1ed  53                   push ebx
// 0044b1ee  8b1dace09800         mov ebx, dword ptr [0x98e0ac]
// 0044b1f4  85c0                 test eax, eax
// 0044b1f6  7518                 jne 0x44b210
// 0044b1f8  8b0e                 mov ecx, dword ptr [esi]
// 0044b1fa  85c9                 test ecx, ecx
// 0044b1fc  740a                 je 0x44b208
// 0044b1fe  8b4114               mov eax, dword ptr [ecx + 0x14]
// 0044b201  85c0                 test eax, eax
// 0044b203  7403                 je 0x44b208
// 0044b205  50                   push eax
// 0044b206  ffd3                 call ebx
// 0044b208  83c604               add esi, 4
// 0044b20b  3b770c               cmp esi, dword ptr [edi + 0xc]
// 0044b20e  72e4                 jb 0x44b1f4
// 0044b210  5b                   pop ebx
// 0044b211  5e                   pop esi
// 0044b212  5f                   pop edi
// 0044b213  c20400               ret 4
// library atl-8.0/atl.cpp (function _AtlComModuleRevokeClassObjects@4)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
