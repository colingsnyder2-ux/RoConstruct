// from server: 100% by auto
// roc 2009-06 006e5790  unit: RBX::ScoreHud  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e5790
//
// 006e5790  83ec08               sub esp, 8
// 006e5793  53                   push ebx
// 006e5794  55                   push ebp
// 006e5795  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 006e579b  56                   push esi
// 006e579c  8bf1                 mov esi, ecx
// 006e579e  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e57a1  8b18                 mov ebx, dword ptr [eax]
// 006e57a3  8b06                 mov eax, dword ptr [esi]
// 006e57a5  57                   push edi
// 006e57a6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e57aa  85ff                 test edi, edi
// 006e57ac  7404                 je 0x6e57b2
// 006e57ae  3bf8                 cmp edi, eax
// 006e57b0  7406                 je 0x6e57b8
// 006e57b2  ffd5                 call ebp
// 006e57b4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e57b8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006e57bc  7562                 jne 0x6e5820
// 006e57be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006e57c2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006e57c5  8b06                 mov eax, dword ptr [esi]
// 006e57c7  85c9                 test ecx, ecx
// 006e57c9  7404                 je 0x6e57cf
// 006e57cb  3bc8                 cmp ecx, eax
// 006e57cd  7406                 je 0x6e57d5
// 006e57cf  ffd5                 call ebp
// 006e57d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e57d5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006e57d9  7545                 jne 0x6e5820
// 006e57db  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006e57de  8b5104               mov edx, dword ptr [ecx + 4]
// 006e57e1  52                   push edx
// 006e57e2  8bce                 mov ecx, esi
// 006e57e4  e847f5ffff           call 0x6e4d30
// 006e57e9  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e57ec  894004               mov dword ptr [eax + 4], eax
// 006e57ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e57f2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006e57f9  8900                 mov dword ptr [eax], eax
// 006e57fb  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e57fe  894008               mov dword ptr [eax + 8], eax
// 006e5801  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e5804  8b16                 mov edx, dword ptr [esi]
// 006e5806  8b08                 mov ecx, dword ptr [eax]
// 006e5808  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006e580c  5f                   pop edi
// 006e580d  5e                   pop esi
// 006e580e  5d                   pop ebp
// 006e580f  894804               mov dword ptr [eax + 4], ecx
// 006e5812  8910                 mov dword ptr [eax], edx
// 006e5814  5b                   pop ebx
// 006e5815  83c408               add esp, 8
// 006e5818  c21400               ret 0x14
// 006e581b  eb03                 jmp 0x6e5820
// 006e581d  8d4900               lea ecx, [ecx]
// 006e5820  85ff                 test edi, edi
// 006e5822  7406                 je 0x6e582a
// 006e5824  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006e5828  7406                 je 0x6e5830
// 006e582a  ffd5                 call ebp
// 006e582c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e5830  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006e5834  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006e5838  741d                 je 0x6e5857
// 006e583a  8d4c2420             lea ecx, [esp + 0x20]
// 006e583e  e82d2bf3ff           call 0x618370
// 006e5843  53                   push ebx
// 006e5844  57                   push edi
// 006e5845  8d442418             lea eax, [esp + 0x18]
// 006e5849  50                   push eax
// 006e584a  8bce                 mov ecx, esi
// 006e584c  e8ffeeffff           call 0x6e4750
// 006e5851  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e5855  ebc9                 jmp 0x6e5820
// 006e5857  8b36                 mov esi, dword ptr [esi]
// 006e5859  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006e585d  5f                   pop edi
// 006e585e  8930                 mov dword ptr [eax], esi
// 006e5860  5e                   pop esi
// 006e5861  5d                   pop ebp
// 006e5862  895804               mov dword ptr [eax + 4], ebx
// 006e5865  5b                   pop ebx
// 006e5866  83c408               add esp, 8
// 006e5869  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
