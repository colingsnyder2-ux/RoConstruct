// from server: 100% by auto
// roc 2009-12 0078aa70  unit: RBX::UniversalTool  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078aa70
//
// 0078aa70  53                   push ebx
// 0078aa71  55                   push ebp
// 0078aa72  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0078aa76  56                   push esi
// 0078aa77  8b742418             mov esi, dword ptr [esp + 0x18]
// 0078aa7b  57                   push edi
// 0078aa7c  85f6                 test esi, esi
// 0078aa7e  741b                 je 0x78aa9b
// 0078aa80  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0078aa84  57                   push edi
// 0078aa85  55                   push ebp
// 0078aa86  e805dfffff           call 0x788990
// 0078aa8b  83c408               add esp, 8
// 0078aa8e  85c0                 test eax, eax
// 0078aa90  7f04                 jg 0x78aa96
// 0078aa92  8bc6                 mov eax, esi
// 0078aa94  eb15                 jmp 0x78aaab
// 0078aa96  6a00                 push 0
// 0078aa98  57                   push edi
// 0078aa99  eb07                 jmp 0x78aaa2
// 0078aa9b  8b442418             mov eax, dword ptr [esp + 0x18]
// 0078aa9f  6a00                 push 0
// 0078aaa1  50                   push eax
// 0078aaa2  55                   push ebp
// 0078aaa3  e8c8fcffff           call 0x78a770
// 0078aaa8  83c40c               add esp, 0xc
// 0078aaab  8b742420             mov esi, dword ptr [esp + 0x20]
// 0078aaaf  8b0e                 mov ecx, dword ptr [esi]
// 0078aab1  33ff                 xor edi, edi
// 0078aab3  85c9                 test ecx, ecx
// 0078aab5  743b                 je 0x78aaf2
// 0078aab7  8bd0                 mov edx, eax
// 0078aab9  8da42400000000       lea esp, [esp]
// 0078aac0  8a19                 mov bl, byte ptr [ecx]
// 0078aac2  3a1a                 cmp bl, byte ptr [edx]
// 0078aac4  751a                 jne 0x78aae0
// 0078aac6  84db                 test bl, bl
// 0078aac8  7412                 je 0x78aadc
// 0078aaca  8a5901               mov bl, byte ptr [ecx + 1]
// 0078aacd  3a5a01               cmp bl, byte ptr [edx + 1]
// 0078aad0  750e                 jne 0x78aae0
// 0078aad2  83c102               add ecx, 2
// 0078aad5  83c202               add edx, 2
// 0078aad8  84db                 test bl, bl
// 0078aada  75e4                 jne 0x78aac0
// 0078aadc  33c9                 xor ecx, ecx
// 0078aade  eb05                 jmp 0x78aae5
// 0078aae0  1bc9                 sbb ecx, ecx
// 0078aae2  83d9ff               sbb ecx, -1
// 0078aae5  85c9                 test ecx, ecx
// 0078aae7  7429                 je 0x78ab12
// 0078aae9  8b4cbe04             mov ecx, dword ptr [esi + edi*4 + 4]
// 0078aaed  47                   inc edi
// 0078aaee  85c9                 test ecx, ecx
// 0078aaf0  75c5                 jne 0x78aab7
// 0078aaf2  50                   push eax
// 0078aaf3  68f49d9e00           push 0x9e9df4
// 0078aaf8  55                   push ebp
// 0078aaf9  e882e3ffff           call 0x788e80
// 0078aafe  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0078ab02  50                   push eax
// 0078ab03  51                   push ecx
// 0078ab04  55                   push ebp
// 0078ab05  e876faffff           call 0x78a580
// 0078ab0a  83c418               add esp, 0x18
// 0078ab0d  5f                   pop edi
// 0078ab0e  5e                   pop esi
// 0078ab0f  5d                   pop ebp
// 0078ab10  5b                   pop ebx
// 0078ab11  c3                   ret 
// 0078ab12  8bc7                 mov eax, edi
// 0078ab14  5f                   pop edi
// 0078ab15  5e                   pop esi
// 0078ab16  5d                   pop ebp
// 0078ab17  5b                   pop ebx
// 0078ab18  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_checkoption)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
