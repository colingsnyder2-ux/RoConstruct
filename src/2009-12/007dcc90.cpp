// from server: 100% by auto
// roc 2009-12 007dcc90  unit: RBX::GroupDragTool  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dcc90
//
// 007dcc90  56                   push esi
// 007dcc91  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007dcc95  57                   push edi
// 007dcc96  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007dcc9a  56                   push esi
// 007dcc9b  57                   push edi
// 007dcc9c  e8dffbffff           call 0x7dc880
// 007dcca1  83c408               add esp, 8
// 007dcca4  833e0c               cmp dword ptr [esi], 0xc
// 007dcca7  7526                 jne 0x7dcccf
// 007dcca9  8b4610               mov eax, dword ptr [esi + 0x10]
// 007dccac  3b4614               cmp eax, dword ptr [esi + 0x14]
// 007dccaf  8b4608               mov eax, dword ptr [esi + 8]
// 007dccb2  7428                 je 0x7dccdc
// 007dccb4  0fb64f32             movzx ecx, byte ptr [edi + 0x32]
// 007dccb8  3bc1                 cmp eax, ecx
// 007dccba  7c13                 jl 0x7dcccf
// 007dccbc  50                   push eax
// 007dccbd  8bc6                 mov eax, esi
// 007dccbf  8bcf                 mov ecx, edi
// 007dccc1  e82afeffff           call 0x7dcaf0
// 007dccc6  8b4608               mov eax, dword ptr [esi + 8]
// 007dccc9  83c404               add esp, 4
// 007dcccc  5f                   pop edi
// 007dcccd  5e                   pop esi
// 007dccce  c3                   ret 
// 007dcccf  56                   push esi
// 007dccd0  57                   push edi
// 007dccd1  e83affffff           call 0x7dcc10
// 007dccd6  8b4608               mov eax, dword ptr [esi + 8]
// 007dccd9  83c408               add esp, 8
// 007dccdc  5f                   pop edi
// 007dccdd  5e                   pop esi
// 007dccde  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_exp2anyreg)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
