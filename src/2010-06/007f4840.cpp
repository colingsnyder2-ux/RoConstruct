// from server: 100% by auto
// roc 2010-06 007f4840  unit: CXTPCustomizeCommandsPage  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f4840
//
// 007f4840  56                   push esi
// 007f4841  8bf1                 mov esi, ecx
// 007f4843  8b8638010000         mov eax, dword ptr [esi + 0x138]
// 007f4849  8b5620               mov edx, dword ptr [esi + 0x20]
// 007f484c  8b88b8000000         mov ecx, dword ptr [eax + 0xb8]
// 007f4852  52                   push edx
// 007f4853  e8e853fdff           call 0x7c9c40
// 007f4858  8bc8                 mov ecx, eax
// 007f485a  e8f1e80200           call 0x823150
// 007f485f  8bce                 mov ecx, esi
// 007f4861  5e                   pop esi
// 007f4862  e9f53bfbff           jmp 0x7a845c
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeCommandsPage.cpp (function ?OnDestroy@CXTPCustomizeCommandsPage@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeCommandsPage.cpp
