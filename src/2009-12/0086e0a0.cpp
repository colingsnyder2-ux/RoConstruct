// from server: 100% by auto
// roc 2009-12 0086e0a0  unit: CXTPResourceManager  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086e0a0
//
// 0086e0a0  56                   push esi
// 0086e0a1  8bf1                 mov esi, ecx
// 0086e0a3  8b4608               mov eax, dword ptr [esi + 8]
// 0086e0a6  85c0                 test eax, eax
// 0086e0a8  740e                 je 0x86e0b8
// 0086e0aa  50                   push eax
// 0086e0ab  ff15f8b19800         call dword ptr [0x98b1f8]
// 0086e0b1  c7460800000000       mov dword ptr [esi + 8], 0
// 0086e0b8  5e                   pop esi
// 0086e0b9  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?Close@CXTPResourceManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
