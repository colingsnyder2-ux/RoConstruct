// from server: 100% by auto
// roc 2009-06 007651c0  unit: CXTPCustomizeSheet  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007651c0
//
// 007651c0  56                   push esi
// 007651c1  6a01                 push 1
// 007651c3  8bf1                 mov esi, ecx
// 007651c5  e8f63afbff           call 0x718cc0
// 007651ca  8bce                 mov ecx, esi
// 007651cc  e8cffeffff           call 0x7650a0
// 007651d1  8b8e98000000         mov ecx, dword ptr [esi + 0x98]
// 007651d7  8b4074               mov eax, dword ptr [eax + 0x74]
// 007651da  89482c               mov dword ptr [eax + 0x2c], ecx
// 007651dd  5e                   pop esi
// 007651de  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeOptionsPage.cpp (function ?OnCheckShortcuts@CXTPCustomizeOptionsPage@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeOptionsPage.cpp
