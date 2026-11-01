// from server: 100% by auto
// roc 2007-03 00624bd0  unit: seg_00620000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00624bd0
//
// 00624bd0  56                   push esi
// 00624bd1  57                   push edi
// 00624bd2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00624bd6  8bf1                 mov esi, ecx
// 00624bd8  3b7e08               cmp edi, dword ptr [esi + 8]
// 00624bdb  721a                 jb 0x624bf7
// 00624bdd  8b06                 mov eax, dword ptr [esi]
// 00624bdf  50                   push eax
// 00624be0  ff1564d07700         call dword ptr [0x77d064]
// 00624be6  034608               add eax, dword ptr [esi + 8]
// 00624be9  3bf8                 cmp edi, eax
// 00624beb  730a                 jae 0x624bf7
// 00624bed  5f                   pop edi
// 00624bee  b801000000           mov eax, 1
// 00624bf3  5e                   pop esi
// 00624bf4  c20400               ret 4
// 00624bf7  5f                   pop edi
// 00624bf8  33c0                 xor eax, eax
// 00624bfa  5e                   pop esi
// 00624bfb  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?Lookup@CXTPImageManagerImageList@@QAEHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
