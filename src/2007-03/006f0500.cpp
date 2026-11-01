// from server: 100% by auto
// roc 2007-03 006f0500  unit: seg_006f0000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f0500
//
// 006f0500  8b4120               mov eax, dword ptr [ecx + 0x20]
// 006f0503  56                   push esi
// 006f0504  8b742408             mov esi, dword ptr [esp + 8]
// 006f0508  56                   push esi
// 006f0509  50                   push eax
// 006f050a  ff153ced7700         call dword ptr [0x77ed3c]
// 006f0510  6afc                 push -4
// 006f0512  6a00                 push 0
// 006f0514  56                   push esi
// 006f0515  ff159ced7700         call dword ptr [0x77ed9c]
// 006f051b  8b0e                 mov ecx, dword ptr [esi]
// 006f051d  83c10e               add ecx, 0xe
// 006f0520  894e08               mov dword ptr [esi + 8], ecx
// 006f0523  5e                   pop esi
// 006f0524  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?GetLumBarRect@CXTPColorLum@@QAEXAAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
