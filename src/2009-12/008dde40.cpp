// from server: 100% by auto
// roc 2009-12 008dde40  unit: CXTColorLum  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008dde40
//
// 008dde40  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008dde43  56                   push esi
// 008dde44  8b742408             mov esi, dword ptr [esp + 8]
// 008dde48  56                   push esi
// 008dde49  50                   push eax
// 008dde4a  ff1550cc9800         call dword ptr [0x98cc50]
// 008dde50  6afc                 push -4
// 008dde52  6a00                 push 0
// 008dde54  56                   push esi
// 008dde55  ff1558ca9800         call dword ptr [0x98ca58]
// 008dde5b  8b0e                 mov ecx, dword ptr [esi]
// 008dde5d  83c10e               add ecx, 0xe
// 008dde60  894e08               mov dword ptr [esi + 8], ecx
// 008dde63  5e                   pop esi
// 008dde64  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?GetLumBarRect@CXTPColorLum@@QAEXAAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
