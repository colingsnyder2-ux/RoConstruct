// from server: 100% by auto
// roc 2009-06 006e5870  unit: RBX::ScoreHud  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e5870
//
// 006e5870  83ec08               sub esp, 8
// 006e5873  53                   push ebx
// 006e5874  55                   push ebp
// 006e5875  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 006e587b  56                   push esi
// 006e587c  8bf1                 mov esi, ecx
// 006e587e  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e5881  8b18                 mov ebx, dword ptr [eax]
// 006e5883  8b06                 mov eax, dword ptr [esi]
// 006e5885  57                   push edi
// 006e5886  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e588a  85ff                 test edi, edi
// 006e588c  7404                 je 0x6e5892
// 006e588e  3bf8                 cmp edi, eax
// 006e5890  7406                 je 0x6e5898
// 006e5892  ffd5                 call ebp
// 006e5894  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e5898  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006e589c  7562                 jne 0x6e5900
// 006e589e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006e58a2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006e58a5  8b06                 mov eax, dword ptr [esi]
// 006e58a7  85c9                 test ecx, ecx
// 006e58a9  7404                 je 0x6e58af
// 006e58ab  3bc8                 cmp ecx, eax
// 006e58ad  7406                 je 0x6e58b5
// 006e58af  ffd5                 call ebp
// 006e58b1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e58b5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006e58b9  7545                 jne 0x6e5900
// 006e58bb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006e58be  8b5104               mov edx, dword ptr [ecx + 4]
// 006e58c1  52                   push edx
// 006e58c2  8bce                 mov ecx, esi
// 006e58c4  e8f7f4ffff           call 0x6e4dc0
// 006e58c9  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e58cc  894004               mov dword ptr [eax + 4], eax
// 006e58cf  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e58d2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006e58d9  8900                 mov dword ptr [eax], eax
// 006e58db  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e58de  894008               mov dword ptr [eax + 8], eax
// 006e58e1  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e58e4  8b16                 mov edx, dword ptr [esi]
// 006e58e6  8b08                 mov ecx, dword ptr [eax]
// 006e58e8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006e58ec  5f                   pop edi
// 006e58ed  5e                   pop esi
// 006e58ee  5d                   pop ebp
// 006e58ef  894804               mov dword ptr [eax + 4], ecx
// 006e58f2  8910                 mov dword ptr [eax], edx
// 006e58f4  5b                   pop ebx
// 006e58f5  83c408               add esp, 8
// 006e58f8  c21400               ret 0x14
// 006e58fb  eb03                 jmp 0x6e5900
// 006e58fd  8d4900               lea ecx, [ecx]
// 006e5900  85ff                 test edi, edi
// 006e5902  7406                 je 0x6e590a
// 006e5904  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006e5908  7406                 je 0x6e5910
// 006e590a  ffd5                 call ebp
// 006e590c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e5910  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006e5914  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006e5918  741d                 je 0x6e5937
// 006e591a  8d4c2420             lea ecx, [esp + 0x20]
// 006e591e  e88dc9ffff           call 0x6e22b0
// 006e5923  53                   push ebx
// 006e5924  57                   push edi
// 006e5925  8d442418             lea eax, [esp + 0x18]
// 006e5929  50                   push eax
// 006e592a  8bce                 mov ecx, esi
// 006e592c  e81ff1ffff           call 0x6e4a50
// 006e5931  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e5935  ebc9                 jmp 0x6e5900
// 006e5937  8b36                 mov esi, dword ptr [esi]
// 006e5939  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006e593d  5f                   pop edi
// 006e593e  8930                 mov dword ptr [eax], esi
// 006e5940  5e                   pop esi
// 006e5941  5d                   pop ebp
// 006e5942  895804               mov dword ptr [eax + 4], ebx
// 006e5945  5b                   pop ebx
// 006e5946  83c408               add esp, 8
// 006e5949  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
