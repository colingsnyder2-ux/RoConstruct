// from server: 100% by auto
// roc 2009-06 007b2a50  unit: CXTPDockBar  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b2a50
//
// 007b2a50  53                   push ebx
// 007b2a51  56                   push esi
// 007b2a52  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007b2a56  8bd9                 mov ebx, ecx
// 007b2a58  85f6                 test esi, esi
// 007b2a5a  7d05                 jge 0x7b2a61
// 007b2a5c  e88362f6ff           call 0x718ce4
// 007b2a61  3b7308               cmp esi, dword ptr [ebx + 8]
// 007b2a64  7c0b                 jl 0x7b2a71
// 007b2a66  6aff                 push -1
// 007b2a68  8d4601               lea eax, [esi + 1]
// 007b2a6b  50                   push eax
// 007b2a6c  e84ffdffff           call 0x7b27c0
// 007b2a71  57                   push edi
// 007b2a72  8d3c76               lea edi, [esi + esi*2]
// 007b2a75  8b742414             mov esi, dword ptr [esp + 0x14]
// 007b2a79  c1e704               shl edi, 4
// 007b2a7c  037b04               add edi, dword ptr [ebx + 4]
// 007b2a7f  b90c000000           mov ecx, 0xc
// 007b2a84  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 007b2a86  5f                   pop edi
// 007b2a87  5e                   pop esi
// 007b2a88  5b                   pop ebx
// 007b2a89  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPDockBar.cpp (function ?SetAtGrow@?$CArray@UDOCK_INFO@CXTPDockBar@@AAU12@@@QAEXHAAUDOCK_INFO@CXTPDockBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockBar.cpp
