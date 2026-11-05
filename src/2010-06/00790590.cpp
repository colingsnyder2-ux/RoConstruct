// from server: 100% by auto
// roc 2010-06 00790590  unit: RBX::GroupDragTool  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00790590
//
// 00790590  56                   push esi
// 00790591  8b742408             mov esi, dword ptr [esp + 8]
// 00790595  57                   push edi
// 00790596  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0079059a  57                   push edi
// 0079059b  56                   push esi
// 0079059c  e83ff8ffff           call 0x78fde0
// 007905a1  8b07                 mov eax, dword ptr [edi]
// 007905a3  83c0fe               add eax, -2
// 007905a6  83c408               add esp, 8
// 007905a9  83f808               cmp eax, 8
// 007905ac  772c                 ja 0x7905da
// 007905ae  0fb68020067900       movzx eax, byte ptr [eax + 0x790620]
// 007905b5  ff248510067900       jmp dword ptr [eax*4 + 0x790610]
// 007905bc  83c8ff               or eax, 0xffffffff
// 007905bf  eb22                 jmp 0x7905e3
// 007905c1  56                   push esi
// 007905c2  e829f7ffff           call 0x78fcf0
// 007905c7  83c404               add esp, 4
// 007905ca  eb17                 jmp 0x7905e3
// 007905cc  8bc7                 mov eax, edi
// 007905ce  8bce                 mov ecx, esi
// 007905d0  e87bf3ffff           call 0x78f950
// 007905d5  8b4708               mov eax, dword ptr [edi + 8]
// 007905d8  eb09                 jmp 0x7905e3
// 007905da  53                   push ebx
// 007905db  33db                 xor ebx, ebx
// 007905dd  e82effffff           call 0x790510
// 007905e2  5b                   pop ebx
// 007905e3  50                   push eax
// 007905e4  8d4f14               lea ecx, [edi + 0x14]
// 007905e7  51                   push ecx
// 007905e8  56                   push esi
// 007905e9  e842f0ffff           call 0x78f630
// 007905ee  8b4710               mov eax, dword ptr [edi + 0x10]
// 007905f1  8b5618               mov edx, dword ptr [esi + 0x18]
// 007905f4  50                   push eax
// 007905f5  8d4620               lea eax, [esi + 0x20]
// 007905f8  50                   push eax
// 007905f9  56                   push esi
// 007905fa  89561c               mov dword ptr [esi + 0x1c], edx
// 007905fd  e82ef0ffff           call 0x78f630
// 00790602  83c418               add esp, 0x18
// 00790605  c74710ffffffff       mov dword ptr [edi + 0x10], 0xffffffff
// 0079060c  5f                   pop edi
// 0079060d  5e                   pop esi
// 0079060e  c3                   ret 
// 0079060f  90                   nop 
// 00790610  bc057900c1           mov esp, 0xc1007905
// 00790615  057900cc05           add eax, 0x5cc0079
// 0079061a  7900                 jns 0x79061c
// 0079061c  da0579000001         fiadd dword ptr [0x1000079]
// 00790622  0000                 add byte ptr [eax], al
// 00790624  0303                 add eax, dword ptr [ebx]
// 00790626  0303                 add eax, dword ptr [ebx]
// library lua-5.1/lcode.c (function _luaK_goiftrue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
