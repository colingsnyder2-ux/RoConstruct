// from server: 100% by auto
// roc 2009-12 0083ff90  unit: CXTPCustomizeSheet  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083ff90
//
// 0083ff90  56                   push esi
// 0083ff91  6a01                 push 1
// 0083ff93  8bf1                 mov esi, ecx
// 0083ff95  e84e3bfbff           call 0x7f3ae8
// 0083ff9a  8bce                 mov ecx, esi
// 0083ff9c  e8cffeffff           call 0x83fe70
// 0083ffa1  8b8e98000000         mov ecx, dword ptr [esi + 0x98]
// 0083ffa7  8b4074               mov eax, dword ptr [eax + 0x74]
// 0083ffaa  89482c               mov dword ptr [eax + 0x2c], ecx
// 0083ffad  5e                   pop esi
// 0083ffae  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeOptionsPage.cpp (function ?OnCheckShortcuts@CXTPCustomizeOptionsPage@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeOptionsPage.cpp
