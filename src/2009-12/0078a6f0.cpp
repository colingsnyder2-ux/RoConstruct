// from server: 100% by auto
// roc 2009-12 0078a6f0  unit: RBX::UniversalTool  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a6f0
//
// 0078a6f0  56                   push esi
// 0078a6f1  8b742408             mov esi, dword ptr [esp + 8]
// 0078a6f5  57                   push edi
// 0078a6f6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0078a6fa  57                   push edi
// 0078a6fb  56                   push esi
// 0078a6fc  e88fe2ffff           call 0x788990
// 0078a701  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0078a705  83c408               add esp, 8
// 0078a708  3bc1                 cmp eax, ecx
// 0078a70a  7431                 je 0x78a73d
// 0078a70c  53                   push ebx
// 0078a70d  51                   push ecx
// 0078a70e  56                   push esi
// 0078a70f  e89ce2ffff           call 0x7889b0
// 0078a714  57                   push edi
// 0078a715  56                   push esi
// 0078a716  8bd8                 mov ebx, eax
// 0078a718  e873e2ffff           call 0x788990
// 0078a71d  50                   push eax
// 0078a71e  56                   push esi
// 0078a71f  e88ce2ffff           call 0x7889b0
// 0078a724  50                   push eax
// 0078a725  53                   push ebx
// 0078a726  68a89d9e00           push 0x9e9da8
// 0078a72b  56                   push esi
// 0078a72c  e84fe7ffff           call 0x788e80
// 0078a731  50                   push eax
// 0078a732  57                   push edi
// 0078a733  56                   push esi
// 0078a734  e847feffff           call 0x78a580
// 0078a739  83c434               add esp, 0x34
// 0078a73c  5b                   pop ebx
// 0078a73d  5f                   pop edi
// 0078a73e  5e                   pop esi
// 0078a73f  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_checktype)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
