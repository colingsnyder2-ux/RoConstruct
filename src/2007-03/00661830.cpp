// from server: 100% by auto
// roc 2007-03 00661830  unit: seg_00660000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00661830
//
// 00661830  56                   push esi
// 00661831  6a01                 push 1
// 00661833  8bf1                 mov esi, ecx
// 00661835  e844cbfbff           call 0x61e37e
// 0066183a  8bce                 mov ecx, esi
// 0066183c  e8dffeffff           call 0x661720
// 00661841  8b8e98000000         mov ecx, dword ptr [esi + 0x98]
// 00661847  8b4074               mov eax, dword ptr [eax + 0x74]
// 0066184a  89482c               mov dword ptr [eax + 0x2c], ecx
// 0066184d  5e                   pop esi
// 0066184e  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeOptionsPage.cpp (function ?OnCheckShortcuts@CXTPCustomizeOptionsPage@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeOptionsPage.cpp
