// roc 2009-12 00796fd0  unit: VWaitScriptSlot::?$TGenericSlotWrapper  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00796fd0
//
// 00796fd0  8b442408             mov eax, dword ptr [esp + 8]
// 00796fd4  56                   push esi
// 00796fd5  8b742410             mov esi, dword ptr [esp + 0x10]
// 00796fd9  83c0fe               add eax, -2
// 00796fdc  57                   push edi
// 00796fdd  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00796fe1  83f803               cmp eax, 3
// 00796fe4  7749                 ja 0x79702f
// 00796fe6  ff248538707900       jmp dword ptr [eax*4 + 0x797038]
// 00796fed  6a11                 push 0x11
// 00796fef  6878a99e00           push 0x9ea978
// 00796ff4  57                   push edi
// 00796ff5  e8969b0300           call 0x7d0b90
// 00796ffa  83c40c               add esp, 0xc
// 00796ffd  8906                 mov dword ptr [esi], eax
// 00796fff  c7460804000000       mov dword ptr [esi + 8], 4
// 00797006  83c610               add esi, 0x10
// 00797009  897708               mov dword ptr [edi + 8], esi
// 0079700c  5f                   pop edi
// 0079700d  5e                   pop esi
// 0079700e  c3                   ret 
// 0079700f  6a17                 push 0x17
// 00797011  6860a99e00           push 0x9ea960
// 00797016  ebdc                 jmp 0x796ff4
// 00797018  8b4708               mov eax, dword ptr [edi + 8]
// 0079701b  8b48f0               mov ecx, dword ptr [eax - 0x10]
// 0079701e  83e810               sub eax, 0x10
// 00797021  890e                 mov dword ptr [esi], ecx
// 00797023  8b5004               mov edx, dword ptr [eax + 4]
// 00797026  895604               mov dword ptr [esi + 4], edx
// 00797029  8b4008               mov eax, dword ptr [eax + 8]
// 0079702c  894608               mov dword ptr [esi + 8], eax
// 0079702f  83c610               add esi, 0x10
// 00797032  897708               mov dword ptr [edi + 8], esi
// 00797035  5f                   pop edi
// 00797036  5e                   pop esi
// 00797037  c3                   ret 
// 00797038  187079               sbb byte ptr [eax + 0x79], dh
// 0079703b  0018                 add byte ptr [eax], bl
// 0079703d  7079                 jo 0x7970b8
// 0079703f  00ed                 add ch, ch
// 00797041  6f                   outsd dx, dword ptr [esi]
// 00797042  7900                 jns 0x797044
// library lua-5.1/ldo.c (function _luaD_seterrorobj)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldo.c
