// from server: 100% by auto
// roc 2010-06 0053ed70  unit: RBX::Mesh  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0053ed70
//
// 0053ed70  83ec08               sub esp, 8
// 0053ed73  53                   push ebx
// 0053ed74  55                   push ebp
// 0053ed75  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0053ed7b  56                   push esi
// 0053ed7c  8bf1                 mov esi, ecx
// 0053ed7e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053ed81  8b18                 mov ebx, dword ptr [eax]
// 0053ed83  8b06                 mov eax, dword ptr [esi]
// 0053ed85  57                   push edi
// 0053ed86  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053ed8a  85ff                 test edi, edi
// 0053ed8c  7404                 je 0x53ed92
// 0053ed8e  3bf8                 cmp edi, eax
// 0053ed90  7406                 je 0x53ed98
// 0053ed92  ffd5                 call ebp
// 0053ed94  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053ed98  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0053ed9c  7562                 jne 0x53ee00
// 0053ed9e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0053eda2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0053eda5  8b06                 mov eax, dword ptr [esi]
// 0053eda7  85c9                 test ecx, ecx
// 0053eda9  7404                 je 0x53edaf
// 0053edab  3bc8                 cmp ecx, eax
// 0053edad  7406                 je 0x53edb5
// 0053edaf  ffd5                 call ebp
// 0053edb1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053edb5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0053edb9  7545                 jne 0x53ee00
// 0053edbb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0053edbe  8b5104               mov edx, dword ptr [ecx + 4]
// 0053edc1  52                   push edx
// 0053edc2  8bce                 mov ecx, esi
// 0053edc4  e827fbffff           call 0x53e8f0
// 0053edc9  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053edcc  894004               mov dword ptr [eax + 4], eax
// 0053edcf  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053edd2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0053edd9  8900                 mov dword ptr [eax], eax
// 0053eddb  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053edde  894008               mov dword ptr [eax + 8], eax
// 0053ede1  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053ede4  8b16                 mov edx, dword ptr [esi]
// 0053ede6  8b08                 mov ecx, dword ptr [eax]
// 0053ede8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053edec  5f                   pop edi
// 0053eded  5e                   pop esi
// 0053edee  5d                   pop ebp
// 0053edef  894804               mov dword ptr [eax + 4], ecx
// 0053edf2  8910                 mov dword ptr [eax], edx
// 0053edf4  5b                   pop ebx
// 0053edf5  83c408               add esp, 8
// 0053edf8  c21400               ret 0x14
// 0053edfb  eb03                 jmp 0x53ee00
// 0053edfd  8d4900               lea ecx, [ecx]
// 0053ee00  85ff                 test edi, edi
// 0053ee02  7406                 je 0x53ee0a
// 0053ee04  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0053ee08  7406                 je 0x53ee10
// 0053ee0a  ffd5                 call ebp
// 0053ee0c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053ee10  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0053ee14  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0053ee18  741d                 je 0x53ee37
// 0053ee1a  8d4c2420             lea ecx, [esp + 0x20]
// 0053ee1e  e84df1ffff           call 0x53df70
// 0053ee23  53                   push ebx
// 0053ee24  57                   push edi
// 0053ee25  8d442418             lea eax, [esp + 0x18]
// 0053ee29  50                   push eax
// 0053ee2a  8bce                 mov ecx, esi
// 0053ee2c  e85ff5ffff           call 0x53e390
// 0053ee31  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053ee35  ebc9                 jmp 0x53ee00
// 0053ee37  8b36                 mov esi, dword ptr [esi]
// 0053ee39  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053ee3d  5f                   pop edi
// 0053ee3e  8930                 mov dword ptr [eax], esi
// 0053ee40  5e                   pop esi
// 0053ee41  5d                   pop ebp
// 0053ee42  895804               mov dword ptr [eax + 4], ebx
// 0053ee45  5b                   pop ebx
// 0053ee46  83c408               add esp, 8
// 0053ee49  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
