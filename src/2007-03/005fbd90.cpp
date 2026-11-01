// from server: 100% by auto
// roc 2007-03 005fbd90  unit: seg_005f0000  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fbd90
//
// 005fbd90  56                   push esi
// 005fbd91  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005fbd95  8b4610               mov eax, dword ptr [esi + 0x10]
// 005fbd98  3d70037c00           cmp eax, 0x7c0370
// 005fbd9d  57                   push edi
// 005fbd9e  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005fbda2  741a                 je 0x5fbdbe
// 005fbda4  8a4e07               mov cl, byte ptr [esi + 7]
// 005fbda7  ba01000000           mov edx, 1
// 005fbdac  d3e2                 shl edx, cl
// 005fbdae  6a00                 push 0
// 005fbdb0  c1e205               shl edx, 5
// 005fbdb3  52                   push edx
// 005fbdb4  50                   push eax
// 005fbdb5  57                   push edi
// 005fbdb6  e8e5150000           call 0x5fd3a0
// 005fbdbb  83c410               add esp, 0x10
// 005fbdbe  8b461c               mov eax, dword ptr [esi + 0x1c]
// 005fbdc1  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005fbdc4  6a00                 push 0
// 005fbdc6  c1e004               shl eax, 4
// 005fbdc9  50                   push eax
// 005fbdca  51                   push ecx
// 005fbdcb  57                   push edi
// 005fbdcc  e8cf150000           call 0x5fd3a0
// 005fbdd1  6a00                 push 0
// 005fbdd3  6a20                 push 0x20
// 005fbdd5  56                   push esi
// 005fbdd6  57                   push edi
// 005fbdd7  e8c4150000           call 0x5fd3a0
// 005fbddc  83c420               add esp, 0x20
// 005fbddf  5f                   pop edi
// 005fbde0  5e                   pop esi
// 005fbde1  c3                   ret 
// library lua-5.1.1/ltable.c (function _luaH_free)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
