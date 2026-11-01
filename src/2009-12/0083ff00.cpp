// from server: 100% by auto
// roc 2009-12 0083ff00  unit: CXTPCustomizeSheet  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083ff00
//
// 0083ff00  56                   push esi
// 0083ff01  6a01                 push 1
// 0083ff03  8bf1                 mov esi, ecx
// 0083ff05  e8de3bfbff           call 0x7f3ae8
// 0083ff0a  8bce                 mov ecx, esi
// 0083ff0c  e85fffffff           call 0x83fe70
// 0083ff11  8b8e8c000000         mov ecx, dword ptr [esi + 0x8c]
// 0083ff17  8b4074               mov eax, dword ptr [eax + 0x74]
// 0083ff1a  894824               mov dword ptr [eax + 0x24], ecx
// 0083ff1d  5e                   pop esi
// 0083ff1e  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeOptionsPage.cpp (function ?OnCheckAfterdelay@CXTPCustomizeOptionsPage@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeOptionsPage.cpp
