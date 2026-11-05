// from server: 100% by auto
// roc 2010-06 00892060  unit: CXTColorLum  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00892060
//
// 00892060  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00892063  56                   push esi
// 00892064  8b742408             mov esi, dword ptr [esp + 8]
// 00892068  56                   push esi
// 00892069  50                   push eax
// 0089206a  ff155cbc9e00         call dword ptr [0x9ebc5c]
// 00892070  6afc                 push -4
// 00892072  6a00                 push 0
// 00892074  56                   push esi
// 00892075  ff15dcbb9e00         call dword ptr [0x9ebbdc]
// 0089207b  8b0e                 mov ecx, dword ptr [esi]
// 0089207d  83c10e               add ecx, 0xe
// 00892080  894e08               mov dword ptr [esi + 8], ecx
// 00892083  5e                   pop esi
// 00892084  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?GetLumBarRect@CXTColorLum@@QAEXAAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
