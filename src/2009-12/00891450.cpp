// from server: 100% by auto
// roc 2009-12 00891450  unit: CXTPDockBar::UDOCK_INFO::?$CArray  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00891450
//
// 00891450  53                   push ebx
// 00891451  56                   push esi
// 00891452  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00891456  8bd9                 mov ebx, ecx
// 00891458  85f6                 test esi, esi
// 0089145a  7d05                 jge 0x891461
// 0089145c  e8ab26f6ff           call 0x7f3b0c
// 00891461  3b7308               cmp esi, dword ptr [ebx + 8]
// 00891464  7c0b                 jl 0x891471
// 00891466  6aff                 push -1
// 00891468  8d4601               lea eax, [esi + 1]
// 0089146b  50                   push eax
// 0089146c  e84ffdffff           call 0x8911c0
// 00891471  57                   push edi
// 00891472  8d3c76               lea edi, [esi + esi*2]
// 00891475  8b742414             mov esi, dword ptr [esp + 0x14]
// 00891479  c1e704               shl edi, 4
// 0089147c  037b04               add edi, dword ptr [ebx + 4]
// 0089147f  b90c000000           mov ecx, 0xc
// 00891484  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00891486  5f                   pop edi
// 00891487  5e                   pop esi
// 00891488  5b                   pop ebx
// 00891489  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPDockBar.cpp (function ?SetAtGrow@?$CArray@UDOCK_INFO@CXTPDockBar@@AAU12@@@QAEXHAAUDOCK_INFO@CXTPDockBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockBar.cpp
