// from server: 100% by auto
// roc 2010-06 00899f60  unit: CXTCaptionButton  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00899f60
//
// 00899f60  8b442408             mov eax, dword ptr [esp + 8]
// 00899f64  56                   push esi
// 00899f65  57                   push edi
// 00899f66  8bf1                 mov esi, ecx
// 00899f68  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00899f6c  8b5620               mov edx, dword ptr [esi + 0x20]
// 00899f6f  50                   push eax
// 00899f70  51                   push ecx
// 00899f71  6828010000           push 0x128
// 00899f76  52                   push edx
// 00899f77  ff157cbb9e00         call dword ptr [0x9ebb7c]
// 00899f7d  6a00                 push 0
// 00899f7f  8bf8                 mov edi, eax
// 00899f81  8b4620               mov eax, dword ptr [esi + 0x20]
// 00899f84  6a00                 push 0
// 00899f86  50                   push eax
// 00899f87  ff1578ba9e00         call dword ptr [0x9eba78]
// 00899f8d  8bc7                 mov eax, edi
// 00899f8f  5f                   pop edi
// 00899f90  5e                   pop esi
// 00899f91  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTButton.cpp (function ?OnUpdateUIState@CXTButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButton.cpp
