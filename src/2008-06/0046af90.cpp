// from server: 100% by auto
// roc 2008-06 0046af90  unit: VCWorkspace::?$CComObject  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046af90
//
// 0046af90  83ec08               sub esp, 8
// 0046af93  53                   push ebx
// 0046af94  55                   push ebp
// 0046af95  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0046af9b  56                   push esi
// 0046af9c  8bf1                 mov esi, ecx
// 0046af9e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0046afa1  8b18                 mov ebx, dword ptr [eax]
// 0046afa3  8b06                 mov eax, dword ptr [esi]
// 0046afa5  57                   push edi
// 0046afa6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0046afaa  85ff                 test edi, edi
// 0046afac  7404                 je 0x46afb2
// 0046afae  3bf8                 cmp edi, eax
// 0046afb0  7406                 je 0x46afb8
// 0046afb2  ffd5                 call ebp
// 0046afb4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0046afb8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0046afbc  7562                 jne 0x46b020
// 0046afbe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0046afc2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0046afc5  8b06                 mov eax, dword ptr [esi]
// 0046afc7  85c9                 test ecx, ecx
// 0046afc9  7404                 je 0x46afcf
// 0046afcb  3bc8                 cmp ecx, eax
// 0046afcd  7406                 je 0x46afd5
// 0046afcf  ffd5                 call ebp
// 0046afd1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0046afd5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0046afd9  7545                 jne 0x46b020
// 0046afdb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0046afde  8b5104               mov edx, dword ptr [ecx + 4]
// 0046afe1  52                   push edx
// 0046afe2  8bce                 mov ecx, esi
// 0046afe4  e887892200           call 0x693970
// 0046afe9  8b4618               mov eax, dword ptr [esi + 0x18]
// 0046afec  894004               mov dword ptr [eax + 4], eax
// 0046afef  8b4618               mov eax, dword ptr [esi + 0x18]
// 0046aff2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0046aff9  8900                 mov dword ptr [eax], eax
// 0046affb  8b4618               mov eax, dword ptr [esi + 0x18]
// 0046affe  894008               mov dword ptr [eax + 8], eax
// 0046b001  8b4618               mov eax, dword ptr [esi + 0x18]
// 0046b004  8b16                 mov edx, dword ptr [esi]
// 0046b006  8b08                 mov ecx, dword ptr [eax]
// 0046b008  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0046b00c  5f                   pop edi
// 0046b00d  5e                   pop esi
// 0046b00e  5d                   pop ebp
// 0046b00f  894804               mov dword ptr [eax + 4], ecx
// 0046b012  8910                 mov dword ptr [eax], edx
// 0046b014  5b                   pop ebx
// 0046b015  83c408               add esp, 8
// 0046b018  c21400               ret 0x14
// 0046b01b  eb03                 jmp 0x46b020
// 0046b01d  8d4900               lea ecx, [ecx]
// 0046b020  85ff                 test edi, edi
// 0046b022  7406                 je 0x46b02a
// 0046b024  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0046b028  7406                 je 0x46b030
// 0046b02a  ffd5                 call ebp
// 0046b02c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0046b030  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0046b034  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0046b038  741d                 je 0x46b057
// 0046b03a  8d4c2420             lea ecx, [esp + 0x20]
// 0046b03e  e85d212200           call 0x68d1a0
// 0046b043  53                   push ebx
// 0046b044  57                   push edi
// 0046b045  8d442418             lea eax, [esp + 0x18]
// 0046b049  50                   push eax
// 0046b04a  8bce                 mov ecx, esi
// 0046b04c  e8ffbb2200           call 0x696c50
// 0046b051  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0046b055  ebc9                 jmp 0x46b020
// 0046b057  8b36                 mov esi, dword ptr [esi]
// 0046b059  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0046b05d  5f                   pop edi
// 0046b05e  8930                 mov dword ptr [eax], esi
// 0046b060  5e                   pop esi
// 0046b061  5d                   pop ebp
// 0046b062  895804               mov dword ptr [eax + 4], ebx
// 0046b065  5b                   pop ebx
// 0046b066  83c408               add esp, 8
// 0046b069  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
