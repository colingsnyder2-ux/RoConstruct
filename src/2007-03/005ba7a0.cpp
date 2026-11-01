// from server: 100% by auto
// roc 2007-03 005ba7a0  unit: seg_005b0000  size: 283 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ba7a0
//
// 005ba7a0  53                   push ebx
// 005ba7a1  55                   push ebp
// 005ba7a2  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 005ba7a6  85ed                 test ebp, ebp
// 005ba7a8  56                   push esi
// 005ba7a9  8b742410             mov esi, dword ptr [esp + 0x10]
// 005ba7ad  57                   push edi
// 005ba7ae  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005ba7b2  0f8499000000         je 0x5ba851
// 005ba7b8  33db                 xor ebx, ebx
// 005ba7ba  391f                 cmp dword ptr [edi], ebx
// 005ba7bc  8bc7                 mov eax, edi
// 005ba7be  740b                 je 0x5ba7cb
// 005ba7c0  83c008               add eax, 8
// 005ba7c3  83c301               add ebx, 1
// 005ba7c6  833800               cmp dword ptr [eax], 0
// 005ba7c9  75f5                 jne 0x5ba7c0
// 005ba7cb  53                   push ebx
// 005ba7cc  6820927b00           push 0x7b9220
// 005ba7d1  68f0d8ffff           push 0xffffd8f0
// 005ba7d6  56                   push esi
// 005ba7d7  e8f4f4ffff           call 0x5b9cd0
// 005ba7dc  55                   push ebp
// 005ba7dd  6aff                 push -1
// 005ba7df  56                   push esi
// 005ba7e0  e8ebeaffff           call 0x5b92d0
// 005ba7e5  6aff                 push -1
// 005ba7e7  56                   push esi
// 005ba7e8  e853e4ffff           call 0x5b8c40
// 005ba7ed  83c424               add esp, 0x24
// 005ba7f0  83f805               cmp eax, 5
// 005ba7f3  743f                 je 0x5ba834
// 005ba7f5  6afe                 push -2
// 005ba7f7  56                   push esi
// 005ba7f8  e863e2ffff           call 0x5b8a60
// 005ba7fd  53                   push ebx
// 005ba7fe  55                   push ebp
// 005ba7ff  68eed8ffff           push 0xffffd8ee
// 005ba804  56                   push esi
// 005ba805  e8c6f4ffff           call 0x5b9cd0
// 005ba80a  83c418               add esp, 0x18
// 005ba80d  85c0                 test eax, eax
// 005ba80f  740f                 je 0x5ba820
// 005ba811  55                   push ebp
// 005ba812  6800927b00           push 0x7b9200
// 005ba817  56                   push esi
// 005ba818  e833f3ffff           call 0x5b9b50
// 005ba81d  83c40c               add esp, 0xc
// 005ba820  6aff                 push -1
// 005ba822  56                   push esi
// 005ba823  e8e8e3ffff           call 0x5b8c10
// 005ba828  55                   push ebp
// 005ba829  6afd                 push -3
// 005ba82b  56                   push esi
// 005ba82c  e8bfecffff           call 0x5b94f0
// 005ba831  83c414               add esp, 0x14
// 005ba834  6afe                 push -2
// 005ba836  56                   push esi
// 005ba837  e874e2ffff           call 0x5b8ab0
// 005ba83c  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 005ba840  83c8ff               or eax, 0xffffffff
// 005ba843  2bc5                 sub eax, ebp
// 005ba845  50                   push eax
// 005ba846  56                   push esi
// 005ba847  e8b4e2ffff           call 0x5b8b00
// 005ba84c  83c410               add esp, 0x10
// 005ba84f  eb04                 jmp 0x5ba855
// 005ba851  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 005ba855  833f00               cmp dword ptr [edi], 0
// 005ba858  744d                 je 0x5ba8a7
// 005ba85a  b8feffffff           mov eax, 0xfffffffe
// 005ba85f  2bc5                 sub eax, ebp
// 005ba861  89442418             mov dword ptr [esp + 0x18], eax
// 005ba865  85ed                 test ebp, ebp
// 005ba867  7e1a                 jle 0x5ba883
// 005ba869  8bdd                 mov ebx, ebp
// 005ba86b  f7db                 neg ebx
// 005ba86d  8d4900               lea ecx, [ecx]
// 005ba870  53                   push ebx
// 005ba871  56                   push esi
// 005ba872  e899e3ffff           call 0x5b8c10
// 005ba877  83c408               add esp, 8
// 005ba87a  83ed01               sub ebp, 1
// 005ba87d  75f1                 jne 0x5ba870
// 005ba87f  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 005ba883  8b4f04               mov ecx, dword ptr [edi + 4]
// 005ba886  55                   push ebp
// 005ba887  51                   push ecx
// 005ba888  56                   push esi
// 005ba889  e802e9ffff           call 0x5b9190
// 005ba88e  8b17                 mov edx, dword ptr [edi]
// 005ba890  8b442424             mov eax, dword ptr [esp + 0x24]
// 005ba894  52                   push edx
// 005ba895  50                   push eax
// 005ba896  56                   push esi
// 005ba897  e854ecffff           call 0x5b94f0
// 005ba89c  83c708               add edi, 8
// 005ba89f  83c418               add esp, 0x18
// 005ba8a2  833f00               cmp dword ptr [edi], 0
// 005ba8a5  75be                 jne 0x5ba865
// 005ba8a7  83c9ff               or ecx, 0xffffffff
// 005ba8aa  2bcd                 sub ecx, ebp
// 005ba8ac  51                   push ecx
// 005ba8ad  56                   push esi
// 005ba8ae  e8ade1ffff           call 0x5b8a60
// 005ba8b3  83c408               add esp, 8
// 005ba8b6  5f                   pop edi
// 005ba8b7  5e                   pop esi
// 005ba8b8  5d                   pop ebp
// 005ba8b9  5b                   pop ebx
// 005ba8ba  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_openlib)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
