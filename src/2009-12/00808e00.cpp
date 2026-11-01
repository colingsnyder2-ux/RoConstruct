// from server: 100% by auto
// roc 2009-12 00808e00  unit: CXTPCommandBar  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00808e00
//
// 00808e00  56                   push esi
// 00808e01  57                   push edi
// 00808e02  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00808e06  8bf1                 mov esi, ecx
// 00808e08  3b7e08               cmp edi, dword ptr [esi + 8]
// 00808e0b  721a                 jb 0x808e27
// 00808e0d  8b06                 mov eax, dword ptr [esi]
// 00808e0f  50                   push eax
// 00808e10  ff1560b09800         call dword ptr [0x98b060]
// 00808e16  034608               add eax, dword ptr [esi + 8]
// 00808e19  3bf8                 cmp edi, eax
// 00808e1b  730a                 jae 0x808e27
// 00808e1d  5f                   pop edi
// 00808e1e  b801000000           mov eax, 1
// 00808e23  5e                   pop esi
// 00808e24  c20400               ret 4
// 00808e27  5f                   pop edi
// 00808e28  33c0                 xor eax, eax
// 00808e2a  5e                   pop esi
// 00808e2b  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?Lookup@CXTPImageManagerImageList@@QAEHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
