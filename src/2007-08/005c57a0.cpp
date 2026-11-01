// from server: 100% by auto
// roc 2007-08 005c57a0  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c57a0
//
// 005c57a0  8b442408             mov eax, dword ptr [esp + 8]
// 005c57a4  56                   push esi
// 005c57a5  8b742410             mov esi, dword ptr [esp + 0x10]
// 005c57a9  83c0fe               add eax, -2
// 005c57ac  83f803               cmp eax, 3
// 005c57af  57                   push edi
// 005c57b0  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005c57b4  7749                 ja 0x5c57ff
// 005c57b6  ff248508585c00       jmp dword ptr [eax*4 + 0x5c5808]
// 005c57bd  6a11                 push 0x11
// 005c57bf  6864967b00           push 0x7b9664
// 005c57c4  57                   push edi
// 005c57c5  e8a6d50400           call 0x612d70
// 005c57ca  83c40c               add esp, 0xc
// 005c57cd  8906                 mov dword ptr [esi], eax
// 005c57cf  c7460804000000       mov dword ptr [esi + 8], 4
// 005c57d6  83c610               add esi, 0x10
// 005c57d9  897708               mov dword ptr [edi + 8], esi
// 005c57dc  5f                   pop edi
// 005c57dd  5e                   pop esi
// 005c57de  c3                   ret 
// 005c57df  6a17                 push 0x17
// 005c57e1  684c967b00           push 0x7b964c
// 005c57e6  ebdc                 jmp 0x5c57c4
// 005c57e8  8b4708               mov eax, dword ptr [edi + 8]
// 005c57eb  8b48f0               mov ecx, dword ptr [eax - 0x10]
// 005c57ee  83e810               sub eax, 0x10
// 005c57f1  890e                 mov dword ptr [esi], ecx
// 005c57f3  8b5004               mov edx, dword ptr [eax + 4]
// 005c57f6  895604               mov dword ptr [esi + 4], edx
// 005c57f9  8b4008               mov eax, dword ptr [eax + 8]
// 005c57fc  894608               mov dword ptr [esi + 8], eax
// 005c57ff  83c610               add esi, 0x10
// 005c5802  897708               mov dword ptr [edi + 8], esi
// 005c5805  5f                   pop edi
// 005c5806  5e                   pop esi
// 005c5807  c3                   ret 
// 005c5808  e8575c00e8           call 0xe85cb464
// 005c580d  57                   push edi
// 005c580e  5c                   pop esp
// 005c580f  00bd575c00df         add byte ptr [ebp - 0x20ffa3a9], bh
// 005c5815  57                   push edi
// 005c5816  5c                   pop esp
// library lua-5.1/ldo.c (function _luaD_seterrorobj)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldo.c
