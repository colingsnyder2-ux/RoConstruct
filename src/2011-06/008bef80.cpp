// from server: 100% by auto
// roc 2011-06 008bef80  unit: CXTPDockingPaneWindowSelect  size: 506 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008bef80
//
// 008bef80  56                   push esi
// 008bef81  8bf1                 mov esi, ecx
// 008bef83  e8f8fdf9ff           call 0x85ed80
// 008bef88  8d442408             lea eax, [esp + 8]
// 008bef8c  50                   push eax
// 008bef8d  56                   push esi
// 008bef8e  e88decf9ff           call 0x85dc20
// 008bef93  8b442410             mov eax, dword ptr [esp + 0x10]
// 008bef97  83c408               add esp, 8
// 008bef9a  83f809               cmp eax, 9
// 008bef9d  0f85a4000000         jne 0x8bf047
// 008befa3  6a10                 push 0x10
// 008befa5  ff15601aa400         call dword ptr [0xa41a60]
// 008befab  6685c0               test ax, ax
// 008befae  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 008befb4  7c48                 jl 0x8beffe
// 008befb6  85c0                 test eax, eax
// 008befb8  7406                 je 0x8befc0
// 008befba  8b4014               mov eax, dword ptr [eax + 0x14]
// 008befbd  40                   inc eax
// 008befbe  eb02                 jmp 0x8befc2
// 008befc0  33c0                 xor eax, eax
// 008befc2  8b9604010000         mov edx, dword ptr [esi + 0x104]
// 008befc8  3bc2                 cmp eax, edx
// 008befca  7c1c                 jl 0x8befe8
// 008befcc  8b8e30010000         mov ecx, dword ptr [esi + 0x130]
// 008befd2  8bc1                 mov eax, ecx
// 008befd4  2bc2                 sub eax, edx
// 008befd6  f7d8                 neg eax
// 008befd8  1bc0                 sbb eax, eax
// 008befda  23c1                 and eax, ecx
// 008befdc  50                   push eax
// 008befdd  8bce                 mov ecx, esi
// 008befdf  e86cffffff           call 0x8bef50
// 008befe4  5e                   pop esi
// 008befe5  c20c00               ret 0xc
// 008befe8  3b8630010000         cmp eax, dword ptr [esi + 0x130]
// 008befee  7502                 jne 0x8beff2
// 008beff0  33c0                 xor eax, eax
// 008beff2  50                   push eax
// 008beff3  8bce                 mov ecx, esi
// 008beff5  e856ffffff           call 0x8bef50
// 008beffa  5e                   pop esi
// 008beffb  c20c00               ret 0xc
// 008beffe  85c0                 test eax, eax
// 008bf000  7405                 je 0x8bf007
// 008bf002  8b4014               mov eax, dword ptr [eax + 0x14]
// 008bf005  eb06                 jmp 0x8bf00d
// 008bf007  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 008bf00d  48                   dec eax
// 008bf00e  85c0                 test eax, eax
// 008bf010  7d17                 jge 0x8bf029
// 008bf012  8b8630010000         mov eax, dword ptr [esi + 0x130]
// 008bf018  85c0                 test eax, eax
// 008bf01a  7418                 je 0x8bf034
// 008bf01c  48                   dec eax
// 008bf01d  50                   push eax
// 008bf01e  8bce                 mov ecx, esi
// 008bf020  e82bffffff           call 0x8bef50
// 008bf025  5e                   pop esi
// 008bf026  c20c00               ret 0xc
// 008bf029  8b8e30010000         mov ecx, dword ptr [esi + 0x130]
// 008bf02f  49                   dec ecx
// 008bf030  3bc1                 cmp eax, ecx
// 008bf032  7507                 jne 0x8bf03b
// 008bf034  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 008bf03a  48                   dec eax
// 008bf03b  50                   push eax
// 008bf03c  8bce                 mov ecx, esi
// 008bf03e  e80dffffff           call 0x8bef50
// 008bf043  5e                   pop esi
// 008bf044  c20c00               ret 0xc
// 008bf047  57                   push edi
// 008bf048  83f825               cmp eax, 0x25
// 008bf04b  755d                 jne 0x8bf0aa
// 008bf04d  8bbe18010000         mov edi, dword ptr [esi + 0x118]
// 008bf053  83ff01               cmp edi, 1
// 008bf056  0f8e19010000         jle 0x8bf175
// 008bf05c  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 008bf062  85c0                 test eax, eax
// 008bf064  0f840b010000         je 0x8bf175
// 008bf06a  8b4818               mov ecx, dword ptr [eax + 0x18]
// 008bf06d  8b501c               mov edx, dword ptr [eax + 0x1c]
// 008bf070  8d41ff               lea eax, [ecx - 1]
// 008bf073  85c9                 test ecx, ecx
// 008bf075  7f03                 jg 0x8bf07a
// 008bf077  8d47ff               lea eax, [edi - 1]
// 008bf07a  85c0                 test eax, eax
// 008bf07c  7c27                 jl 0x8bf0a5
// 008bf07e  3bc7                 cmp eax, edi
// 008bf080  7d23                 jge 0x8bf0a5
// 008bf082  8b8e14010000         mov ecx, dword ptr [esi + 0x114]
// 008bf088  8d04c1               lea eax, [ecx + eax*8]
// 008bf08b  8b08                 mov ecx, dword ptr [eax]
// 008bf08d  8b4004               mov eax, dword ptr [eax + 4]
// 008bf090  03ca                 add ecx, edx
// 008bf092  3bc8                 cmp ecx, eax
// 008bf094  7f02                 jg 0x8bf098
// 008bf096  8bc1                 mov eax, ecx
// 008bf098  50                   push eax
// 008bf099  8bce                 mov ecx, esi
// 008bf09b  e8b0feffff           call 0x8bef50
// 008bf0a0  5f                   pop edi
// 008bf0a1  5e                   pop esi
// 008bf0a2  c20c00               ret 0xc
// 008bf0a5  e860b2f4ff           call 0x80a30a
// 008bf0aa  83f827               cmp eax, 0x27
// 008bf0ad  7556                 jne 0x8bf105
// 008bf0af  8b9618010000         mov edx, dword ptr [esi + 0x118]
// 008bf0b5  83fa01               cmp edx, 1
// 008bf0b8  0f8eb7000000         jle 0x8bf175
// 008bf0be  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 008bf0c4  85c0                 test eax, eax
// 008bf0c6  0f84a9000000         je 0x8bf175
// 008bf0cc  8b4818               mov ecx, dword ptr [eax + 0x18]
// 008bf0cf  8b781c               mov edi, dword ptr [eax + 0x1c]
// 008bf0d2  4a                   dec edx
// 008bf0d3  3bca                 cmp ecx, edx
// 008bf0d5  7d05                 jge 0x8bf0dc
// 008bf0d7  8d4101               lea eax, [ecx + 1]
// 008bf0da  eb02                 jmp 0x8bf0de
// 008bf0dc  33c0                 xor eax, eax
// 008bf0de  50                   push eax
// 008bf0df  8d8e10010000         lea ecx, [esi + 0x110]
// 008bf0e5  e8c6ebffff           call 0x8bdcb0
// 008bf0ea  8b10                 mov edx, dword ptr [eax]
// 008bf0ec  8b4004               mov eax, dword ptr [eax + 4]
// 008bf0ef  8d0c3a               lea ecx, [edx + edi]
// 008bf0f2  3bc8                 cmp ecx, eax
// 008bf0f4  7f02                 jg 0x8bf0f8
// 008bf0f6  8bc1                 mov eax, ecx
// 008bf0f8  50                   push eax
// 008bf0f9  8bce                 mov ecx, esi
// 008bf0fb  e850feffff           call 0x8bef50
// 008bf100  5f                   pop edi
// 008bf101  5e                   pop esi
// 008bf102  c20c00               ret 0xc
// 008bf105  83f828               cmp eax, 0x28
// 008bf108  752d                 jne 0x8bf137
// 008bf10a  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 008bf110  85c0                 test eax, eax
// 008bf112  7406                 je 0x8bf11a
// 008bf114  8b4014               mov eax, dword ptr [eax + 0x14]
// 008bf117  40                   inc eax
// 008bf118  eb02                 jmp 0x8bf11c
// 008bf11a  33c0                 xor eax, eax
// 008bf11c  33c9                 xor ecx, ecx
// 008bf11e  3b8604010000         cmp eax, dword ptr [esi + 0x104]
// 008bf124  0f9dc1               setge cl
// 008bf127  49                   dec ecx
// 008bf128  23c8                 and ecx, eax
// 008bf12a  51                   push ecx
// 008bf12b  8bce                 mov ecx, esi
// 008bf12d  e81efeffff           call 0x8bef50
// 008bf132  5f                   pop edi
// 008bf133  5e                   pop esi
// 008bf134  c20c00               ret 0xc
// 008bf137  83f826               cmp eax, 0x26
// 008bf13a  7526                 jne 0x8bf162
// 008bf13c  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 008bf142  85c0                 test eax, eax
// 008bf144  7408                 je 0x8bf14e
// 008bf146  8b4014               mov eax, dword ptr [eax + 0x14]
// 008bf149  83e801               sub eax, 1
// 008bf14c  7907                 jns 0x8bf155
// 008bf14e  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 008bf154  48                   dec eax
// 008bf155  50                   push eax
// 008bf156  8bce                 mov ecx, esi
// 008bf158  e8f3fdffff           call 0x8bef50
// 008bf15d  5f                   pop edi
// 008bf15e  5e                   pop esi
// 008bf15f  c20c00               ret 0xc
// 008bf162  83f810               cmp eax, 0x10
// 008bf165  740e                 je 0x8bf175
// 008bf167  8b16                 mov edx, dword ptr [esi]
// 008bf169  8b8294000000         mov eax, dword ptr [edx + 0x94]
// 008bf16f  6a01                 push 1
// 008bf171  8bce                 mov ecx, esi
// 008bf173  ffd0                 call eax
// 008bf175  5f                   pop edi
// 008bf176  5e                   pop esi
// 008bf177  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?OnKeyDown@CXTPDockingPaneWindowSelect@@QAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/DockingPane/XTPDockingPaneKeyboardHook.cpp
