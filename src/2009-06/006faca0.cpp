// from server: 100% by auto
// roc 2009-06 006faca0  unit: RBX::GroupDragTool  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006faca0
//
// 006faca0  56                   push esi
// 006faca1  57                   push edi
// 006faca2  8bf8                 mov edi, eax
// 006faca4  8bf1                 mov esi, ecx
// 006faca6  57                   push edi
// 006faca7  56                   push esi
// 006faca8  e8a3f7ffff           call 0x6fa450
// 006facad  8b07                 mov eax, dword ptr [edi]
// 006facaf  48                   dec eax
// 006facb0  83c408               add esp, 8
// 006facb3  83f809               cmp eax, 9
// 006facb6  7723                 ja 0x6facdb
// 006facb8  0fb68024ad6f00       movzx eax, byte ptr [eax + 0x6fad24]
// 006facbf  ff248514ad6f00       jmp dword ptr [eax*4 + 0x6fad14]
// 006facc6  83c8ff               or eax, 0xffffffff
// 006facc9  eb1c                 jmp 0x6face7
// 006faccb  56                   push esi
// 006faccc  e88ff6ffff           call 0x6fa360
// 006facd1  83c404               add esp, 4
// 006facd4  eb11                 jmp 0x6face7
// 006facd6  8b4708               mov eax, dword ptr [edi + 8]
// 006facd9  eb0c                 jmp 0x6face7
// 006facdb  53                   push ebx
// 006facdc  bb01000000           mov ebx, 1
// 006face1  e89afeffff           call 0x6fab80
// 006face6  5b                   pop ebx
// 006face7  50                   push eax
// 006face8  8d4f10               lea ecx, [edi + 0x10]
// 006faceb  51                   push ecx
// 006facec  56                   push esi
// 006faced  e8beefffff           call 0x6f9cb0
// 006facf2  8b4714               mov eax, dword ptr [edi + 0x14]
// 006facf5  8b5618               mov edx, dword ptr [esi + 0x18]
// 006facf8  50                   push eax
// 006facf9  8d4620               lea eax, [esi + 0x20]
// 006facfc  50                   push eax
// 006facfd  56                   push esi
// 006facfe  89561c               mov dword ptr [esi + 0x1c], edx
// 006fad01  e8aaefffff           call 0x6f9cb0
// 006fad06  83c418               add esp, 0x18
// 006fad09  c74714ffffffff       mov dword ptr [edi + 0x14], 0xffffffff
// 006fad10  5f                   pop edi
// 006fad11  5e                   pop esi
// 006fad12  c3                   ret 
// 006fad13  90                   nop 
// library lua-5.1/lcode.c (function _luaK_goiffalse)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
