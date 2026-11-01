// from server: 100% by auto
// roc 2011-06 00458ad0  unit: CRobloxControlColorSelector  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00458ad0
//
// 00458ad0  57                   push edi
// 00458ad1  8b7c2408             mov edi, dword ptr [esp + 8]
// 00458ad5  85ff                 test edi, edi
// 00458ad7  7509                 jne 0x458ae2
// 00458ad9  b857000780           mov eax, 0x80070057
// 00458ade  5f                   pop edi
// 00458adf  c20400               ret 4
// 00458ae2  56                   push esi
// 00458ae3  8b7708               mov esi, dword ptr [edi + 8]
// 00458ae6  33c0                 xor eax, eax
// 00458ae8  3b770c               cmp esi, dword ptr [edi + 0xc]
// 00458aeb  7324                 jae 0x458b11
// 00458aed  53                   push ebx
// 00458aee  8b1d9430a400         mov ebx, dword ptr [0xa43094]
// 00458af4  85c0                 test eax, eax
// 00458af6  7518                 jne 0x458b10
// 00458af8  8b0e                 mov ecx, dword ptr [esi]
// 00458afa  85c9                 test ecx, ecx
// 00458afc  740a                 je 0x458b08
// 00458afe  8b4114               mov eax, dword ptr [ecx + 0x14]
// 00458b01  85c0                 test eax, eax
// 00458b03  7403                 je 0x458b08
// 00458b05  50                   push eax
// 00458b06  ffd3                 call ebx
// 00458b08  83c604               add esi, 4
// 00458b0b  3b770c               cmp esi, dword ptr [edi + 0xc]
// 00458b0e  72e4                 jb 0x458af4
// 00458b10  5b                   pop ebx
// 00458b11  5e                   pop esi
// 00458b12  5f                   pop edi
// 00458b13  c20400               ret 4
// library atl-8.0/atl.cpp (function _AtlComModuleRevokeClassObjects@4)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
