// from server: 100% by auto
// roc 2009-06 00731c80  unit: CXTPCommandBar  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00731c80
//
// 00731c80  56                   push esi
// 00731c81  57                   push edi
// 00731c82  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00731c86  8bf1                 mov esi, ecx
// 00731c88  3b7e08               cmp edi, dword ptr [esi + 8]
// 00731c8b  721a                 jb 0x731ca7
// 00731c8d  8b06                 mov eax, dword ptr [esi]
// 00731c8f  50                   push eax
// 00731c90  ff155ce08900         call dword ptr [0x89e05c]
// 00731c96  034608               add eax, dword ptr [esi + 8]
// 00731c99  3bf8                 cmp edi, eax
// 00731c9b  730a                 jae 0x731ca7
// 00731c9d  5f                   pop edi
// 00731c9e  b801000000           mov eax, 1
// 00731ca3  5e                   pop esi
// 00731ca4  c20400               ret 4
// 00731ca7  5f                   pop edi
// 00731ca8  33c0                 xor eax, eax
// 00731caa  5e                   pop esi
// 00731cab  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?Lookup@CXTPImageManagerImageList@@QAEHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
