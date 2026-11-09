// from server: 100% by auto
// roc 2007-08 004b5fe0  unit: RBX::Network::Replicator  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b5fe0
//
// 004b5fe0  83ec08               sub esp, 8
// 004b5fe3  53                   push ebx
// 004b5fe4  55                   push ebp
// 004b5fe5  56                   push esi
// 004b5fe6  57                   push edi
// 004b5fe7  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b5feb  85ff                 test edi, edi
// 004b5fed  8bf1                 mov esi, ecx
// 004b5fef  8b4604               mov eax, dword ptr [esi + 4]
// 004b5ff2  8b28                 mov ebp, dword ptr [eax]
// 004b5ff4  7404                 je 0x4b5ffa
// 004b5ff6  3bfe                 cmp edi, esi
// 004b5ff8  7406                 je 0x4b6000
// 004b5ffa  ff15d8e67700         call dword ptr [0x77e6d8]
// 004b6000  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004b6004  3bdd                 cmp ebx, ebp
// 004b6006  7559                 jne 0x4b6061
// 004b6008  8b442428             mov eax, dword ptr [esp + 0x28]
// 004b600c  85c0                 test eax, eax
// 004b600e  8b6e04               mov ebp, dword ptr [esi + 4]
// 004b6011  7404                 je 0x4b6017
// 004b6013  3bc6                 cmp eax, esi
// 004b6015  7406                 je 0x4b601d
// 004b6017  ff15d8e67700         call dword ptr [0x77e6d8]
// 004b601d  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 004b6021  753e                 jne 0x4b6061
// 004b6023  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b6026  8b5104               mov edx, dword ptr [ecx + 4]
// 004b6029  52                   push edx
// 004b602a  8bce                 mov ecx, esi
// 004b602c  e8dfd8ffff           call 0x4b3910
// 004b6031  8b4604               mov eax, dword ptr [esi + 4]
// 004b6034  894004               mov dword ptr [eax + 4], eax
// 004b6037  8b4604               mov eax, dword ptr [esi + 4]
// 004b603a  c7460800000000       mov dword ptr [esi + 8], 0
// 004b6041  8900                 mov dword ptr [eax], eax
// 004b6043  8b4604               mov eax, dword ptr [esi + 4]
// 004b6046  894008               mov dword ptr [eax + 8], eax
// 004b6049  8b4604               mov eax, dword ptr [esi + 4]
// 004b604c  8b08                 mov ecx, dword ptr [eax]
// 004b604e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004b6052  5f                   pop edi
// 004b6053  8930                 mov dword ptr [eax], esi
// 004b6055  5e                   pop esi
// 004b6056  5d                   pop ebp
// 004b6057  894804               mov dword ptr [eax + 4], ecx
// 004b605a  5b                   pop ebx
// 004b605b  83c408               add esp, 8
// 004b605e  c21400               ret 0x14
// 004b6061  85ff                 test edi, edi
// 004b6063  7406                 je 0x4b606b
// 004b6065  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004b6069  7406                 je 0x4b6071
// 004b606b  ff15d8e67700         call dword ptr [0x77e6d8]
// 004b6071  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004b6075  7421                 je 0x4b6098
// 004b6077  8d4c2420             lea ecx, [esp + 0x20]
// 004b607b  e8f0a70100           call 0x4d0870
// 004b6080  53                   push ebx
// 004b6081  57                   push edi
// 004b6082  8d542418             lea edx, [esp + 0x18]
// 004b6086  52                   push edx
// 004b6087  8bce                 mov ecx, esi
// 004b6089  e8a2cbfeff           call 0x4a2c30
// 004b608e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004b6092  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b6096  ebc9                 jmp 0x4b6061
// 004b6098  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004b609c  8938                 mov dword ptr [eax], edi
// 004b609e  5f                   pop edi
// 004b609f  5e                   pop esi
// 004b60a0  5d                   pop ebp
// 004b60a1  895804               mov dword ptr [eax + 4], ebx
// 004b60a4  5b                   pop ebx
// 004b60a5  83c408               add esp, 8
// 004b60a8  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
