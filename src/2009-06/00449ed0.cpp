// from server: 100% by auto
// roc 2009-06 00449ed0  unit: RBX::VExplosion::?$FactoryProduct::Creator  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00449ed0
//
// 00449ed0  83ec08               sub esp, 8
// 00449ed3  53                   push ebx
// 00449ed4  55                   push ebp
// 00449ed5  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00449edb  56                   push esi
// 00449edc  8bf1                 mov esi, ecx
// 00449ede  8b4618               mov eax, dword ptr [esi + 0x18]
// 00449ee1  8b18                 mov ebx, dword ptr [eax]
// 00449ee3  8b06                 mov eax, dword ptr [esi]
// 00449ee5  57                   push edi
// 00449ee6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00449eea  85ff                 test edi, edi
// 00449eec  7404                 je 0x449ef2
// 00449eee  3bf8                 cmp edi, eax
// 00449ef0  7406                 je 0x449ef8
// 00449ef2  ffd5                 call ebp
// 00449ef4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00449ef8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00449efc  7562                 jne 0x449f60
// 00449efe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00449f02  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00449f05  8b06                 mov eax, dword ptr [esi]
// 00449f07  85c9                 test ecx, ecx
// 00449f09  7404                 je 0x449f0f
// 00449f0b  3bc8                 cmp ecx, eax
// 00449f0d  7406                 je 0x449f15
// 00449f0f  ffd5                 call ebp
// 00449f11  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00449f15  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00449f19  7545                 jne 0x449f60
// 00449f1b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00449f1e  8b5104               mov edx, dword ptr [ecx + 4]
// 00449f21  52                   push edx
// 00449f22  8bce                 mov ecx, esi
// 00449f24  e8a7f9ffff           call 0x4498d0
// 00449f29  8b4618               mov eax, dword ptr [esi + 0x18]
// 00449f2c  894004               mov dword ptr [eax + 4], eax
// 00449f2f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00449f32  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00449f39  8900                 mov dword ptr [eax], eax
// 00449f3b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00449f3e  894008               mov dword ptr [eax + 8], eax
// 00449f41  8b4618               mov eax, dword ptr [esi + 0x18]
// 00449f44  8b16                 mov edx, dword ptr [esi]
// 00449f46  8b08                 mov ecx, dword ptr [eax]
// 00449f48  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00449f4c  5f                   pop edi
// 00449f4d  5e                   pop esi
// 00449f4e  5d                   pop ebp
// 00449f4f  894804               mov dword ptr [eax + 4], ecx
// 00449f52  8910                 mov dword ptr [eax], edx
// 00449f54  5b                   pop ebx
// 00449f55  83c408               add esp, 8
// 00449f58  c21400               ret 0x14
// 00449f5b  eb03                 jmp 0x449f60
// 00449f5d  8d4900               lea ecx, [ecx]
// 00449f60  85ff                 test edi, edi
// 00449f62  7406                 je 0x449f6a
// 00449f64  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00449f68  7406                 je 0x449f70
// 00449f6a  ffd5                 call ebp
// 00449f6c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00449f70  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00449f74  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00449f78  741d                 je 0x449f97
// 00449f7a  8d4c2420             lea ecx, [esp + 0x20]
// 00449f7e  e82dbaffff           call 0x4459b0
// 00449f83  53                   push ebx
// 00449f84  57                   push edi
// 00449f85  8d442418             lea eax, [esp + 0x18]
// 00449f89  50                   push eax
// 00449f8a  8bce                 mov ecx, esi
// 00449f8c  e84ff6ffff           call 0x4495e0
// 00449f91  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00449f95  ebc9                 jmp 0x449f60
// 00449f97  8b36                 mov esi, dword ptr [esi]
// 00449f99  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00449f9d  5f                   pop edi
// 00449f9e  8930                 mov dword ptr [eax], esi
// 00449fa0  5e                   pop esi
// 00449fa1  5d                   pop ebp
// 00449fa2  895804               mov dword ptr [eax + 4], ebx
// 00449fa5  5b                   pop ebx
// 00449fa6  83c408               add esp, 8
// 00449fa9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
