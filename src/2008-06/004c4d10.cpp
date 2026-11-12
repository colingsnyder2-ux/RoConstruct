// from server: 100% by auto
// roc 2008-06 004c4d10  unit: ProfiledRakPeer  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c4d10
//
// 004c4d10  56                   push esi
// 004c4d11  57                   push edi
// 004c4d12  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004c4d16  33f6                 xor esi, esi
// 004c4d18  e803f40000           call 0x4d4120
// 004c4d1d  8904b7               mov dword ptr [edi + esi*4], eax
// 004c4d20  46                   inc esi
// 004c4d21  83fe04               cmp esi, 4
// 004c4d24  7cf2                 jl 0x4c4d18
// 004c4d26  814f0c00000080       or dword ptr [edi + 0xc], 0x80000000
// 004c4d2d  830f01               or dword ptr [edi], 1
// 004c4d30  6a05                 push 5
// 004c4d32  57                   push edi
// 004c4d33  e828ebffff           call 0x4c3860
// 004c4d38  83c408               add esp, 8
// 004c4d3b  84c0                 test al, al
// 004c4d3d  74d7                 je 0x4c4d16
// 004c4d3f  5f                   pop edi
// 004c4d40  5e                   pop esi
// 004c4d41  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$generateStrongPseudoPrime@$$BY03I@big@@YAXAAY03I@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
