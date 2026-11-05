// from server: 100% by auto
// roc 2010-06 00861c80  unit: CXTPDockingPaneWindowSelect  size: 506 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00861c80
//
// 00861c80  56                   push esi
// 00861c81  8bf1                 mov esi, ecx
// 00861c83  e878f6f9ff           call 0x801300
// 00861c88  8d442408             lea eax, [esp + 8]
// 00861c8c  50                   push eax
// 00861c8d  56                   push esi
// 00861c8e  e80de5f9ff           call 0x8001a0
// 00861c93  8b442410             mov eax, dword ptr [esp + 0x10]
// 00861c97  83c408               add esp, 8
// 00861c9a  83f809               cmp eax, 9
// 00861c9d  0f85a4000000         jne 0x861d47
// 00861ca3  6a10                 push 0x10
// 00861ca5  ff157cbc9e00         call dword ptr [0x9ebc7c]
// 00861cab  6685c0               test ax, ax
// 00861cae  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 00861cb4  7c48                 jl 0x861cfe
// 00861cb6  85c0                 test eax, eax
// 00861cb8  7406                 je 0x861cc0
// 00861cba  8b4014               mov eax, dword ptr [eax + 0x14]
// 00861cbd  40                   inc eax
// 00861cbe  eb02                 jmp 0x861cc2
// 00861cc0  33c0                 xor eax, eax
// 00861cc2  8b9604010000         mov edx, dword ptr [esi + 0x104]
// 00861cc8  3bc2                 cmp eax, edx
// 00861cca  7c1c                 jl 0x861ce8
// 00861ccc  8b8e30010000         mov ecx, dword ptr [esi + 0x130]
// 00861cd2  8bc1                 mov eax, ecx
// 00861cd4  2bc2                 sub eax, edx
// 00861cd6  f7d8                 neg eax
// 00861cd8  1bc0                 sbb eax, eax
// 00861cda  23c1                 and eax, ecx
// 00861cdc  50                   push eax
// 00861cdd  8bce                 mov ecx, esi
// 00861cdf  e86cffffff           call 0x861c50
// 00861ce4  5e                   pop esi
// 00861ce5  c20c00               ret 0xc
// 00861ce8  3b8630010000         cmp eax, dword ptr [esi + 0x130]
// 00861cee  7502                 jne 0x861cf2
// 00861cf0  33c0                 xor eax, eax
// 00861cf2  50                   push eax
// 00861cf3  8bce                 mov ecx, esi
// 00861cf5  e856ffffff           call 0x861c50
// 00861cfa  5e                   pop esi
// 00861cfb  c20c00               ret 0xc
// 00861cfe  85c0                 test eax, eax
// 00861d00  7405                 je 0x861d07
// 00861d02  8b4014               mov eax, dword ptr [eax + 0x14]
// 00861d05  eb06                 jmp 0x861d0d
// 00861d07  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 00861d0d  48                   dec eax
// 00861d0e  85c0                 test eax, eax
// 00861d10  7d17                 jge 0x861d29
// 00861d12  8b8630010000         mov eax, dword ptr [esi + 0x130]
// 00861d18  85c0                 test eax, eax
// 00861d1a  7418                 je 0x861d34
// 00861d1c  48                   dec eax
// 00861d1d  50                   push eax
// 00861d1e  8bce                 mov ecx, esi
// 00861d20  e82bffffff           call 0x861c50
// 00861d25  5e                   pop esi
// 00861d26  c20c00               ret 0xc
// 00861d29  8b8e30010000         mov ecx, dword ptr [esi + 0x130]
// 00861d2f  49                   dec ecx
// 00861d30  3bc1                 cmp eax, ecx
// 00861d32  7507                 jne 0x861d3b
// 00861d34  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 00861d3a  48                   dec eax
// 00861d3b  50                   push eax
// 00861d3c  8bce                 mov ecx, esi
// 00861d3e  e80dffffff           call 0x861c50
// 00861d43  5e                   pop esi
// 00861d44  c20c00               ret 0xc
// 00861d47  57                   push edi
// 00861d48  83f825               cmp eax, 0x25
// 00861d4b  755d                 jne 0x861daa
// 00861d4d  8bbe18010000         mov edi, dword ptr [esi + 0x118]
// 00861d53  83ff01               cmp edi, 1
// 00861d56  0f8e19010000         jle 0x861e75
// 00861d5c  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 00861d62  85c0                 test eax, eax
// 00861d64  0f840b010000         je 0x861e75
// 00861d6a  8b4818               mov ecx, dword ptr [eax + 0x18]
// 00861d6d  8b501c               mov edx, dword ptr [eax + 0x1c]
// 00861d70  8d41ff               lea eax, [ecx - 1]
// 00861d73  85c9                 test ecx, ecx
// 00861d75  7f03                 jg 0x861d7a
// 00861d77  8d47ff               lea eax, [edi - 1]
// 00861d7a  85c0                 test eax, eax
// 00861d7c  7c27                 jl 0x861da5
// 00861d7e  3bc7                 cmp eax, edi
// 00861d80  7d23                 jge 0x861da5
// 00861d82  8b8e14010000         mov ecx, dword ptr [esi + 0x114]
// 00861d88  8d04c1               lea eax, [ecx + eax*8]
// 00861d8b  8b08                 mov ecx, dword ptr [eax]
// 00861d8d  8b4004               mov eax, dword ptr [eax + 4]
// 00861d90  03ca                 add ecx, edx
// 00861d92  3bc8                 cmp ecx, eax
// 00861d94  7f02                 jg 0x861d98
// 00861d96  8bc1                 mov eax, ecx
// 00861d98  50                   push eax
// 00861d99  8bce                 mov ecx, esi
// 00861d9b  e8b0feffff           call 0x861c50
// 00861da0  5f                   pop edi
// 00861da1  5e                   pop esi
// 00861da2  c20c00               ret 0xc
// 00861da5  e8a25ef4ff           call 0x7a7c4c
// 00861daa  83f827               cmp eax, 0x27
// 00861dad  7556                 jne 0x861e05
// 00861daf  8b9618010000         mov edx, dword ptr [esi + 0x118]
// 00861db5  83fa01               cmp edx, 1
// 00861db8  0f8eb7000000         jle 0x861e75
// 00861dbe  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 00861dc4  85c0                 test eax, eax
// 00861dc6  0f84a9000000         je 0x861e75
// 00861dcc  8b4818               mov ecx, dword ptr [eax + 0x18]
// 00861dcf  8b781c               mov edi, dword ptr [eax + 0x1c]
// 00861dd2  4a                   dec edx
// 00861dd3  3bca                 cmp ecx, edx
// 00861dd5  7d05                 jge 0x861ddc
// 00861dd7  8d4101               lea eax, [ecx + 1]
// 00861dda  eb02                 jmp 0x861dde
// 00861ddc  33c0                 xor eax, eax
// 00861dde  50                   push eax
// 00861ddf  8d8e10010000         lea ecx, [esi + 0x110]
// 00861de5  e8c6ebffff           call 0x8609b0
// 00861dea  8b10                 mov edx, dword ptr [eax]
// 00861dec  8b4004               mov eax, dword ptr [eax + 4]
// 00861def  8d0c3a               lea ecx, [edx + edi]
// 00861df2  3bc8                 cmp ecx, eax
// 00861df4  7f02                 jg 0x861df8
// 00861df6  8bc1                 mov eax, ecx
// 00861df8  50                   push eax
// 00861df9  8bce                 mov ecx, esi
// 00861dfb  e850feffff           call 0x861c50
// 00861e00  5f                   pop edi
// 00861e01  5e                   pop esi
// 00861e02  c20c00               ret 0xc
// 00861e05  83f828               cmp eax, 0x28
// 00861e08  752d                 jne 0x861e37
// 00861e0a  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 00861e10  85c0                 test eax, eax
// 00861e12  7406                 je 0x861e1a
// 00861e14  8b4014               mov eax, dword ptr [eax + 0x14]
// 00861e17  40                   inc eax
// 00861e18  eb02                 jmp 0x861e1c
// 00861e1a  33c0                 xor eax, eax
// 00861e1c  33c9                 xor ecx, ecx
// 00861e1e  3b8604010000         cmp eax, dword ptr [esi + 0x104]
// 00861e24  0f9dc1               setge cl
// 00861e27  49                   dec ecx
// 00861e28  23c8                 and ecx, eax
// 00861e2a  51                   push ecx
// 00861e2b  8bce                 mov ecx, esi
// 00861e2d  e81efeffff           call 0x861c50
// 00861e32  5f                   pop edi
// 00861e33  5e                   pop esi
// 00861e34  c20c00               ret 0xc
// 00861e37  83f826               cmp eax, 0x26
// 00861e3a  7526                 jne 0x861e62
// 00861e3c  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 00861e42  85c0                 test eax, eax
// 00861e44  7408                 je 0x861e4e
// 00861e46  8b4014               mov eax, dword ptr [eax + 0x14]
// 00861e49  83e801               sub eax, 1
// 00861e4c  7907                 jns 0x861e55
// 00861e4e  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 00861e54  48                   dec eax
// 00861e55  50                   push eax
// 00861e56  8bce                 mov ecx, esi
// 00861e58  e8f3fdffff           call 0x861c50
// 00861e5d  5f                   pop edi
// 00861e5e  5e                   pop esi
// 00861e5f  c20c00               ret 0xc
// 00861e62  83f810               cmp eax, 0x10
// 00861e65  740e                 je 0x861e75
// 00861e67  8b16                 mov edx, dword ptr [esi]
// 00861e69  8b8294000000         mov eax, dword ptr [edx + 0x94]
// 00861e6f  6a01                 push 1
// 00861e71  8bce                 mov ecx, esi
// 00861e73  ffd0                 call eax
// 00861e75  5f                   pop edi
// 00861e76  5e                   pop esi
// 00861e77  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?OnKeyDown@CXTPDockingPaneWindowSelect@@QAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/DockingPane/XTPDockingPaneKeyboardHook.cpp
