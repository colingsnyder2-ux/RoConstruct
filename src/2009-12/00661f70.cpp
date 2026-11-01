// from server: 100% by auto
// roc 2009-12 00661f70  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00661f70
//
// 00661f70  83ec08               sub esp, 8
// 00661f73  53                   push ebx
// 00661f74  55                   push ebp
// 00661f75  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 00661f7b  56                   push esi
// 00661f7c  8bf1                 mov esi, ecx
// 00661f7e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00661f81  8b18                 mov ebx, dword ptr [eax]
// 00661f83  8b06                 mov eax, dword ptr [esi]
// 00661f85  57                   push edi
// 00661f86  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00661f8a  85ff                 test edi, edi
// 00661f8c  7404                 je 0x661f92
// 00661f8e  3bf8                 cmp edi, eax
// 00661f90  7406                 je 0x661f98
// 00661f92  ffd5                 call ebp
// 00661f94  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00661f98  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00661f9c  7562                 jne 0x662000
// 00661f9e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00661fa2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00661fa5  8b06                 mov eax, dword ptr [esi]
// 00661fa7  85c9                 test ecx, ecx
// 00661fa9  7404                 je 0x661faf
// 00661fab  3bc8                 cmp ecx, eax
// 00661fad  7406                 je 0x661fb5
// 00661faf  ffd5                 call ebp
// 00661fb1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00661fb5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00661fb9  7545                 jne 0x662000
// 00661fbb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00661fbe  8b5104               mov edx, dword ptr [ecx + 4]
// 00661fc1  52                   push edx
// 00661fc2  8bce                 mov ecx, esi
// 00661fc4  e8471bddff           call 0x433b10
// 00661fc9  8b4618               mov eax, dword ptr [esi + 0x18]
// 00661fcc  894004               mov dword ptr [eax + 4], eax
// 00661fcf  8b4618               mov eax, dword ptr [esi + 0x18]
// 00661fd2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00661fd9  8900                 mov dword ptr [eax], eax
// 00661fdb  8b4618               mov eax, dword ptr [esi + 0x18]
// 00661fde  894008               mov dword ptr [eax + 8], eax
// 00661fe1  8b4618               mov eax, dword ptr [esi + 0x18]
// 00661fe4  8b16                 mov edx, dword ptr [esi]
// 00661fe6  8b08                 mov ecx, dword ptr [eax]
// 00661fe8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00661fec  5f                   pop edi
// 00661fed  5e                   pop esi
// 00661fee  5d                   pop ebp
// 00661fef  894804               mov dword ptr [eax + 4], ecx
// 00661ff2  8910                 mov dword ptr [eax], edx
// 00661ff4  5b                   pop ebx
// 00661ff5  83c408               add esp, 8
// 00661ff8  c21400               ret 0x14
// 00661ffb  eb03                 jmp 0x662000
// 00661ffd  8d4900               lea ecx, [ecx]
// 00662000  85ff                 test edi, edi
// 00662002  7406                 je 0x66200a
// 00662004  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00662008  7406                 je 0x662010
// 0066200a  ffd5                 call ebp
// 0066200c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00662010  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00662014  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00662018  741d                 je 0x662037
// 0066201a  8d4c2420             lea ecx, [esp + 0x20]
// 0066201e  e8cdb00400           call 0x6ad0f0
// 00662023  53                   push ebx
// 00662024  57                   push edi
// 00662025  8d442418             lea eax, [esp + 0x18]
// 00662029  50                   push eax
// 0066202a  8bce                 mov ecx, esi
// 0066202c  e86ffcffff           call 0x661ca0
// 00662031  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00662035  ebc9                 jmp 0x662000
// 00662037  8b36                 mov esi, dword ptr [esi]
// 00662039  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0066203d  5f                   pop edi
// 0066203e  8930                 mov dword ptr [eax], esi
// 00662040  5e                   pop esi
// 00662041  5d                   pop ebp
// 00662042  895804               mov dword ptr [eax + 4], ebx
// 00662045  5b                   pop ebx
// 00662046  83c408               add esp, 8
// 00662049  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
