// from server: 100% by auto
// roc 2010-06 00845630  unit: CXTPDockBar::UDOCK_INFO::?$CArray  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00845630
//
// 00845630  53                   push ebx
// 00845631  56                   push esi
// 00845632  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00845636  8bd9                 mov ebx, ecx
// 00845638  85f6                 test esi, esi
// 0084563a  7d05                 jge 0x845641
// 0084563c  e80b26f6ff           call 0x7a7c4c
// 00845641  3b7308               cmp esi, dword ptr [ebx + 8]
// 00845644  7c0b                 jl 0x845651
// 00845646  6aff                 push -1
// 00845648  8d4601               lea eax, [esi + 1]
// 0084564b  50                   push eax
// 0084564c  e84ffdffff           call 0x8453a0
// 00845651  57                   push edi
// 00845652  8d3c76               lea edi, [esi + esi*2]
// 00845655  8b742414             mov esi, dword ptr [esp + 0x14]
// 00845659  c1e704               shl edi, 4
// 0084565c  037b04               add edi, dword ptr [ebx + 4]
// 0084565f  b90c000000           mov ecx, 0xc
// 00845664  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00845666  5f                   pop edi
// 00845667  5e                   pop esi
// 00845668  5b                   pop ebx
// 00845669  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPDockBar.cpp (function ?SetAtGrow@?$CArray@UDOCK_INFO@CXTPDockBar@@AAU12@@@QAEXHAAUDOCK_INFO@CXTPDockBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDockBar.cpp
