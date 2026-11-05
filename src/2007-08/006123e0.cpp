// from server: 100% by auto
// roc 2007-08 006123e0  unit: seg_00610000  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006123e0
//
// 006123e0  56                   push esi
// 006123e1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006123e5  8b4610               mov eax, dword ptr [esi + 0x10]
// 006123e8  3db8327c00           cmp eax, 0x7c32b8
// 006123ed  57                   push edi
// 006123ee  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006123f2  741a                 je 0x61240e
// 006123f4  8a4e07               mov cl, byte ptr [esi + 7]
// 006123f7  ba01000000           mov edx, 1
// 006123fc  d3e2                 shl edx, cl
// 006123fe  6a00                 push 0
// 00612400  c1e205               shl edx, 5
// 00612403  52                   push edx
// 00612404  50                   push eax
// 00612405  57                   push edi
// 00612406  e8e5150000           call 0x6139f0
// 0061240b  83c410               add esp, 0x10
// 0061240e  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00612411  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00612414  6a00                 push 0
// 00612416  c1e004               shl eax, 4
// 00612419  50                   push eax
// 0061241a  51                   push ecx
// 0061241b  57                   push edi
// 0061241c  e8cf150000           call 0x6139f0
// 00612421  6a00                 push 0
// 00612423  6a20                 push 0x20
// 00612425  56                   push esi
// 00612426  57                   push edi
// 00612427  e8c4150000           call 0x6139f0
// 0061242c  83c420               add esp, 0x20
// 0061242f  5f                   pop edi
// 00612430  5e                   pop esi
// 00612431  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_free)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
