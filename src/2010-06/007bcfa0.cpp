// from server: 100% by auto
// roc 2010-06 007bcfa0  unit: CXTPCommandBar  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bcfa0
//
// 007bcfa0  56                   push esi
// 007bcfa1  57                   push edi
// 007bcfa2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007bcfa6  8bf1                 mov esi, ecx
// 007bcfa8  3b7e08               cmp edi, dword ptr [esi + 8]
// 007bcfab  721a                 jb 0x7bcfc7
// 007bcfad  8b06                 mov eax, dword ptr [esi]
// 007bcfaf  50                   push eax
// 007bcfb0  ff1574a09e00         call dword ptr [0x9ea074]
// 007bcfb6  034608               add eax, dword ptr [esi + 8]
// 007bcfb9  3bf8                 cmp edi, eax
// 007bcfbb  730a                 jae 0x7bcfc7
// 007bcfbd  5f                   pop edi
// 007bcfbe  b801000000           mov eax, 1
// 007bcfc3  5e                   pop esi
// 007bcfc4  c20400               ret 4
// 007bcfc7  5f                   pop edi
// 007bcfc8  33c0                 xor eax, eax
// 007bcfca  5e                   pop esi
// 007bcfcb  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?Lookup@CXTPImageManagerImageList@@QAEHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
