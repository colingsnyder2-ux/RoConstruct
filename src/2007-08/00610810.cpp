// from server: 100% by auto
// roc 2007-08 00610810  unit: RBX::Ball  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00610810
//
// 00610810  8b442408             mov eax, dword ptr [esp + 8]
// 00610814  8b4808               mov ecx, dword ptr [eax + 8]
// 00610817  83f907               cmp ecx, 7
// 0061081a  53                   push ebx
// 0061081b  55                   push ebp
// 0061081c  56                   push esi
// 0061081d  57                   push edi
// 0061081e  0f8790000000         ja 0x6108b4
// 00610824  ff248dc8086100       jmp dword ptr [ecx*4 + 0x6108c8]
// 0061082b  5f                   pop edi
// 0061082c  5e                   pop esi
// 0061082d  5d                   pop ebp
// 0061082e  b801000000           mov eax, 1
// 00610833  5b                   pop ebx
// 00610834  c3                   ret 
// 00610835  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00610839  dd01                 fld qword ptr [ecx]
// 0061083b  dc18                 fcomp qword ptr [eax]
// 0061083d  dfe0                 fnstsw ax
// 0061083f  f6c444               test ah, 0x44
// 00610842  7a3a                 jp 0x61087e
// 00610844  5f                   pop edi
// 00610845  5e                   pop esi
// 00610846  5d                   pop ebp
// 00610847  b801000000           mov eax, 1
// 0061084c  5b                   pop ebx
// 0061084d  c3                   ret 
// 0061084e  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00610852  8b0a                 mov ecx, dword ptr [edx]
// 00610854  eb06                 jmp 0x61085c
// 00610856  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0061085a  8b09                 mov ecx, dword ptr [ecx]
// 0061085c  8b00                 mov eax, dword ptr [eax]
// 0061085e  3bc1                 cmp eax, ecx
// 00610860  74c9                 je 0x61082b
// 00610862  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00610866  8b5908               mov ebx, dword ptr [ecx + 8]
// 00610869  8b7808               mov edi, dword ptr [eax + 8]
// 0061086c  55                   push ebp
// 0061086d  be04000000           mov esi, 4
// 00610872  e8f9fcffff           call 0x610570
// 00610877  83c404               add esp, 4
// 0061087a  85c0                 test eax, eax
// 0061087c  7507                 jne 0x610885
// 0061087e  5f                   pop edi
// 0061087f  5e                   pop esi
// 00610880  5d                   pop ebp
// 00610881  33c0                 xor eax, eax
// 00610883  5b                   pop ebx
// 00610884  c3                   ret 
// 00610885  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00610889  8b542418             mov edx, dword ptr [esp + 0x18]
// 0061088d  50                   push eax
// 0061088e  8b4508               mov eax, dword ptr [ebp + 8]
// 00610891  55                   push ebp
// 00610892  e889f9ffff           call 0x610220
// 00610897  8b6d08               mov ebp, dword ptr [ebp + 8]
// 0061089a  8b4508               mov eax, dword ptr [ebp + 8]
// 0061089d  83c408               add esp, 8
// 006108a0  85c0                 test eax, eax
// 006108a2  74da                 je 0x61087e
// 006108a4  83f801               cmp eax, 1
// 006108a7  7582                 jne 0x61082b
// 006108a9  837d0000             cmp dword ptr [ebp], 0
// 006108ad  74cf                 je 0x61087e
// 006108af  5f                   pop edi
// 006108b0  5e                   pop esi
// 006108b1  5d                   pop ebp
// 006108b2  5b                   pop ebx
// 006108b3  c3                   ret 
// 006108b4  8b10                 mov edx, dword ptr [eax]
// 006108b6  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006108ba  5f                   pop edi
// 006108bb  33c0                 xor eax, eax
// 006108bd  3b11                 cmp edx, dword ptr [ecx]
// 006108bf  5e                   pop esi
// 006108c0  5d                   pop ebp
// 006108c1  0f94c0               sete al
// 006108c4  5b                   pop ebx
// 006108c5  c3                   ret 
// 006108c6  8bff                 mov edi, edi
// 006108c8  2b08                 sub ecx, dword ptr [eax]
// 006108ca  61                   popal 
// 006108cb  00b4086100b408       add byte ptr [eax + ecx + 0x8b40061], dh
// 006108d2  61                   popal 
// 006108d3  0035086100b4         add byte ptr [0xb4006108], dh
// 006108d9  086100               or byte ptr [ecx], ah
// 006108dc  56                   push esi
// 006108dd  086100               or byte ptr [ecx], ah
// 006108e0  b408                 mov ah, 8
// 006108e2  61                   popal 
// 006108e3  004e08               add byte ptr [esi + 8], cl
// 006108e6  61                   popal 
// library lua-5.1/lvm.c (function _luaV_equalval)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lvm.c
