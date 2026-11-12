// from server: 100% by auto
// roc 2008-06 004bdae0  unit: ProfiledRakPeer  size: 219 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bdae0
//
// 004bdae0  53                   push ebx
// 004bdae1  56                   push esi
// 004bdae2  8bf1                 mov esi, ecx
// 004bdae4  8b4608               mov eax, dword ptr [esi + 8]
// 004bdae7  57                   push edi
// 004bdae8  394604               cmp dword ptr [esi + 4], eax
// 004bdaeb  7571                 jne 0x4bdb5e
// 004bdaed  85c0                 test eax, eax
// 004bdaef  7509                 jne 0x4bdafa
// 004bdaf1  c7460810000000       mov dword ptr [esi + 8], 0x10
// 004bdaf8  eb05                 jmp 0x4bdaff
// 004bdafa  03c0                 add eax, eax
// 004bdafc  894608               mov dword ptr [esi + 8], eax
// 004bdaff  8b4608               mov eax, dword ptr [esi + 8]
// 004bdb02  33c9                 xor ecx, ecx
// 004bdb04  ba0c000000           mov edx, 0xc
// 004bdb09  f7e2                 mul edx
// 004bdb0b  0f90c1               seto cl
// 004bdb0e  f7d9                 neg ecx
// 004bdb10  0bc8                 or ecx, eax
// 004bdb12  51                   push ecx
// 004bdb13  e8082e1e00           call 0x6a0920
// 004bdb18  33d2                 xor edx, edx
// 004bdb1a  83c404               add esp, 4
// 004bdb1d  8bd8                 mov ebx, eax
// 004bdb1f  395604               cmp dword ptr [esi + 4], edx
// 004bdb22  762d                 jbe 0x4bdb51
// 004bdb24  bff8ffffff           mov edi, 0xfffffff8
// 004bdb29  8d4b08               lea ecx, [ebx + 8]
// 004bdb2c  2bfb                 sub edi, ebx
// 004bdb2e  55                   push ebp
// 004bdb2f  90                   nop 
// 004bdb30  8d040f               lea eax, [edi + ecx]
// 004bdb33  0306                 add eax, dword ptr [esi]
// 004bdb35  42                   inc edx
// 004bdb36  8b28                 mov ebp, dword ptr [eax]
// 004bdb38  8969f8               mov dword ptr [ecx - 8], ebp
// 004bdb3b  668b6804             mov bp, word ptr [eax + 4]
// 004bdb3f  668969fc             mov word ptr [ecx - 4], bp
// 004bdb43  8b4008               mov eax, dword ptr [eax + 8]
// 004bdb46  8901                 mov dword ptr [ecx], eax
// 004bdb48  83c10c               add ecx, 0xc
// 004bdb4b  3b5604               cmp edx, dword ptr [esi + 4]
// 004bdb4e  72e0                 jb 0x4bdb30
// 004bdb50  5d                   pop ebp
// 004bdb51  8b0e                 mov ecx, dword ptr [esi]
// 004bdb53  51                   push ecx
// 004bdb54  e8212b1e00           call 0x6a067a
// 004bdb59  83c404               add esp, 4
// 004bdb5c  891e                 mov dword ptr [esi], ebx
// 004bdb5e  8b4604               mov eax, dword ptr [esi + 4]
// 004bdb61  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004bdb65  3bc7                 cmp eax, edi
// 004bdb67  742b                 je 0x4bdb94
// 004bdb69  8d0c40               lea ecx, [eax + eax*2]
// 004bdb6c  03c9                 add ecx, ecx
// 004bdb6e  03c9                 add ecx, ecx
// 004bdb70  2bc7                 sub eax, edi
// 004bdb72  8bd0                 mov edx, eax
// 004bdb74  8b06                 mov eax, dword ptr [esi]
// 004bdb76  8b5c08f4             mov ebx, dword ptr [eax + ecx - 0xc]
// 004bdb7a  03c1                 add eax, ecx
// 004bdb7c  8918                 mov dword ptr [eax], ebx
// 004bdb7e  668b58f8             mov bx, word ptr [eax - 8]
// 004bdb82  66895804             mov word ptr [eax + 4], bx
// 004bdb86  8b58fc               mov ebx, dword ptr [eax - 4]
// 004bdb89  83e90c               sub ecx, 0xc
// 004bdb8c  83ea01               sub edx, 1
// 004bdb8f  895808               mov dword ptr [eax + 8], ebx
// 004bdb92  75e0                 jne 0x4bdb74
// 004bdb94  8b16                 mov edx, dword ptr [esi]
// 004bdb96  8d0c7f               lea ecx, [edi + edi*2]
// 004bdb99  8d048a               lea eax, [edx + ecx*4]
// 004bdb9c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004bdba0  8908                 mov dword ptr [eax], ecx
// 004bdba2  668b542414           mov dx, word ptr [esp + 0x14]
// 004bdba7  66895004             mov word ptr [eax + 4], dx
// 004bdbab  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004bdbaf  5f                   pop edi
// 004bdbb0  894808               mov dword ptr [eax + 8], ecx
// 004bdbb3  ff4604               inc dword ptr [esi + 4]
// 004bdbb6  5e                   pop esi
// 004bdbb7  5b                   pop ebx
// 004bdbb8  c21000               ret 0x10
// library openrbx-raknet/RakPeer.cpp (function ?Insert@?$List@USystemAddressAndIndex@@@DataStructures@@QAEXUSystemAddressAndIndex@@I@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
