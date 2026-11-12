// from server: 100% by auto
// roc 2010-06 00515f20  unit: RakPeer  size: 219 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00515f20
//
// 00515f20  53                   push ebx
// 00515f21  56                   push esi
// 00515f22  8bf1                 mov esi, ecx
// 00515f24  8b4608               mov eax, dword ptr [esi + 8]
// 00515f27  57                   push edi
// 00515f28  394604               cmp dword ptr [esi + 4], eax
// 00515f2b  7571                 jne 0x515f9e
// 00515f2d  85c0                 test eax, eax
// 00515f2f  7509                 jne 0x515f3a
// 00515f31  c7460810000000       mov dword ptr [esi + 8], 0x10
// 00515f38  eb05                 jmp 0x515f3f
// 00515f3a  03c0                 add eax, eax
// 00515f3c  894608               mov dword ptr [esi + 8], eax
// 00515f3f  8b4608               mov eax, dword ptr [esi + 8]
// 00515f42  33c9                 xor ecx, ecx
// 00515f44  ba0c000000           mov edx, 0xc
// 00515f49  f7e2                 mul edx
// 00515f4b  0f90c1               seto cl
// 00515f4e  f7d9                 neg ecx
// 00515f50  0bc8                 or ecx, eax
// 00515f52  51                   push ecx
// 00515f53  e82a1d2900           call 0x7a7c82
// 00515f58  33d2                 xor edx, edx
// 00515f5a  83c404               add esp, 4
// 00515f5d  8bd8                 mov ebx, eax
// 00515f5f  395604               cmp dword ptr [esi + 4], edx
// 00515f62  762d                 jbe 0x515f91
// 00515f64  bff8ffffff           mov edi, 0xfffffff8
// 00515f69  8d4b08               lea ecx, [ebx + 8]
// 00515f6c  2bfb                 sub edi, ebx
// 00515f6e  55                   push ebp
// 00515f6f  90                   nop 
// 00515f70  8d040f               lea eax, [edi + ecx]
// 00515f73  0306                 add eax, dword ptr [esi]
// 00515f75  42                   inc edx
// 00515f76  8b28                 mov ebp, dword ptr [eax]
// 00515f78  8969f8               mov dword ptr [ecx - 8], ebp
// 00515f7b  668b6804             mov bp, word ptr [eax + 4]
// 00515f7f  668969fc             mov word ptr [ecx - 4], bp
// 00515f83  8b4008               mov eax, dword ptr [eax + 8]
// 00515f86  8901                 mov dword ptr [ecx], eax
// 00515f88  83c10c               add ecx, 0xc
// 00515f8b  3b5604               cmp edx, dword ptr [esi + 4]
// 00515f8e  72e0                 jb 0x515f70
// 00515f90  5d                   pop ebp
// 00515f91  8b0e                 mov ecx, dword ptr [esi]
// 00515f93  51                   push ecx
// 00515f94  e8ad1c2900           call 0x7a7c46
// 00515f99  83c404               add esp, 4
// 00515f9c  891e                 mov dword ptr [esi], ebx
// 00515f9e  8b4604               mov eax, dword ptr [esi + 4]
// 00515fa1  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00515fa5  3bc7                 cmp eax, edi
// 00515fa7  742b                 je 0x515fd4
// 00515fa9  8d0c40               lea ecx, [eax + eax*2]
// 00515fac  03c9                 add ecx, ecx
// 00515fae  03c9                 add ecx, ecx
// 00515fb0  2bc7                 sub eax, edi
// 00515fb2  8bd0                 mov edx, eax
// 00515fb4  8b06                 mov eax, dword ptr [esi]
// 00515fb6  8b5c08f4             mov ebx, dword ptr [eax + ecx - 0xc]
// 00515fba  03c1                 add eax, ecx
// 00515fbc  8918                 mov dword ptr [eax], ebx
// 00515fbe  668b58f8             mov bx, word ptr [eax - 8]
// 00515fc2  66895804             mov word ptr [eax + 4], bx
// 00515fc6  8b58fc               mov ebx, dword ptr [eax - 4]
// 00515fc9  83e90c               sub ecx, 0xc
// 00515fcc  83ea01               sub edx, 1
// 00515fcf  895808               mov dword ptr [eax + 8], ebx
// 00515fd2  75e0                 jne 0x515fb4
// 00515fd4  8b16                 mov edx, dword ptr [esi]
// 00515fd6  8d0c7f               lea ecx, [edi + edi*2]
// 00515fd9  8d048a               lea eax, [edx + ecx*4]
// 00515fdc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00515fe0  8908                 mov dword ptr [eax], ecx
// 00515fe2  668b542414           mov dx, word ptr [esp + 0x14]
// 00515fe7  66895004             mov word ptr [eax + 4], dx
// 00515feb  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00515fef  5f                   pop edi
// 00515ff0  894808               mov dword ptr [eax + 8], ecx
// 00515ff3  ff4604               inc dword ptr [esi + 4]
// 00515ff6  5e                   pop esi
// 00515ff7  5b                   pop ebx
// 00515ff8  c21000               ret 0x10
// library openrbx-raknet/RakPeer.cpp (function ?Insert@?$List@USystemAddressAndIndex@@@DataStructures@@QAEXUSystemAddressAndIndex@@I@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
