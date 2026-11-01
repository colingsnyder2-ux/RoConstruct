// from server: 100% by auto
// roc 2009-06 00803350  unit: CXTColorLum  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00803350
//
// 00803350  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00803353  56                   push esi
// 00803354  8b742408             mov esi, dword ptr [esp + 8]
// 00803358  56                   push esi
// 00803359  50                   push eax
// 0080335a  ff1514ee8900         call dword ptr [0x89ee14]
// 00803360  6afc                 push -4
// 00803362  6a00                 push 0
// 00803364  56                   push esi
// 00803365  ff15bced8900         call dword ptr [0x89edbc]
// 0080336b  8b0e                 mov ecx, dword ptr [esi]
// 0080336d  83c10e               add ecx, 0xe
// 00803370  894e08               mov dword ptr [esi + 8], ecx
// 00803373  5e                   pop esi
// 00803374  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?GetLumBarRect@CXTPColorLum@@QAEXAAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
