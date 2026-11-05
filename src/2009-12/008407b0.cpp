// from server: 100% by auto
// roc 2009-12 008407b0  unit: CXTPCustomizeCommandsPage  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008407b0
//
// 008407b0  56                   push esi
// 008407b1  8bf1                 mov esi, ecx
// 008407b3  8b8638010000         mov eax, dword ptr [esi + 0x138]
// 008407b9  8b5620               mov edx, dword ptr [esi + 0x20]
// 008407bc  8b88b8000000         mov ecx, dword ptr [eax + 0xb8]
// 008407c2  52                   push edx
// 008407c3  e8a853fdff           call 0x815b70
// 008407c8  8bc8                 mov ecx, eax
// 008407ca  e871e90200           call 0x86f140
// 008407cf  8bce                 mov ecx, esi
// 008407d1  5e                   pop esi
// 008407d2  e9453bfbff           jmp 0x7f431c
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeCommandsPage.cpp (function ?OnDestroy@CXTPCustomizeCommandsPage@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeCommandsPage.cpp
