// roc 2009-12 005675d0  unit: RakPeer  size: 219 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005675d0
//
// 005675d0  53                   push ebx
// 005675d1  56                   push esi
// 005675d2  8bf1                 mov esi, ecx
// 005675d4  8b4608               mov eax, dword ptr [esi + 8]
// 005675d7  57                   push edi
// 005675d8  394604               cmp dword ptr [esi + 4], eax
// 005675db  7571                 jne 0x56764e
// 005675dd  85c0                 test eax, eax
// 005675df  7509                 jne 0x5675ea
// 005675e1  c7460810000000       mov dword ptr [esi + 8], 0x10
// 005675e8  eb05                 jmp 0x5675ef
// 005675ea  03c0                 add eax, eax
// 005675ec  894608               mov dword ptr [esi + 8], eax
// 005675ef  8b4608               mov eax, dword ptr [esi + 8]
// 005675f2  33c9                 xor ecx, ecx
// 005675f4  ba0c000000           mov edx, 0xc
// 005675f9  f7e2                 mul edx
// 005675fb  0f90c1               seto cl
// 005675fe  f7d9                 neg ecx
// 00567600  0bc8                 or ecx, eax
// 00567602  51                   push ecx
// 00567603  e83ac52800           call 0x7f3b42
// 00567608  33d2                 xor edx, edx
// 0056760a  83c404               add esp, 4
// 0056760d  8bd8                 mov ebx, eax
// 0056760f  395604               cmp dword ptr [esi + 4], edx
// 00567612  762d                 jbe 0x567641
// 00567614  bff8ffffff           mov edi, 0xfffffff8
// 00567619  8d4b08               lea ecx, [ebx + 8]
// 0056761c  2bfb                 sub edi, ebx
// 0056761e  55                   push ebp
// 0056761f  90                   nop 
// 00567620  8d040f               lea eax, [edi + ecx]
// 00567623  0306                 add eax, dword ptr [esi]
// 00567625  42                   inc edx
// 00567626  8b28                 mov ebp, dword ptr [eax]
// 00567628  8969f8               mov dword ptr [ecx - 8], ebp
// 0056762b  668b6804             mov bp, word ptr [eax + 4]
// 0056762f  668969fc             mov word ptr [ecx - 4], bp
// 00567633  8b4008               mov eax, dword ptr [eax + 8]
// 00567636  8901                 mov dword ptr [ecx], eax
// 00567638  83c10c               add ecx, 0xc
// 0056763b  3b5604               cmp edx, dword ptr [esi + 4]
// 0056763e  72e0                 jb 0x567620
// 00567640  5d                   pop ebp
// 00567641  8b0e                 mov ecx, dword ptr [esi]
// 00567643  51                   push ecx
// 00567644  e8bdc42800           call 0x7f3b06
// 00567649  83c404               add esp, 4
// 0056764c  891e                 mov dword ptr [esi], ebx
// 0056764e  8b4604               mov eax, dword ptr [esi + 4]
// 00567651  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00567655  3bc7                 cmp eax, edi
// 00567657  742b                 je 0x567684
// 00567659  8d0c40               lea ecx, [eax + eax*2]
// 0056765c  03c9                 add ecx, ecx
// 0056765e  03c9                 add ecx, ecx
// 00567660  2bc7                 sub eax, edi
// 00567662  8bd0                 mov edx, eax
// 00567664  8b06                 mov eax, dword ptr [esi]
// 00567666  8b5c08f4             mov ebx, dword ptr [eax + ecx - 0xc]
// 0056766a  03c1                 add eax, ecx
// 0056766c  8918                 mov dword ptr [eax], ebx
// 0056766e  668b58f8             mov bx, word ptr [eax - 8]
// 00567672  66895804             mov word ptr [eax + 4], bx
// 00567676  8b58fc               mov ebx, dword ptr [eax - 4]
// 00567679  83e90c               sub ecx, 0xc
// 0056767c  83ea01               sub edx, 1
// 0056767f  895808               mov dword ptr [eax + 8], ebx
// 00567682  75e0                 jne 0x567664
// 00567684  8b16                 mov edx, dword ptr [esi]
// 00567686  8d0c7f               lea ecx, [edi + edi*2]
// 00567689  8d048a               lea eax, [edx + ecx*4]
// 0056768c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00567690  8908                 mov dword ptr [eax], ecx
// 00567692  668b542414           mov dx, word ptr [esp + 0x14]
// 00567697  66895004             mov word ptr [eax + 4], dx
// 0056769b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0056769f  5f                   pop edi
// 005676a0  894808               mov dword ptr [eax + 8], ecx
// 005676a3  ff4604               inc dword ptr [esi + 4]
// 005676a6  5e                   pop esi
// 005676a7  5b                   pop ebx
// 005676a8  c21000               ret 0x10
// library openrbx-raknet/RakPeer.cpp (function ?Insert@?$List@USystemAddressAndIndex@@@DataStructures@@QAEXUSystemAddressAndIndex@@I@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
