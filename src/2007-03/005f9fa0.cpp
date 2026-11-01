// from server: 100% by auto
// roc 2007-03 005f9fa0  unit: seg_005f0000  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9fa0
//
// 005f9fa0  55                   push ebp
// 005f9fa1  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 005f9fa5  56                   push esi
// 005f9fa6  57                   push edi
// 005f9fa7  8bf0                 mov esi, eax
// 005f9fa9  8b442410             mov eax, dword ptr [esp + 0x10]
// 005f9fad  55                   push ebp
// 005f9fae  50                   push eax
// 005f9faf  56                   push esi
// 005f9fb0  e86bfaffff           call 0x5f9a20
// 005f9fb5  8bf8                 mov edi, eax
// 005f9fb7  83c40c               add esp, 0xc
// 005f9fba  837f0800             cmp dword ptr [edi + 8], 0
// 005f9fbe  7507                 jne 0x5f9fc7
// 005f9fc0  5f                   pop edi
// 005f9fc1  5e                   pop esi
// 005f9fc2  83c8ff               or eax, 0xffffffff
// 005f9fc5  5d                   pop ebp
// 005f9fc6  c3                   ret 
// 005f9fc7  55                   push ebp
// 005f9fc8  53                   push ebx
// 005f9fc9  56                   push esi
// 005f9fca  e851faffff           call 0x5f9a20
// 005f9fcf  50                   push eax
// 005f9fd0  57                   push edi
// 005f9fd1  e85ae4ffff           call 0x5f8430
// 005f9fd6  83c414               add esp, 0x14
// 005f9fd9  85c0                 test eax, eax
// 005f9fdb  74e3                 je 0x5f9fc0
// 005f9fdd  8b542410             mov edx, dword ptr [esp + 0x10]
// 005f9fe1  8b4608               mov eax, dword ptr [esi + 8]
// 005f9fe4  57                   push edi
// 005f9fe5  56                   push esi
// 005f9fe6  8bcb                 mov ecx, ebx
// 005f9fe8  e8e3fbffff           call 0x5f9bd0
// 005f9fed  8b7608               mov esi, dword ptr [esi + 8]
// 005f9ff0  8b4608               mov eax, dword ptr [esi + 8]
// 005f9ff3  83c408               add esp, 8
// 005f9ff6  85c0                 test eax, eax
// 005f9ff8  7413                 je 0x5fa00d
// 005f9ffa  83f801               cmp eax, 1
// 005f9ffd  7505                 jne 0x5fa004
// 005f9fff  833e00               cmp dword ptr [esi], 0
// 005fa002  7409                 je 0x5fa00d
// 005fa004  5f                   pop edi
// 005fa005  5e                   pop esi
// 005fa006  b801000000           mov eax, 1
// 005fa00b  5d                   pop ebp
// 005fa00c  c3                   ret 
// 005fa00d  5f                   pop edi
// 005fa00e  5e                   pop esi
// 005fa00f  33c0                 xor eax, eax
// 005fa011  5d                   pop ebp
// 005fa012  c3                   ret 
// library lua-5.1.1/lvm.c (function _call_orderTM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lvm.c
