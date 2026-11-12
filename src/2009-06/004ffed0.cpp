// from server: 100% by auto
// roc 2009-06 004ffed0  unit: RakPeer  size: 219 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ffed0
//
// 004ffed0  53                   push ebx
// 004ffed1  56                   push esi
// 004ffed2  8bf1                 mov esi, ecx
// 004ffed4  8b4608               mov eax, dword ptr [esi + 8]
// 004ffed7  57                   push edi
// 004ffed8  394604               cmp dword ptr [esi + 4], eax
// 004ffedb  7571                 jne 0x4fff4e
// 004ffedd  85c0                 test eax, eax
// 004ffedf  7509                 jne 0x4ffeea
// 004ffee1  c7460810000000       mov dword ptr [esi + 8], 0x10
// 004ffee8  eb05                 jmp 0x4ffeef
// 004ffeea  03c0                 add eax, eax
// 004ffeec  894608               mov dword ptr [esi + 8], eax
// 004ffeef  8b4608               mov eax, dword ptr [esi + 8]
// 004ffef2  33c9                 xor ecx, ecx
// 004ffef4  ba0c000000           mov edx, 0xc
// 004ffef9  f7e2                 mul edx
// 004ffefb  0f90c1               seto cl
// 004ffefe  f7d9                 neg ecx
// 004fff00  0bc8                 or ecx, eax
// 004fff02  51                   push ecx
// 004fff03  e8128e2100           call 0x718d1a
// 004fff08  33d2                 xor edx, edx
// 004fff0a  83c404               add esp, 4
// 004fff0d  8bd8                 mov ebx, eax
// 004fff0f  395604               cmp dword ptr [esi + 4], edx
// 004fff12  762d                 jbe 0x4fff41
// 004fff14  bff8ffffff           mov edi, 0xfffffff8
// 004fff19  8d4b08               lea ecx, [ebx + 8]
// 004fff1c  2bfb                 sub edi, ebx
// 004fff1e  55                   push ebp
// 004fff1f  90                   nop 
// 004fff20  8d040f               lea eax, [edi + ecx]
// 004fff23  0306                 add eax, dword ptr [esi]
// 004fff25  42                   inc edx
// 004fff26  8b28                 mov ebp, dword ptr [eax]
// 004fff28  8969f8               mov dword ptr [ecx - 8], ebp
// 004fff2b  668b6804             mov bp, word ptr [eax + 4]
// 004fff2f  668969fc             mov word ptr [ecx - 4], bp
// 004fff33  8b4008               mov eax, dword ptr [eax + 8]
// 004fff36  8901                 mov dword ptr [ecx], eax
// 004fff38  83c10c               add ecx, 0xc
// 004fff3b  3b5604               cmp edx, dword ptr [esi + 4]
// 004fff3e  72e0                 jb 0x4fff20
// 004fff40  5d                   pop ebp
// 004fff41  8b0e                 mov ecx, dword ptr [esi]
// 004fff43  51                   push ecx
// 004fff44  e8958d2100           call 0x718cde
// 004fff49  83c404               add esp, 4
// 004fff4c  891e                 mov dword ptr [esi], ebx
// 004fff4e  8b4604               mov eax, dword ptr [esi + 4]
// 004fff51  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004fff55  3bc7                 cmp eax, edi
// 004fff57  742b                 je 0x4fff84
// 004fff59  8d0c40               lea ecx, [eax + eax*2]
// 004fff5c  03c9                 add ecx, ecx
// 004fff5e  03c9                 add ecx, ecx
// 004fff60  2bc7                 sub eax, edi
// 004fff62  8bd0                 mov edx, eax
// 004fff64  8b06                 mov eax, dword ptr [esi]
// 004fff66  8b5c08f4             mov ebx, dword ptr [eax + ecx - 0xc]
// 004fff6a  03c1                 add eax, ecx
// 004fff6c  8918                 mov dword ptr [eax], ebx
// 004fff6e  668b58f8             mov bx, word ptr [eax - 8]
// 004fff72  66895804             mov word ptr [eax + 4], bx
// 004fff76  8b58fc               mov ebx, dword ptr [eax - 4]
// 004fff79  83e90c               sub ecx, 0xc
// 004fff7c  83ea01               sub edx, 1
// 004fff7f  895808               mov dword ptr [eax + 8], ebx
// 004fff82  75e0                 jne 0x4fff64
// 004fff84  8b16                 mov edx, dword ptr [esi]
// 004fff86  8d0c7f               lea ecx, [edi + edi*2]
// 004fff89  8d048a               lea eax, [edx + ecx*4]
// 004fff8c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004fff90  8908                 mov dword ptr [eax], ecx
// 004fff92  668b542414           mov dx, word ptr [esp + 0x14]
// 004fff97  66895004             mov word ptr [eax + 4], dx
// 004fff9b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004fff9f  5f                   pop edi
// 004fffa0  894808               mov dword ptr [eax + 8], ecx
// 004fffa3  ff4604               inc dword ptr [esi + 4]
// 004fffa6  5e                   pop esi
// 004fffa7  5b                   pop ebx
// 004fffa8  c21000               ret 0x10
// library openrbx-raknet/RakPeer.cpp (function ?Insert@?$List@USystemAddressAndIndex@@@DataStructures@@QAEXUSystemAddressAndIndex@@I@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
