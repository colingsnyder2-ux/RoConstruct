// from server: 100% by auto
// roc 2011-06 00426780  unit: CInstanceExplorer  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00426780
//
// 00426780  0fb7442404           movzx eax, word ptr [esp + 4]
// 00426785  56                   push esi
// 00426786  50                   push eax
// 00426787  6a04                 push 4
// 00426789  50                   push eax
// 0042678a  8bf1                 mov esi, ecx
// 0042678c  e84b423e00           call 0x80a9dc
// 00426791  50                   push eax
// 00426792  ff15801ca400         call dword ptr [0xa41c80]
// 00426798  50                   push eax
// 00426799  8bce                 mov ecx, esi
// 0042679b  e836423e00           call 0x80a9d6
// 004267a0  5e                   pop esi
// 004267a1  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCommandBars.cpp (function ?LoadMenuA@CMenu@@QAEHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCommandBars.cpp
