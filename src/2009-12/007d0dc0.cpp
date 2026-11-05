// from server: 100% by auto
// roc 2009-12 007d0dc0  unit: RBX::PartDropTool  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d0dc0
//
// 007d0dc0  8b542404             mov edx, dword ptr [esp + 4]
// 007d0dc4  837a6800             cmp dword ptr [edx + 0x68], 0
// 007d0dc8  53                   push ebx
// 007d0dc9  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 007d0dcd  56                   push esi
// 007d0dce  8d7268               lea esi, [edx + 0x68]
// 007d0dd1  57                   push edi
// 007d0dd2  8b7a10               mov edi, dword ptr [edx + 0x10]
// 007d0dd5  7412                 je 0x7d0de9
// 007d0dd7  8b06                 mov eax, dword ptr [esi]
// 007d0dd9  8b4808               mov ecx, dword ptr [eax + 8]
// 007d0ddc  3bcb                 cmp ecx, ebx
// 007d0dde  7209                 jb 0x7d0de9
// 007d0de0  7448                 je 0x7d0e2a
// 007d0de2  833800               cmp dword ptr [eax], 0
// 007d0de5  8bf0                 mov esi, eax
// 007d0de7  75ee                 jne 0x7d0dd7
// 007d0de9  6a20                 push 0x20
// 007d0deb  6a00                 push 0
// 007d0ded  6a00                 push 0
// 007d0def  52                   push edx
// 007d0df0  e8bb090000           call 0x7d17b0
// 007d0df5  c640040a             mov byte ptr [eax + 4], 0xa
// 007d0df9  8a4f14               mov cl, byte ptr [edi + 0x14]
// 007d0dfc  895808               mov dword ptr [eax + 8], ebx
// 007d0dff  83c410               add esp, 0x10
// 007d0e02  80e103               and cl, 3
// 007d0e05  884805               mov byte ptr [eax + 5], cl
// 007d0e08  8b16                 mov edx, dword ptr [esi]
// 007d0e0a  8910                 mov dword ptr [eax], edx
// 007d0e0c  8906                 mov dword ptr [esi], eax
// 007d0e0e  8d4f78               lea ecx, [edi + 0x78]
// 007d0e11  894810               mov dword ptr [eax + 0x10], ecx
// 007d0e14  8b8f8c000000         mov ecx, dword ptr [edi + 0x8c]
// 007d0e1a  894814               mov dword ptr [eax + 0x14], ecx
// 007d0e1d  894110               mov dword ptr [ecx + 0x10], eax
// 007d0e20  89878c000000         mov dword ptr [edi + 0x8c], eax
// 007d0e26  5f                   pop edi
// 007d0e27  5e                   pop esi
// 007d0e28  5b                   pop ebx
// 007d0e29  c3                   ret 
// 007d0e2a  8a4805               mov cl, byte ptr [eax + 5]
// 007d0e2d  0fb65f14             movzx ebx, byte ptr [edi + 0x14]
// 007d0e31  0fb6d1               movzx edx, cl
// 007d0e34  83e203               and edx, 3
// 007d0e37  f7d3                 not ebx
// 007d0e39  84d3                 test bl, dl
// 007d0e3b  74e9                 je 0x7d0e26
// 007d0e3d  5f                   pop edi
// 007d0e3e  80f103               xor cl, 3
// 007d0e41  5e                   pop esi
// 007d0e42  884805               mov byte ptr [eax + 5], cl
// 007d0e45  5b                   pop ebx
// 007d0e46  c3                   ret 
// library lua-5.1.2/lfunc.c (function _luaF_findupval)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lfunc.c
