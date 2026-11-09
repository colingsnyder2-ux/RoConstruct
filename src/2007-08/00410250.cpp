// from server: 100% by auto
// roc 2007-08 00410250  unit: CopyVerb  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00410250
//
// 00410250  83ec08               sub esp, 8
// 00410253  53                   push ebx
// 00410254  55                   push ebp
// 00410255  56                   push esi
// 00410256  57                   push edi
// 00410257  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041025b  85ff                 test edi, edi
// 0041025d  8bf1                 mov esi, ecx
// 0041025f  8b4604               mov eax, dword ptr [esi + 4]
// 00410262  8b28                 mov ebp, dword ptr [eax]
// 00410264  7404                 je 0x41026a
// 00410266  3bfe                 cmp edi, esi
// 00410268  7406                 je 0x410270
// 0041026a  ff15d8e67700         call dword ptr [0x77e6d8]
// 00410270  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00410274  3bdd                 cmp ebx, ebp
// 00410276  7559                 jne 0x4102d1
// 00410278  8b442428             mov eax, dword ptr [esp + 0x28]
// 0041027c  85c0                 test eax, eax
// 0041027e  8b6e04               mov ebp, dword ptr [esi + 4]
// 00410281  7404                 je 0x410287
// 00410283  3bc6                 cmp eax, esi
// 00410285  7406                 je 0x41028d
// 00410287  ff15d8e67700         call dword ptr [0x77e6d8]
// 0041028d  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 00410291  753e                 jne 0x4102d1
// 00410293  8b4e04               mov ecx, dword ptr [esi + 4]
// 00410296  8b5104               mov edx, dword ptr [ecx + 4]
// 00410299  52                   push edx
// 0041029a  8bce                 mov ecx, esi
// 0041029c  e88ffeffff           call 0x410130
// 004102a1  8b4604               mov eax, dword ptr [esi + 4]
// 004102a4  894004               mov dword ptr [eax + 4], eax
// 004102a7  8b4604               mov eax, dword ptr [esi + 4]
// 004102aa  c7460800000000       mov dword ptr [esi + 8], 0
// 004102b1  8900                 mov dword ptr [eax], eax
// 004102b3  8b4604               mov eax, dword ptr [esi + 4]
// 004102b6  894008               mov dword ptr [eax + 8], eax
// 004102b9  8b4604               mov eax, dword ptr [esi + 4]
// 004102bc  8b08                 mov ecx, dword ptr [eax]
// 004102be  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004102c2  5f                   pop edi
// 004102c3  8930                 mov dword ptr [eax], esi
// 004102c5  5e                   pop esi
// 004102c6  5d                   pop ebp
// 004102c7  894804               mov dword ptr [eax + 4], ecx
// 004102ca  5b                   pop ebx
// 004102cb  83c408               add esp, 8
// 004102ce  c21400               ret 0x14
// 004102d1  85ff                 test edi, edi
// 004102d3  7406                 je 0x4102db
// 004102d5  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004102d9  7406                 je 0x4102e1
// 004102db  ff15d8e67700         call dword ptr [0x77e6d8]
// 004102e1  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004102e5  7421                 je 0x410308
// 004102e7  8d4c2420             lea ecx, [esp + 0x20]
// 004102eb  e8d0791700           call 0x587cc0
// 004102f0  53                   push ebx
// 004102f1  57                   push edi
// 004102f2  8d542418             lea edx, [esp + 0x18]
// 004102f6  52                   push edx
// 004102f7  8bce                 mov ecx, esi
// 004102f9  e852fbffff           call 0x40fe50
// 004102fe  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00410302  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00410306  ebc9                 jmp 0x4102d1
// 00410308  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041030c  8938                 mov dword ptr [eax], edi
// 0041030e  5f                   pop edi
// 0041030f  5e                   pop esi
// 00410310  5d                   pop ebp
// 00410311  895804               mov dword ptr [eax + 4], ebx
// 00410314  5b                   pop ebx
// 00410315  83c408               add esp, 8
// 00410318  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
