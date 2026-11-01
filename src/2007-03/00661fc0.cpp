// from server: 100% by auto
// roc 2007-03 00661fc0  unit: seg_00660000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00661fc0
//
// 00661fc0  56                   push esi
// 00661fc1  8bf1                 mov esi, ecx
// 00661fc3  8b8638010000         mov eax, dword ptr [esi + 0x138]
// 00661fc9  8b5620               mov edx, dword ptr [esi + 0x20]
// 00661fcc  8b88b8000000         mov ecx, dword ptr [eax + 0xb8]
// 00661fd2  52                   push edx
// 00661fd3  e8d8b0fcff           call 0x62d0b0
// 00661fd8  8bc8                 mov ecx, eax
// 00661fda  e8f1b30200           call 0x68d3d0
// 00661fdf  8bce                 mov ecx, esi
// 00661fe1  5e                   pop esi
// 00661fe2  e9cfcdfbff           jmp 0x61edb6
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeCommandsPage.cpp (function ?OnDestroy@CXTPCustomizeCommandsPage@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeCommandsPage.cpp
