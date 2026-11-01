// from server: 100% by auto
// roc 2007-03 005fc9a0  unit: seg_005f0000  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fc9a0
//
// 005fc9a0  8b542404             mov edx, dword ptr [esp + 4]
// 005fc9a4  8b4268               mov eax, dword ptr [edx + 0x68]
// 005fc9a7  85c0                 test eax, eax
// 005fc9a9  53                   push ebx
// 005fc9aa  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 005fc9ae  56                   push esi
// 005fc9af  8b7210               mov esi, dword ptr [edx + 0x10]
// 005fc9b2  57                   push edi
// 005fc9b3  8d7a68               lea edi, [edx + 0x68]
// 005fc9b6  7411                 je 0x5fc9c9
// 005fc9b8  8b4808               mov ecx, dword ptr [eax + 8]
// 005fc9bb  3bcb                 cmp ecx, ebx
// 005fc9bd  720a                 jb 0x5fc9c9
// 005fc9bf  7449                 je 0x5fca0a
// 005fc9c1  8bf8                 mov edi, eax
// 005fc9c3  8b00                 mov eax, dword ptr [eax]
// 005fc9c5  85c0                 test eax, eax
// 005fc9c7  75ef                 jne 0x5fc9b8
// 005fc9c9  6a20                 push 0x20
// 005fc9cb  6a00                 push 0
// 005fc9cd  6a00                 push 0
// 005fc9cf  52                   push edx
// 005fc9d0  e8cb090000           call 0x5fd3a0
// 005fc9d5  c640040a             mov byte ptr [eax + 4], 0xa
// 005fc9d9  8a4e14               mov cl, byte ptr [esi + 0x14]
// 005fc9dc  895808               mov dword ptr [eax + 8], ebx
// 005fc9df  83c410               add esp, 0x10
// 005fc9e2  80e103               and cl, 3
// 005fc9e5  884805               mov byte ptr [eax + 5], cl
// 005fc9e8  8b17                 mov edx, dword ptr [edi]
// 005fc9ea  8910                 mov dword ptr [eax], edx
// 005fc9ec  8907                 mov dword ptr [edi], eax
// 005fc9ee  8d4e78               lea ecx, [esi + 0x78]
// 005fc9f1  894810               mov dword ptr [eax + 0x10], ecx
// 005fc9f4  8b8e8c000000         mov ecx, dword ptr [esi + 0x8c]
// 005fc9fa  894814               mov dword ptr [eax + 0x14], ecx
// 005fc9fd  894110               mov dword ptr [ecx + 0x10], eax
// 005fca00  89868c000000         mov dword ptr [esi + 0x8c], eax
// 005fca06  5f                   pop edi
// 005fca07  5e                   pop esi
// 005fca08  5b                   pop ebx
// 005fca09  c3                   ret 
// 005fca0a  8a4805               mov cl, byte ptr [eax + 5]
// 005fca0d  0fb65e14             movzx ebx, byte ptr [esi + 0x14]
// 005fca11  0fb6d1               movzx edx, cl
// 005fca14  83e203               and edx, 3
// 005fca17  f7d3                 not ebx
// 005fca19  84d3                 test bl, dl
// 005fca1b  74e9                 je 0x5fca06
// 005fca1d  5f                   pop edi
// 005fca1e  80f103               xor cl, 3
// 005fca21  5e                   pop esi
// 005fca22  884805               mov byte ptr [eax + 5], cl
// 005fca25  5b                   pop ebx
// 005fca26  c3                   ret 
// library lua-5.1.1/lfunc.c (function _luaF_findupval)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lfunc.c
