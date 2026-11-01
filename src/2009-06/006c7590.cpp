// from server: 100% by auto
// roc 2009-06 006c7590  unit: seg_006c0000  size: 244 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c7590
//
// 006c7590  56                   push esi
// 006c7591  8b742408             mov esi, dword ptr [esp + 8]
// 006c7595  6a01                 push 1
// 006c7597  56                   push esi
// 006c7598  e8f336ffff           call 0x6bac90
// 006c759d  680cb48d00           push 0x8db40c
// 006c75a2  6a01                 push 1
// 006c75a4  56                   push esi
// 006c75a5  e8b62dffff           call 0x6ba360
// 006c75aa  83c414               add esp, 0x14
// 006c75ad  85c0                 test eax, eax
// 006c75af  0f85b2000000         jne 0x6c7667
// 006c75b5  6a01                 push 1
// 006c75b7  56                   push esi
// 006c75b8  e8b319ffff           call 0x6b8f70
// 006c75bd  83c408               add esp, 8
// 006c75c0  83f804               cmp eax, 4
// 006c75c3  7775                 ja 0x6c763a
// 006c75c5  ff248570766c00       jmp dword ptr [eax*4 + 0x6c7670]
// 006c75cc  6a00                 push 0
// 006c75ce  6a01                 push 1
// 006c75d0  56                   push esi
// 006c75d1  e8aa1bffff           call 0x6b9180
// 006c75d6  50                   push eax
// 006c75d7  56                   push esi
// 006c75d8  e8e31dffff           call 0x6b93c0
// 006c75dd  83c414               add esp, 0x14
// 006c75e0  b801000000           mov eax, 1
// 006c75e5  5e                   pop esi
// 006c75e6  c3                   ret 
// 006c75e7  6a01                 push 1
// 006c75e9  56                   push esi
// 006c75ea  e85119ffff           call 0x6b8f40
// 006c75ef  83c408               add esp, 8
// 006c75f2  b801000000           mov eax, 1
// 006c75f7  5e                   pop esi
// 006c75f8  c3                   ret 
// 006c75f9  6a01                 push 1
// 006c75fb  56                   push esi
// 006c75fc  e84f1bffff           call 0x6b9150
// 006c7601  83c408               add esp, 8
// 006c7604  85c0                 test eax, eax
// 006c7606  b894ba8c00           mov eax, 0x8cba94
// 006c760b  7505                 jne 0x6c7612
// 006c760d  b8fcfc8b00           mov eax, 0x8bfcfc
// 006c7612  50                   push eax
// 006c7613  56                   push esi
// 006c7614  e8a71dffff           call 0x6b93c0
// 006c7619  83c408               add esp, 8
// 006c761c  b801000000           mov eax, 1
// 006c7621  5e                   pop esi
// 006c7622  c3                   ret 
// 006c7623  6a03                 push 3
// 006c7625  68a0818d00           push 0x8d81a0
// 006c762a  56                   push esi
// 006c762b  e8501dffff           call 0x6b9380
// 006c7630  83c40c               add esp, 0xc
// 006c7633  b801000000           mov eax, 1
// 006c7638  5e                   pop esi
// 006c7639  c3                   ret 
// 006c763a  6a01                 push 1
// 006c763c  56                   push esi
// 006c763d  e86e1cffff           call 0x6b92b0
// 006c7642  83c408               add esp, 8
// 006c7645  50                   push eax
// 006c7646  6a01                 push 1
// 006c7648  56                   push esi
// 006c7649  e82219ffff           call 0x6b8f70
// 006c764e  50                   push eax
// 006c764f  56                   push esi
// 006c7650  e83b19ffff           call 0x6b8f90
// 006c7655  83c410               add esp, 0x10
// 006c7658  50                   push eax
// 006c7659  687cc18e00           push 0x8ec17c
// 006c765e  56                   push esi
// 006c765f  e8fc1dffff           call 0x6b9460
// 006c7664  83c410               add esp, 0x10
// 006c7667  b801000000           mov eax, 1
// 006c766c  5e                   pop esi
// 006c766d  c3                   ret 
// 006c766e  8bff                 mov edi, edi
// 006c7670  23766c               and esi, dword ptr [esi + 0x6c]
// 006c7673  00f9                 add cl, bh
// 006c7675  756c                 jne 0x6c76e3
// 006c7677  003a                 add byte ptr [edx], bh
// 006c7679  766c                 jbe 0x6c76e7
// 006c767b  00cc                 add ah, cl
// 006c767d  756c                 jne 0x6c76eb
// 006c767f  00e7                 add bh, ah
// 006c7681  756c                 jne 0x6c76ef
// library lua-5.1/lbaselib.c (function _luaB_tostring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
