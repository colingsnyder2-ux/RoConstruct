// from server: 100% by auto
// roc 2009-12 006bf8f0  unit: RBX::VInstance::?$NonFactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bf8f0
//
// 006bf8f0  83ec08               sub esp, 8
// 006bf8f3  53                   push ebx
// 006bf8f4  55                   push ebp
// 006bf8f5  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 006bf8fb  56                   push esi
// 006bf8fc  8bf1                 mov esi, ecx
// 006bf8fe  8b4618               mov eax, dword ptr [esi + 0x18]
// 006bf901  8b18                 mov ebx, dword ptr [eax]
// 006bf903  8b06                 mov eax, dword ptr [esi]
// 006bf905  57                   push edi
// 006bf906  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006bf90a  85ff                 test edi, edi
// 006bf90c  7404                 je 0x6bf912
// 006bf90e  3bf8                 cmp edi, eax
// 006bf910  7406                 je 0x6bf918
// 006bf912  ffd5                 call ebp
// 006bf914  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006bf918  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006bf91c  7562                 jne 0x6bf980
// 006bf91e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006bf922  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006bf925  8b06                 mov eax, dword ptr [esi]
// 006bf927  85c9                 test ecx, ecx
// 006bf929  7404                 je 0x6bf92f
// 006bf92b  3bc8                 cmp ecx, eax
// 006bf92d  7406                 je 0x6bf935
// 006bf92f  ffd5                 call ebp
// 006bf931  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006bf935  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006bf939  7545                 jne 0x6bf980
// 006bf93b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006bf93e  8b5104               mov edx, dword ptr [ecx + 4]
// 006bf941  52                   push edx
// 006bf942  8bce                 mov ecx, esi
// 006bf944  e8a7f3ffff           call 0x6becf0
// 006bf949  8b4618               mov eax, dword ptr [esi + 0x18]
// 006bf94c  894004               mov dword ptr [eax + 4], eax
// 006bf94f  8b4618               mov eax, dword ptr [esi + 0x18]
// 006bf952  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006bf959  8900                 mov dword ptr [eax], eax
// 006bf95b  8b4618               mov eax, dword ptr [esi + 0x18]
// 006bf95e  894008               mov dword ptr [eax + 8], eax
// 006bf961  8b4618               mov eax, dword ptr [esi + 0x18]
// 006bf964  8b16                 mov edx, dword ptr [esi]
// 006bf966  8b08                 mov ecx, dword ptr [eax]
// 006bf968  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006bf96c  5f                   pop edi
// 006bf96d  5e                   pop esi
// 006bf96e  5d                   pop ebp
// 006bf96f  894804               mov dword ptr [eax + 4], ecx
// 006bf972  8910                 mov dword ptr [eax], edx
// 006bf974  5b                   pop ebx
// 006bf975  83c408               add esp, 8
// 006bf978  c21400               ret 0x14
// 006bf97b  eb03                 jmp 0x6bf980
// 006bf97d  8d4900               lea ecx, [ecx]
// 006bf980  85ff                 test edi, edi
// 006bf982  7406                 je 0x6bf98a
// 006bf984  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006bf988  7406                 je 0x6bf990
// 006bf98a  ffd5                 call ebp
// 006bf98c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006bf990  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006bf994  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006bf998  741d                 je 0x6bf9b7
// 006bf99a  8d4c2420             lea ecx, [esp + 0x20]
// 006bf99e  e8fd40ffff           call 0x6b3aa0
// 006bf9a3  53                   push ebx
// 006bf9a4  57                   push edi
// 006bf9a5  8d442418             lea eax, [esp + 0x18]
// 006bf9a9  50                   push eax
// 006bf9aa  8bce                 mov ecx, esi
// 006bf9ac  e87fedffff           call 0x6be730
// 006bf9b1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006bf9b5  ebc9                 jmp 0x6bf980
// 006bf9b7  8b36                 mov esi, dword ptr [esi]
// 006bf9b9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006bf9bd  5f                   pop edi
// 006bf9be  8930                 mov dword ptr [eax], esi
// 006bf9c0  5e                   pop esi
// 006bf9c1  5d                   pop ebp
// 006bf9c2  895804               mov dword ptr [eax + 4], ebx
// 006bf9c5  5b                   pop ebx
// 006bf9c6  83c408               add esp, 8
// 006bf9c9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
