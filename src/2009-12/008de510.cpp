// from server: 100% by auto
// roc 2009-12 008de510  unit: CXTColorLum  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008de510
//
// 008de510  8b442404             mov eax, dword ptr [esp + 4]
// 008de514  56                   push esi
// 008de515  50                   push eax
// 008de516  8bf1                 mov esi, ecx
// 008de518  e87161f1ff           call 0x7f468e
// 008de51d  6a00                 push 0
// 008de51f  c70524bfb90002000000 mov dword ptr [0xb9bf24], 2
// 008de529  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008de52c  6a00                 push 0
// 008de52e  51                   push ecx
// 008de52f  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008de535  5e                   pop esi
// 008de536  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?OnSetFocus@CXTPColorLum@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
