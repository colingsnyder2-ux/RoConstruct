// from server: 100% by auto
// roc 2011-06 0077dc20  unit: seg_00770000  size: 334 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0077dc20
//
// 0077dc20  51                   push ecx
// 0077dc21  53                   push ebx
// 0077dc22  55                   push ebp
// 0077dc23  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0077dc27  57                   push edi
// 0077dc28  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0077dc2c  33db                 xor ebx, ebx
// 0077dc2e  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0077dc36  3bfb                 cmp edi, ebx
// 0077dc38  7543                 jne 0x77dc7d
// 0077dc3a  b8cabea500           mov eax, 0xa5beca
// 0077dc3f  894608               mov dword ptr [esi + 8], eax
// 0077dc42  894604               mov dword ptr [esi + 4], eax
// 0077dc45  83c8ff               or eax, 0xffffffff
// 0077dc48  6a3c                 push 0x3c
// 0077dc4a  894614               mov dword ptr [esi + 0x14], eax
// 0077dc4d  89461c               mov dword ptr [esi + 0x1c], eax
// 0077dc50  894620               mov dword ptr [esi + 0x20], eax
// 0077dc53  8d4624               lea eax, [esi + 0x24]
// 0077dc56  681877ab00           push 0xab7718
// 0077dc5b  50                   push eax
// 0077dc5c  c7460c1077ab00       mov dword ptr [esi + 0xc], 0xab7710
// 0077dc63  c746101877ab00       mov dword ptr [esi + 0x10], 0xab7718
// 0077dc6a  e8d1f1ffff           call 0x77ce40
// 0077dc6f  83c40c               add esp, 0xc
// 0077dc72  5f                   pop edi
// 0077dc73  5d                   pop ebp
// 0077dc74  895e18               mov dword ptr [esi + 0x18], ebx
// 0077dc77  8d4301               lea eax, [ebx + 1]
// 0077dc7a  5b                   pop ebx
// 0077dc7b  59                   pop ecx
// 0077dc7c  c3                   ret 
// 0077dc7d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0077dc81  8a01                 mov al, byte ptr [ecx]
// 0077dc83  3ac3                 cmp al, bl
// 0077dc85  0f8496000000         je 0x77dd21
// 0077dc8b  eb03                 jmp 0x77dc90
// 0077dc8d  8d4900               lea ecx, [ecx]
// 0077dc90  0fbec0               movsx eax, al
// 0077dc93  83c0b4               add eax, -0x4c
// 0077dc96  83f829               cmp eax, 0x29
// 0077dc99  776f                 ja 0x77dd0a
// 0077dc9b  0fb69044dd7700       movzx edx, byte ptr [eax + 0x77dd44]
// 0077dca2  ff24952cdd7700       jmp dword ptr [edx*4 + 0x77dd2c]
// 0077dca9  8bcf                 mov ecx, edi
// 0077dcab  8bc6                 mov eax, esi
// 0077dcad  e81ef5ffff           call 0x77d1d0
// 0077dcb2  eb5a                 jmp 0x77dd0e
// 0077dcb4  3beb                 cmp ebp, ebx
// 0077dcb6  7410                 je 0x77dcc8
// 0077dcb8  8b542414             mov edx, dword ptr [esp + 0x14]
// 0077dcbc  8bc5                 mov eax, ebp
// 0077dcbe  e8cdf2ffff           call 0x77cf90
// 0077dcc3  894614               mov dword ptr [esi + 0x14], eax
// 0077dcc6  eb46                 jmp 0x77dd0e
// 0077dcc8  83c8ff               or eax, 0xffffffff
// 0077dccb  894614               mov dword ptr [esi + 0x14], eax
// 0077dcce  eb3e                 jmp 0x77dd0e
// 0077dcd0  0fb64707             movzx eax, byte ptr [edi + 7]
// 0077dcd4  894618               mov dword ptr [esi + 0x18], eax
// 0077dcd7  eb35                 jmp 0x77dd0e
// 0077dcd9  3beb                 cmp ebp, ebx
// 0077dcdb  7418                 je 0x77dcf5
// 0077dcdd  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0077dce1  8d4e04               lea ecx, [esi + 4]
// 0077dce4  51                   push ecx
// 0077dce5  8bcd                 mov ecx, ebp
// 0077dce7  e864fdffff           call 0x77da50
// 0077dcec  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0077dcf0  83c404               add esp, 4
// 0077dcf3  eb02                 jmp 0x77dcf7
// 0077dcf5  33c0                 xor eax, eax
// 0077dcf7  894608               mov dword ptr [esi + 8], eax
// 0077dcfa  3bc3                 cmp eax, ebx
// 0077dcfc  7510                 jne 0x77dd0e
// 0077dcfe  c74608cabea500       mov dword ptr [esi + 8], 0xa5beca
// 0077dd05  895e04               mov dword ptr [esi + 4], ebx
// 0077dd08  eb04                 jmp 0x77dd0e
// 0077dd0a  895c240c             mov dword ptr [esp + 0xc], ebx
// 0077dd0e  8b442418             mov eax, dword ptr [esp + 0x18]
// 0077dd12  40                   inc eax
// 0077dd13  89442418             mov dword ptr [esp + 0x18], eax
// 0077dd17  8a00                 mov al, byte ptr [eax]
// 0077dd19  3ac3                 cmp al, bl
// 0077dd1b  0f856fffffff         jne 0x77dc90
// 0077dd21  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0077dd25  5f                   pop edi
// 0077dd26  5d                   pop ebp
// 0077dd27  5b                   pop ebx
// 0077dd28  59                   pop ecx
// 0077dd29  c3                   ret 
// 0077dd2a  8bff                 mov edi, edi
// 0077dd2c  0e                   push cs
// 0077dd2d  dd7700               fnsave dword ptr [edi]
// 0077dd30  a9dc7700b4           test eax, 0xb40077dc
// 0077dd35  dc7700               fdiv qword ptr [edi]
// 0077dd38  d9dc                 fstpnce st(4), st(0)
// 0077dd3a  7700                 ja 0x77dd3c
// 0077dd3c  d0dc                 rcr ah, 1
// 0077dd3e  7700                 ja 0x77dd40
// 0077dd40  0add                 or bl, ch
// 0077dd42  7700                 ja 0x77dd44
// 0077dd44  000505050505         add byte ptr [0x5050505], al
// 0077dd4a  0501050505           add eax, 0x5050501
// 0077dd4f  0505050505           add eax, 0x5050505
// 0077dd54  0505050505           add eax, 0x5050505
// 0077dd59  0505050505           add eax, 0x5050505
// 0077dd5e  000505050505         add byte ptr [0x5050505], al
// 0077dd64  020503050505         add al, byte ptr [0x5050503]
// library lua-5.1/ldebug.c (function _auxgetinfo)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
