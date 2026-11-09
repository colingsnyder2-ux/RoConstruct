// from server: 100% by auto
// roc 2007-08 00629b10  unit: RBX::AssemblyStage  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00629b10
//
// 00629b10  83ec18               sub esp, 0x18
// 00629b13  d9ee                 fldz 
// 00629b15  83c8ff               or eax, 0xffffffff
// 00629b18  89442414             mov dword ptr [esp + 0x14], eax
// 00629b1c  dd5c2408             fstp qword ptr [esp + 8]
// 00629b20  89442410             mov dword ptr [esp + 0x10], eax
// 00629b24  8b442420             mov eax, dword ptr [esp + 0x20]
// 00629b28  83e800               sub eax, 0
// 00629b2b  53                   push ebx
// 00629b2c  57                   push edi
// 00629b2d  c744240805000000     mov dword ptr [esp + 8], 5
// 00629b35  7443                 je 0x629b7a
// 00629b37  83e801               sub eax, 1
// 00629b3a  7429                 je 0x629b65
// 00629b3c  83e801               sub eax, 1
// 00629b3f  755f                 jne 0x629ba0
// 00629b41  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 00629b45  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00629b49  53                   push ebx
// 00629b4a  57                   push edi
// 00629b4b  e8c0f8ffff           call 0x629410
// 00629b50  8d442410             lea eax, [esp + 0x10]
// 00629b54  50                   push eax
// 00629b55  6a14                 push 0x14
// 00629b57  e874feffff           call 0x6299d0
// 00629b5c  83c410               add esp, 0x10
// 00629b5f  5f                   pop edi
// 00629b60  5b                   pop ebx
// 00629b61  83c418               add esp, 0x18
// 00629b64  c3                   ret 
// 00629b65  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00629b69  56                   push esi
// 00629b6a  8b742430             mov esi, dword ptr [esp + 0x30]
// 00629b6e  e87dfdffff           call 0x6298f0
// 00629b73  5e                   pop esi
// 00629b74  5f                   pop edi
// 00629b75  5b                   pop ebx
// 00629b76  83c418               add esp, 0x18
// 00629b79  c3                   ret 
// 00629b7a  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 00629b7e  833b04               cmp dword ptr [ebx], 4
// 00629b81  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00629b85  750a                 jne 0x629b91
// 00629b87  53                   push ebx
// 00629b88  57                   push edi
// 00629b89  e882f8ffff           call 0x629410
// 00629b8e  83c408               add esp, 8
// 00629b91  8d4c2408             lea ecx, [esp + 8]
// 00629b95  51                   push ecx
// 00629b96  6a12                 push 0x12
// 00629b98  e833feffff           call 0x6299d0
// 00629b9d  83c408               add esp, 8
// 00629ba0  5f                   pop edi
// 00629ba1  5b                   pop ebx
// 00629ba2  83c418               add esp, 0x18
// 00629ba5  c3                   ret 
// library lua-5.1.2/lcode.c (function _luaK_prefix)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lcode.c
