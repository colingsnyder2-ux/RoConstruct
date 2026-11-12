// from server: 100% by auto
// roc 2008-06 004c2030  unit: ProfiledRakPeer  size: 196 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c2030
//
// 004c2030  83ec08               sub esp, 8
// 004c2033  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004c2037  53                   push ebx
// 004c2038  57                   push edi
// 004c2039  8bf9                 mov edi, ecx
// 004c203b  50                   push eax
// 004c203c  8d4c240c             lea ecx, [esp + 0xc]
// 004c2040  e8db78feff           call 0x4a9920
// 004c2045  668b4c2418           mov cx, word ptr [esp + 0x18]
// 004c204a  8b442408             mov eax, dword ptr [esp + 8]
// 004c204e  6a01                 push 1
// 004c2050  66894c2410           mov word ptr [esp + 0x10], cx
// 004c2055  8b542410             mov edx, dword ptr [esp + 0x10]
// 004c2059  33db                 xor ebx, ebx
// 004c205b  53                   push ebx
// 004c205c  52                   push edx
// 004c205d  50                   push eax
// 004c205e  8bcf                 mov ecx, edi
// 004c2060  e87bddffff           call 0x4bfde0
// 004c2065  85c0                 test eax, eax
// 004c2067  740a                 je 0x4c2073
// 004c2069  5f                   pop edi
// 004c206a  32c0                 xor al, al
// 004c206c  5b                   pop ebx
// 004c206d  83c408               add esp, 8
// 004c2070  c21400               ret 0x14
// 004c2073  81c7b4020000         add edi, 0x2b4
// 004c2079  56                   push esi
// 004c207a  8bcf                 mov ecx, edi
// 004c207c  e80fa2ffff           call 0x4bc290
// 004c2081  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004c2085  8bf0                 mov esi, eax
// 004c2087  890e                 mov dword ptr [esi], ecx
// 004c2089  668b542410           mov dx, word ptr [esp + 0x10]
// 004c208e  66895604             mov word ptr [esi + 4], dx
// 004c2092  e879780000           call 0x4c9910
// 004c2097  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004c209b  885e0c               mov byte ptr [esi + 0xc], bl
// 004c209e  895e10               mov dword ptr [esi + 0x10], ebx
// 004c20a1  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004c20a5  53                   push ebx
// 004c20a6  894608               mov dword ptr [esi + 8], eax
// 004c20a9  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004c20ad  51                   push ecx
// 004c20ae  8d5616               lea edx, [esi + 0x16]
// 004c20b1  52                   push edx
// 004c20b2  898618010000         mov dword ptr [esi + 0x118], eax
// 004c20b8  c7861c01000001000000 mov dword ptr [esi + 0x11c], 1
// 004c20c2  e819f71d00           call 0x6a17e0
// 004c20c7  889e16010000         mov byte ptr [esi + 0x116], bl
// 004c20cd  8b470c               mov eax, dword ptr [edi + 0xc]
// 004c20d0  83c40c               add esp, 0xc
// 004c20d3  ff4714               inc dword ptr [edi + 0x14]
// 004c20d6  c6802001000001       mov byte ptr [eax + 0x120], 1
// 004c20dd  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 004c20e0  8b9124010000         mov edx, dword ptr [ecx + 0x124]
// 004c20e6  5e                   pop esi
// 004c20e7  89570c               mov dword ptr [edi + 0xc], edx
// 004c20ea  5f                   pop edi
// 004c20eb  b001                 mov al, 1
// 004c20ed  5b                   pop ebx
// 004c20ee  83c408               add esp, 8
// 004c20f1  c21400               ret 0x14
// library openrbx-raknet/RakPeer.cpp (function ?SendConnectionRequest@RakPeer@@IAE_NPBDG0HI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
