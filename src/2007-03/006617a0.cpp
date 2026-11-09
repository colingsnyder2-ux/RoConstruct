// from server: 100% by auto
// roc 2007-03 006617a0  unit: seg_00660000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006617a0
//
// 006617a0  56                   push esi
// 006617a1  6a01                 push 1
// 006617a3  8bf1                 mov esi, ecx
// 006617a5  e8d4cbfbff           call 0x61e37e
// 006617aa  8bce                 mov ecx, esi
// 006617ac  e86fffffff           call 0x661720
// 006617b1  8b8e8c000000         mov ecx, dword ptr [esi + 0x8c]
// 006617b7  8b4074               mov eax, dword ptr [eax + 0x74]
// 006617ba  894824               mov dword ptr [eax + 0x24], ecx
// 006617bd  5e                   pop esi
// 006617be  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeOptionsPage.cpp (function ?OnCheckAfterdelay@CXTPCustomizeOptionsPage@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeOptionsPage.cpp
