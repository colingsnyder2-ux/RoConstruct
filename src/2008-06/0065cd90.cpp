// from server: 100% by auto
// roc 2008-06 0065cd90  unit: RBX::BallBallContact  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065cd90
//
// 0065cd90  8b442408             mov eax, dword ptr [esp + 8]
// 0065cd94  8b4808               mov ecx, dword ptr [eax + 8]
// 0065cd97  53                   push ebx
// 0065cd98  55                   push ebp
// 0065cd99  56                   push esi
// 0065cd9a  57                   push edi
// 0065cd9b  83f907               cmp ecx, 7
// 0065cd9e  0f8790000000         ja 0x65ce34
// 0065cda4  ff248d48ce6500       jmp dword ptr [ecx*4 + 0x65ce48]
// 0065cdab  5f                   pop edi
// 0065cdac  5e                   pop esi
// 0065cdad  5d                   pop ebp
// 0065cdae  b801000000           mov eax, 1
// 0065cdb3  5b                   pop ebx
// 0065cdb4  c3                   ret 
// 0065cdb5  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0065cdb9  dd01                 fld qword ptr [ecx]
// 0065cdbb  dc18                 fcomp qword ptr [eax]
// 0065cdbd  dfe0                 fnstsw ax
// 0065cdbf  f6c444               test ah, 0x44
// 0065cdc2  7a3a                 jp 0x65cdfe
// 0065cdc4  5f                   pop edi
// 0065cdc5  5e                   pop esi
// 0065cdc6  5d                   pop ebp
// 0065cdc7  b801000000           mov eax, 1
// 0065cdcc  5b                   pop ebx
// 0065cdcd  c3                   ret 
// 0065cdce  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0065cdd2  8b0a                 mov ecx, dword ptr [edx]
// 0065cdd4  eb06                 jmp 0x65cddc
// 0065cdd6  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0065cdda  8b09                 mov ecx, dword ptr [ecx]
// 0065cddc  8b00                 mov eax, dword ptr [eax]
// 0065cdde  3bc1                 cmp eax, ecx
// 0065cde0  74c9                 je 0x65cdab
// 0065cde2  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0065cde6  8b5908               mov ebx, dword ptr [ecx + 8]
// 0065cde9  8b7808               mov edi, dword ptr [eax + 8]
// 0065cdec  55                   push ebp
// 0065cded  be04000000           mov esi, 4
// 0065cdf2  e8f9fcffff           call 0x65caf0
// 0065cdf7  83c404               add esp, 4
// 0065cdfa  85c0                 test eax, eax
// 0065cdfc  7507                 jne 0x65ce05
// 0065cdfe  5f                   pop edi
// 0065cdff  5e                   pop esi
// 0065ce00  5d                   pop ebp
// 0065ce01  33c0                 xor eax, eax
// 0065ce03  5b                   pop ebx
// 0065ce04  c3                   ret 
// 0065ce05  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0065ce09  8b542418             mov edx, dword ptr [esp + 0x18]
// 0065ce0d  50                   push eax
// 0065ce0e  8b4508               mov eax, dword ptr [ebp + 8]
// 0065ce11  55                   push ebp
// 0065ce12  e899f9ffff           call 0x65c7b0
// 0065ce17  8b6d08               mov ebp, dword ptr [ebp + 8]
// 0065ce1a  8b4508               mov eax, dword ptr [ebp + 8]
// 0065ce1d  83c408               add esp, 8
// 0065ce20  85c0                 test eax, eax
// 0065ce22  74da                 je 0x65cdfe
// 0065ce24  83f801               cmp eax, 1
// 0065ce27  7582                 jne 0x65cdab
// 0065ce29  837d0000             cmp dword ptr [ebp], 0
// 0065ce2d  74cf                 je 0x65cdfe
// 0065ce2f  5f                   pop edi
// 0065ce30  5e                   pop esi
// 0065ce31  5d                   pop ebp
// 0065ce32  5b                   pop ebx
// 0065ce33  c3                   ret 
// 0065ce34  8b10                 mov edx, dword ptr [eax]
// 0065ce36  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0065ce3a  5f                   pop edi
// 0065ce3b  33c0                 xor eax, eax
// 0065ce3d  3b11                 cmp edx, dword ptr [ecx]
// 0065ce3f  5e                   pop esi
// 0065ce40  5d                   pop ebp
// 0065ce41  0f94c0               sete al
// 0065ce44  5b                   pop ebx
// 0065ce45  c3                   ret 
// 0065ce46  8bff                 mov edi, edi
// 0065ce48  ab                   stosd dword ptr es:[edi], eax
// 0065ce49  cd65                 int 0x65
// 0065ce4b  0034ce               add byte ptr [esi + ecx*8], dh
// 0065ce4e  650034ce             add byte ptr gs:[esi + ecx*8], dh
// 0065ce52  6500b5cd650034       add byte ptr gs:[ebp + 0x340065cd], dh
// 0065ce59  ce                   into 
// 0065ce5a  6500d6               add dh, dl
// 0065ce5d  cd65                 int 0x65
// 0065ce5f  0034ce               add byte ptr [esi + ecx*8], dh
// 0065ce62  6500ce               add dh, cl
// 0065ce65  cd65                 int 0x65
// library lua-5.1/lvm.c (function _luaV_equalval)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lvm.c
