// from server: 100% by auto
// roc 2009-06 00765130  unit: CXTPCustomizeSheet  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00765130
//
// 00765130  56                   push esi
// 00765131  6a01                 push 1
// 00765133  8bf1                 mov esi, ecx
// 00765135  e8863bfbff           call 0x718cc0
// 0076513a  8bce                 mov ecx, esi
// 0076513c  e85fffffff           call 0x7650a0
// 00765141  8b8e8c000000         mov ecx, dword ptr [esi + 0x8c]
// 00765147  8b4074               mov eax, dword ptr [eax + 0x74]
// 0076514a  894824               mov dword ptr [eax + 0x24], ecx
// 0076514d  5e                   pop esi
// 0076514e  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeOptionsPage.cpp (function ?OnCheckAfterdelay@CXTPCustomizeOptionsPage@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeOptionsPage.cpp
