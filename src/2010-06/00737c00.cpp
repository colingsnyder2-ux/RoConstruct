// from server: 100% by auto
// roc 2010-06 00737c00  unit: seg_00730000  size: 244 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00737c00
//
// 00737c00  56                   push esi
// 00737c01  8b742408             mov esi, dword ptr [esp + 8]
// 00737c05  6a01                 push 1
// 00737c07  56                   push esi
// 00737c08  e8e3b2feff           call 0x722ef0
// 00737c0d  687c15a300           push 0xa3157c
// 00737c12  6a01                 push 1
// 00737c14  56                   push esi
// 00737c15  e8a6a9feff           call 0x7225c0
// 00737c1a  83c414               add esp, 0x14
// 00737c1d  85c0                 test eax, eax
// 00737c1f  0f85b2000000         jne 0x737cd7
// 00737c25  6a01                 push 1
// 00737c27  56                   push esi
// 00737c28  e81395feff           call 0x721140
// 00737c2d  83c408               add esp, 8
// 00737c30  83f804               cmp eax, 4
// 00737c33  7775                 ja 0x737caa
// 00737c35  ff2485e07c7300       jmp dword ptr [eax*4 + 0x737ce0]
// 00737c3c  6a00                 push 0
// 00737c3e  6a01                 push 1
// 00737c40  56                   push esi
// 00737c41  e80a97feff           call 0x721350
// 00737c46  50                   push eax
// 00737c47  56                   push esi
// 00737c48  e84399feff           call 0x721590
// 00737c4d  83c414               add esp, 0x14
// 00737c50  b801000000           mov eax, 1
// 00737c55  5e                   pop esi
// 00737c56  c3                   ret 
// 00737c57  6a01                 push 1
// 00737c59  56                   push esi
// 00737c5a  e8b194feff           call 0x721110
// 00737c5f  83c408               add esp, 8
// 00737c62  b801000000           mov eax, 1
// 00737c67  5e                   pop esi
// 00737c68  c3                   ret 
// 00737c69  6a01                 push 1
// 00737c6b  56                   push esi
// 00737c6c  e8af96feff           call 0x721320
// 00737c71  83c408               add esp, 8
// 00737c74  85c0                 test eax, eax
// 00737c76  b8c408a200           mov eax, 0xa208c4
// 00737c7b  7505                 jne 0x737c82
// 00737c7d  b8a432a100           mov eax, 0xa132a4
// 00737c82  50                   push eax
// 00737c83  56                   push esi
// 00737c84  e80799feff           call 0x721590
// 00737c89  83c408               add esp, 8
// 00737c8c  b801000000           mov eax, 1
// 00737c91  5e                   pop esi
// 00737c92  c3                   ret 
// 00737c93  6a03                 push 3
// 00737c95  6880dfa200           push 0xa2df80
// 00737c9a  56                   push esi
// 00737c9b  e8b098feff           call 0x721550
// 00737ca0  83c40c               add esp, 0xc
// 00737ca3  b801000000           mov eax, 1
// 00737ca8  5e                   pop esi
// 00737ca9  c3                   ret 
// 00737caa  6a01                 push 1
// 00737cac  56                   push esi
// 00737cad  e8ce97feff           call 0x721480
// 00737cb2  83c408               add esp, 8
// 00737cb5  50                   push eax
// 00737cb6  6a01                 push 1
// 00737cb8  56                   push esi
// 00737cb9  e88294feff           call 0x721140
// 00737cbe  50                   push eax
// 00737cbf  56                   push esi
// 00737cc0  e89b94feff           call 0x721160
// 00737cc5  83c410               add esp, 0x10
// 00737cc8  50                   push eax
// 00737cc9  68e4e8a400           push 0xa4e8e4
// 00737cce  56                   push esi
// 00737ccf  e85c99feff           call 0x721630
// 00737cd4  83c410               add esp, 0x10
// 00737cd7  b801000000           mov eax, 1
// 00737cdc  5e                   pop esi
// 00737cdd  c3                   ret 
// 00737cde  8bff                 mov edi, edi
// 00737ce0  93                   xchg ebx, eax
// 00737ce1  7c73                 jl 0x737d56
// 00737ce3  00697c               add byte ptr [ecx + 0x7c], ch
// 00737ce6  7300                 jae 0x737ce8
// 00737ce8  aa                   stosb byte ptr es:[edi], al
// 00737ce9  7c73                 jl 0x737d5e
// 00737ceb  003c7c               add byte ptr [esp + edi*2], bh
// 00737cee  7300                 jae 0x737cf0
// 00737cf0  57                   push edi
// 00737cf1  7c73                 jl 0x737d66
// library lua-5.1/lbaselib.c (function _luaB_tostring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
