// from server: 100% by auto
// roc 2009-12 00833020  unit: CXTTreeBase  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00833020
//
// 00833020  56                   push esi
// 00833021  8bf1                 mov esi, ecx
// 00833023  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00833026  e847340f00           call 0x926472
// 0083302b  a900020000           test eax, 0x200
// 00833030  741e                 je 0x833050
// 00833032  837e1400             cmp dword ptr [esi + 0x14], 0
// 00833036  7418                 je 0x833050
// 00833038  8b4634               mov eax, dword ptr [esi + 0x34]
// 0083303b  6a00                 push 0
// 0083303d  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00833044  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00833047  6a00                 push 0
// 00833049  51                   push ecx
// 0083304a  ff15e8cb9800         call dword ptr [0x98cbe8]
// 00833050  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00833053  e8d80dfcff           call 0x7f3e30
// 00833058  5e                   pop esi
// 00833059  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnNcMouseMove@CXTPTreeBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
