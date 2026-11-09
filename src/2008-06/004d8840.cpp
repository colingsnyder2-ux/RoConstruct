// from server: 100% by auto
// roc 2008-06 004d8840  unit: G3D::VVector3::?$Table  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d8840
//
// 004d8840  83ec08               sub esp, 8
// 004d8843  53                   push ebx
// 004d8844  55                   push ebp
// 004d8845  8b2d90288000         mov ebp, dword ptr [0x802890]
// 004d884b  56                   push esi
// 004d884c  8bf1                 mov esi, ecx
// 004d884e  8b4618               mov eax, dword ptr [esi + 0x18]
// 004d8851  8b18                 mov ebx, dword ptr [eax]
// 004d8853  8b06                 mov eax, dword ptr [esi]
// 004d8855  57                   push edi
// 004d8856  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004d885a  85ff                 test edi, edi
// 004d885c  7404                 je 0x4d8862
// 004d885e  3bf8                 cmp edi, eax
// 004d8860  7406                 je 0x4d8868
// 004d8862  ffd5                 call ebp
// 004d8864  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004d8868  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004d886c  7562                 jne 0x4d88d0
// 004d886e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004d8872  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004d8875  8b06                 mov eax, dword ptr [esi]
// 004d8877  85c9                 test ecx, ecx
// 004d8879  7404                 je 0x4d887f
// 004d887b  3bc8                 cmp ecx, eax
// 004d887d  7406                 je 0x4d8885
// 004d887f  ffd5                 call ebp
// 004d8881  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004d8885  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004d8889  7545                 jne 0x4d88d0
// 004d888b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004d888e  8b5104               mov edx, dword ptr [ecx + 4]
// 004d8891  52                   push edx
// 004d8892  8bce                 mov ecx, esi
// 004d8894  e847fbffff           call 0x4d83e0
// 004d8899  8b4618               mov eax, dword ptr [esi + 0x18]
// 004d889c  894004               mov dword ptr [eax + 4], eax
// 004d889f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004d88a2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004d88a9  8900                 mov dword ptr [eax], eax
// 004d88ab  8b4618               mov eax, dword ptr [esi + 0x18]
// 004d88ae  894008               mov dword ptr [eax + 8], eax
// 004d88b1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004d88b4  8b16                 mov edx, dword ptr [esi]
// 004d88b6  8b08                 mov ecx, dword ptr [eax]
// 004d88b8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004d88bc  5f                   pop edi
// 004d88bd  5e                   pop esi
// 004d88be  5d                   pop ebp
// 004d88bf  894804               mov dword ptr [eax + 4], ecx
// 004d88c2  8910                 mov dword ptr [eax], edx
// 004d88c4  5b                   pop ebx
// 004d88c5  83c408               add esp, 8
// 004d88c8  c21400               ret 0x14
// 004d88cb  eb03                 jmp 0x4d88d0
// 004d88cd  8d4900               lea ecx, [ecx]
// 004d88d0  85ff                 test edi, edi
// 004d88d2  7406                 je 0x4d88da
// 004d88d4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004d88d8  7406                 je 0x4d88e0
// 004d88da  ffd5                 call ebp
// 004d88dc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004d88e0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004d88e4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004d88e8  741d                 je 0x4d8907
// 004d88ea  8d4c2420             lea ecx, [esp + 0x20]
// 004d88ee  e84de9ffff           call 0x4d7240
// 004d88f3  53                   push ebx
// 004d88f4  57                   push edi
// 004d88f5  8d442418             lea eax, [esp + 0x18]
// 004d88f9  50                   push eax
// 004d88fa  8bce                 mov ecx, esi
// 004d88fc  e89ff5ffff           call 0x4d7ea0
// 004d8901  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004d8905  ebc9                 jmp 0x4d88d0
// 004d8907  8b36                 mov esi, dword ptr [esi]
// 004d8909  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004d890d  5f                   pop edi
// 004d890e  8930                 mov dword ptr [eax], esi
// 004d8910  5e                   pop esi
// 004d8911  5d                   pop ebp
// 004d8912  895804               mov dword ptr [eax + 4], ebx
// 004d8915  5b                   pop ebx
// 004d8916  83c408               add esp, 8
// 004d8919  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
