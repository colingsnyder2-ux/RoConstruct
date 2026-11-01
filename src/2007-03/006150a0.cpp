// from server: 100% by auto
// roc 2007-03 006150a0  unit: seg_00610000  size: 275 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006150a0
//
// 006150a0  83ec08               sub esp, 8
// 006150a3  53                   push ebx
// 006150a4  55                   push ebp
// 006150a5  56                   push esi
// 006150a6  57                   push edi
// 006150a7  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 006150ab  8bd8                 mov ebx, eax
// 006150ad  8bf1                 mov esi, ecx
// 006150af  e87cfeffff           call 0x614f30
// 006150b4  833b0a               cmp dword ptr [ebx], 0xa
// 006150b7  7511                 jne 0x6150ca
// 006150b9  8b4308               mov eax, dword ptr [ebx + 8]
// 006150bc  50                   push eax
// 006150bd  8d4b10               lea ecx, [ebx + 0x10]
// 006150c0  51                   push ecx
// 006150c1  56                   push esi
// 006150c2  e889f5ffff           call 0x614650
// 006150c7  83c40c               add esp, 0xc
// 006150ca  8b5310               mov edx, dword ptr [ebx + 0x10]
// 006150cd  8b6b14               mov ebp, dword ptr [ebx + 0x14]
// 006150d0  3bd5                 cmp edx, ebp
// 006150d2  0f84bd000000         je 0x615195
// 006150d8  83cfff               or edi, 0xffffffff
// 006150db  8bc6                 mov eax, esi
// 006150dd  897c2414             mov dword ptr [esp + 0x14], edi
// 006150e1  e83af3ffff           call 0x614420
// 006150e6  85c0                 test eax, eax
// 006150e8  750d                 jne 0x6150f7
// 006150ea  8bd5                 mov edx, ebp
// 006150ec  8bc6                 mov eax, esi
// 006150ee  e82df3ffff           call 0x614420
// 006150f3  85c0                 test eax, eax
// 006150f5  7475                 je 0x61516c
// 006150f7  833b0a               cmp dword ptr [ebx], 0xa
// 006150fa  750a                 jne 0x615106
// 006150fc  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00615104  eb0d                 jmp 0x615113
// 00615106  56                   push esi
// 00615107  e834fcffff           call 0x614d40
// 0061510c  83c404               add esp, 4
// 0061510f  89442410             mov dword ptr [esp + 0x10], eax
// 00615113  8b5618               mov edx, dword ptr [esi + 0x18]
// 00615116  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0061511a  8b460c               mov eax, dword ptr [esi + 0xc]
// 0061511d  89561c               mov dword ptr [esi + 0x1c], edx
// 00615120  8b4808               mov ecx, dword ptr [eax + 8]
// 00615123  c1e506               shl ebp, 6
// 00615126  8bd5                 mov edx, ebp
// 00615128  51                   push ecx
// 00615129  81ca02400000         or edx, 0x4002
// 0061512f  52                   push edx
// 00615130  e8dbf9ffff           call 0x614b10
// 00615135  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00615138  8bf8                 mov edi, eax
// 0061513a  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061513d  89461c               mov dword ptr [esi + 0x1c], eax
// 00615140  8b5108               mov edx, dword ptr [ecx + 8]
// 00615143  52                   push edx
// 00615144  81cd02008000         or ebp, 0x800002
// 0061514a  55                   push ebp
// 0061514b  e8c0f9ffff           call 0x614b10
// 00615150  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00615154  51                   push ecx
// 00615155  8d5620               lea edx, [esi + 0x20]
// 00615158  89442428             mov dword ptr [esp + 0x28], eax
// 0061515c  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061515f  52                   push edx
// 00615160  56                   push esi
// 00615161  89461c               mov dword ptr [esi + 0x1c], eax
// 00615164  e8e7f4ffff           call 0x614650
// 00615169  83c41c               add esp, 0x1c
// 0061516c  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 0061516f  57                   push edi
// 00615170  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00615174  57                   push edi
// 00615175  896e1c               mov dword ptr [esi + 0x1c], ebp
// 00615178  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0061517b  55                   push ebp
// 0061517c  56                   push esi
// 0061517d  e80ef4ffff           call 0x614590
// 00615182  8b442424             mov eax, dword ptr [esp + 0x24]
// 00615186  50                   push eax
// 00615187  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0061518a  57                   push edi
// 0061518b  55                   push ebp
// 0061518c  56                   push esi
// 0061518d  e8fef3ffff           call 0x614590
// 00615192  83c420               add esp, 0x20
// 00615195  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00615199  5f                   pop edi
// 0061519a  5e                   pop esi
// 0061519b  83c8ff               or eax, 0xffffffff
// 0061519e  5d                   pop ebp
// 0061519f  894310               mov dword ptr [ebx + 0x10], eax
// 006151a2  894314               mov dword ptr [ebx + 0x14], eax
// 006151a5  894b08               mov dword ptr [ebx + 8], ecx
// 006151a8  c7030c000000         mov dword ptr [ebx], 0xc
// 006151ae  5b                   pop ebx
// 006151af  83c408               add esp, 8
// 006151b2  c3                   ret 
// library lua-5.1.1/lcode.c (function _exp2reg)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
