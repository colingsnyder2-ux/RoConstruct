// from server: 100% by auto
// roc 2008-06 00424430  unit: CSelectionTreeCtrl  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00424430
//
// 00424430  83ec08               sub esp, 8
// 00424433  53                   push ebx
// 00424434  55                   push ebp
// 00424435  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0042443b  56                   push esi
// 0042443c  8bf1                 mov esi, ecx
// 0042443e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00424441  8b18                 mov ebx, dword ptr [eax]
// 00424443  8b06                 mov eax, dword ptr [esi]
// 00424445  57                   push edi
// 00424446  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0042444a  85ff                 test edi, edi
// 0042444c  7404                 je 0x424452
// 0042444e  3bf8                 cmp edi, eax
// 00424450  7406                 je 0x424458
// 00424452  ffd5                 call ebp
// 00424454  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00424458  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0042445c  7562                 jne 0x4244c0
// 0042445e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00424462  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00424465  8b06                 mov eax, dword ptr [esi]
// 00424467  85c9                 test ecx, ecx
// 00424469  7404                 je 0x42446f
// 0042446b  3bc8                 cmp ecx, eax
// 0042446d  7406                 je 0x424475
// 0042446f  ffd5                 call ebp
// 00424471  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00424475  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00424479  7545                 jne 0x4244c0
// 0042447b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0042447e  8b5104               mov edx, dword ptr [ecx + 4]
// 00424481  52                   push edx
// 00424482  8bce                 mov ecx, esi
// 00424484  e8c7f5ffff           call 0x423a50
// 00424489  8b4618               mov eax, dword ptr [esi + 0x18]
// 0042448c  894004               mov dword ptr [eax + 4], eax
// 0042448f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00424492  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00424499  8900                 mov dword ptr [eax], eax
// 0042449b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0042449e  894008               mov dword ptr [eax + 8], eax
// 004244a1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004244a4  8b16                 mov edx, dword ptr [esi]
// 004244a6  8b08                 mov ecx, dword ptr [eax]
// 004244a8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004244ac  5f                   pop edi
// 004244ad  5e                   pop esi
// 004244ae  5d                   pop ebp
// 004244af  894804               mov dword ptr [eax + 4], ecx
// 004244b2  8910                 mov dword ptr [eax], edx
// 004244b4  5b                   pop ebx
// 004244b5  83c408               add esp, 8
// 004244b8  c21400               ret 0x14
// 004244bb  eb03                 jmp 0x4244c0
// 004244bd  8d4900               lea ecx, [ecx]
// 004244c0  85ff                 test edi, edi
// 004244c2  7406                 je 0x4244ca
// 004244c4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004244c8  7406                 je 0x4244d0
// 004244ca  ffd5                 call ebp
// 004244cc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004244d0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004244d4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004244d8  741d                 je 0x4244f7
// 004244da  8d4c2420             lea ecx, [esp + 0x20]
// 004244de  e8bd9a2600           call 0x68dfa0
// 004244e3  53                   push ebx
// 004244e4  57                   push edi
// 004244e5  8d442418             lea eax, [esp + 0x18]
// 004244e9  50                   push eax
// 004244ea  8bce                 mov ecx, esi
// 004244ec  e83ffcffff           call 0x424130
// 004244f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004244f5  ebc9                 jmp 0x4244c0
// 004244f7  8b36                 mov esi, dword ptr [esi]
// 004244f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004244fd  5f                   pop edi
// 004244fe  8930                 mov dword ptr [eax], esi
// 00424500  5e                   pop esi
// 00424501  5d                   pop ebp
// 00424502  895804               mov dword ptr [eax + 4], ebx
// 00424505  5b                   pop ebx
// 00424506  83c408               add esp, 8
// 00424509  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
