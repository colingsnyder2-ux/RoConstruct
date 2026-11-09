// from server: 100% by auto
// roc 2008-06 005b4050  unit: RBX::VHat::?$FactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b4050
//
// 005b4050  83ec08               sub esp, 8
// 005b4053  53                   push ebx
// 005b4054  55                   push ebp
// 005b4055  8b2d90288000         mov ebp, dword ptr [0x802890]
// 005b405b  56                   push esi
// 005b405c  8bf1                 mov esi, ecx
// 005b405e  8b4618               mov eax, dword ptr [esi + 0x18]
// 005b4061  8b18                 mov ebx, dword ptr [eax]
// 005b4063  8b06                 mov eax, dword ptr [esi]
// 005b4065  57                   push edi
// 005b4066  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005b406a  85ff                 test edi, edi
// 005b406c  7404                 je 0x5b4072
// 005b406e  3bf8                 cmp edi, eax
// 005b4070  7406                 je 0x5b4078
// 005b4072  ffd5                 call ebp
// 005b4074  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005b4078  395c2424             cmp dword ptr [esp + 0x24], ebx
// 005b407c  7562                 jne 0x5b40e0
// 005b407e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005b4082  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 005b4085  8b06                 mov eax, dword ptr [esi]
// 005b4087  85c9                 test ecx, ecx
// 005b4089  7404                 je 0x5b408f
// 005b408b  3bc8                 cmp ecx, eax
// 005b408d  7406                 je 0x5b4095
// 005b408f  ffd5                 call ebp
// 005b4091  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005b4095  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 005b4099  7545                 jne 0x5b40e0
// 005b409b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005b409e  8b5104               mov edx, dword ptr [ecx + 4]
// 005b40a1  52                   push edx
// 005b40a2  8bce                 mov ecx, esi
// 005b40a4  e8b7f7ffff           call 0x5b3860
// 005b40a9  8b4618               mov eax, dword ptr [esi + 0x18]
// 005b40ac  894004               mov dword ptr [eax + 4], eax
// 005b40af  8b4618               mov eax, dword ptr [esi + 0x18]
// 005b40b2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005b40b9  8900                 mov dword ptr [eax], eax
// 005b40bb  8b4618               mov eax, dword ptr [esi + 0x18]
// 005b40be  894008               mov dword ptr [eax + 8], eax
// 005b40c1  8b4618               mov eax, dword ptr [esi + 0x18]
// 005b40c4  8b16                 mov edx, dword ptr [esi]
// 005b40c6  8b08                 mov ecx, dword ptr [eax]
// 005b40c8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b40cc  5f                   pop edi
// 005b40cd  5e                   pop esi
// 005b40ce  5d                   pop ebp
// 005b40cf  894804               mov dword ptr [eax + 4], ecx
// 005b40d2  8910                 mov dword ptr [eax], edx
// 005b40d4  5b                   pop ebx
// 005b40d5  83c408               add esp, 8
// 005b40d8  c21400               ret 0x14
// 005b40db  eb03                 jmp 0x5b40e0
// 005b40dd  8d4900               lea ecx, [ecx]
// 005b40e0  85ff                 test edi, edi
// 005b40e2  7406                 je 0x5b40ea
// 005b40e4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005b40e8  7406                 je 0x5b40f0
// 005b40ea  ffd5                 call ebp
// 005b40ec  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005b40f0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005b40f4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005b40f8  741d                 je 0x5b4117
// 005b40fa  8d4c2420             lea ecx, [esp + 0x20]
// 005b40fe  e89d900d00           call 0x68d1a0
// 005b4103  53                   push ebx
// 005b4104  57                   push edi
// 005b4105  8d442418             lea eax, [esp + 0x18]
// 005b4109  50                   push eax
// 005b410a  8bce                 mov ecx, esi
// 005b410c  e86ff4ffff           call 0x5b3580
// 005b4111  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005b4115  ebc9                 jmp 0x5b40e0
// 005b4117  8b36                 mov esi, dword ptr [esi]
// 005b4119  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b411d  5f                   pop edi
// 005b411e  8930                 mov dword ptr [eax], esi
// 005b4120  5e                   pop esi
// 005b4121  5d                   pop ebp
// 005b4122  895804               mov dword ptr [eax + 4], ebx
// 005b4125  5b                   pop ebx
// 005b4126  83c408               add esp, 8
// 005b4129  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
