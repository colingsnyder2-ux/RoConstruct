// from server: 100% by auto
// roc 2008-06 00592530  unit: RBX::RootInstance  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00592530
//
// 00592530  83ec08               sub esp, 8
// 00592533  53                   push ebx
// 00592534  55                   push ebp
// 00592535  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0059253b  56                   push esi
// 0059253c  8bf1                 mov esi, ecx
// 0059253e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00592541  8b18                 mov ebx, dword ptr [eax]
// 00592543  8b06                 mov eax, dword ptr [esi]
// 00592545  57                   push edi
// 00592546  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0059254a  85ff                 test edi, edi
// 0059254c  7404                 je 0x592552
// 0059254e  3bf8                 cmp edi, eax
// 00592550  7406                 je 0x592558
// 00592552  ffd5                 call ebp
// 00592554  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00592558  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0059255c  7562                 jne 0x5925c0
// 0059255e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00592562  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00592565  8b06                 mov eax, dword ptr [esi]
// 00592567  85c9                 test ecx, ecx
// 00592569  7404                 je 0x59256f
// 0059256b  3bc8                 cmp ecx, eax
// 0059256d  7406                 je 0x592575
// 0059256f  ffd5                 call ebp
// 00592571  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00592575  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00592579  7545                 jne 0x5925c0
// 0059257b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0059257e  8b5104               mov edx, dword ptr [ecx + 4]
// 00592581  52                   push edx
// 00592582  8bce                 mov ecx, esi
// 00592584  e8b7fbffff           call 0x592140
// 00592589  8b4618               mov eax, dword ptr [esi + 0x18]
// 0059258c  894004               mov dword ptr [eax + 4], eax
// 0059258f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00592592  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00592599  8900                 mov dword ptr [eax], eax
// 0059259b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0059259e  894008               mov dword ptr [eax + 8], eax
// 005925a1  8b4618               mov eax, dword ptr [esi + 0x18]
// 005925a4  8b16                 mov edx, dword ptr [esi]
// 005925a6  8b08                 mov ecx, dword ptr [eax]
// 005925a8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005925ac  5f                   pop edi
// 005925ad  5e                   pop esi
// 005925ae  5d                   pop ebp
// 005925af  894804               mov dword ptr [eax + 4], ecx
// 005925b2  8910                 mov dword ptr [eax], edx
// 005925b4  5b                   pop ebx
// 005925b5  83c408               add esp, 8
// 005925b8  c21400               ret 0x14
// 005925bb  eb03                 jmp 0x5925c0
// 005925bd  8d4900               lea ecx, [ecx]
// 005925c0  85ff                 test edi, edi
// 005925c2  7406                 je 0x5925ca
// 005925c4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005925c8  7406                 je 0x5925d0
// 005925ca  ffd5                 call ebp
// 005925cc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005925d0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005925d4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005925d8  741d                 je 0x5925f7
// 005925da  8d4c2420             lea ecx, [esp + 0x20]
// 005925de  e89df2ffff           call 0x591880
// 005925e3  53                   push ebx
// 005925e4  57                   push edi
// 005925e5  8d442418             lea eax, [esp + 0x18]
// 005925e9  50                   push eax
// 005925ea  8bce                 mov ecx, esi
// 005925ec  e86ff8ffff           call 0x591e60
// 005925f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005925f5  ebc9                 jmp 0x5925c0
// 005925f7  8b36                 mov esi, dword ptr [esi]
// 005925f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005925fd  5f                   pop edi
// 005925fe  8930                 mov dword ptr [eax], esi
// 00592600  5e                   pop esi
// 00592601  5d                   pop ebp
// 00592602  895804               mov dword ptr [eax + 4], ebx
// 00592605  5b                   pop ebx
// 00592606  83c408               add esp, 8
// 00592609  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
