// from server: 100% by auto
// roc 2010-06 004de7f0  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004de7f0
//
// 004de7f0  83ec08               sub esp, 8
// 004de7f3  53                   push ebx
// 004de7f4  55                   push ebp
// 004de7f5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 004de7fb  56                   push esi
// 004de7fc  8bf1                 mov esi, ecx
// 004de7fe  8b4618               mov eax, dword ptr [esi + 0x18]
// 004de801  8b18                 mov ebx, dword ptr [eax]
// 004de803  8b06                 mov eax, dword ptr [esi]
// 004de805  57                   push edi
// 004de806  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004de80a  85ff                 test edi, edi
// 004de80c  7404                 je 0x4de812
// 004de80e  3bf8                 cmp edi, eax
// 004de810  7406                 je 0x4de818
// 004de812  ffd5                 call ebp
// 004de814  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004de818  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004de81c  7562                 jne 0x4de880
// 004de81e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004de822  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004de825  8b06                 mov eax, dword ptr [esi]
// 004de827  85c9                 test ecx, ecx
// 004de829  7404                 je 0x4de82f
// 004de82b  3bc8                 cmp ecx, eax
// 004de82d  7406                 je 0x4de835
// 004de82f  ffd5                 call ebp
// 004de831  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004de835  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004de839  7545                 jne 0x4de880
// 004de83b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004de83e  8b5104               mov edx, dword ptr [ecx + 4]
// 004de841  52                   push edx
// 004de842  8bce                 mov ecx, esi
// 004de844  e887f7ffff           call 0x4ddfd0
// 004de849  8b4618               mov eax, dword ptr [esi + 0x18]
// 004de84c  894004               mov dword ptr [eax + 4], eax
// 004de84f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004de852  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004de859  8900                 mov dword ptr [eax], eax
// 004de85b  8b4618               mov eax, dword ptr [esi + 0x18]
// 004de85e  894008               mov dword ptr [eax + 8], eax
// 004de861  8b4618               mov eax, dword ptr [esi + 0x18]
// 004de864  8b16                 mov edx, dword ptr [esi]
// 004de866  8b08                 mov ecx, dword ptr [eax]
// 004de868  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004de86c  5f                   pop edi
// 004de86d  5e                   pop esi
// 004de86e  5d                   pop ebp
// 004de86f  894804               mov dword ptr [eax + 4], ecx
// 004de872  8910                 mov dword ptr [eax], edx
// 004de874  5b                   pop ebx
// 004de875  83c408               add esp, 8
// 004de878  c21400               ret 0x14
// 004de87b  eb03                 jmp 0x4de880
// 004de87d  8d4900               lea ecx, [ecx]
// 004de880  85ff                 test edi, edi
// 004de882  7406                 je 0x4de88a
// 004de884  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004de888  7406                 je 0x4de890
// 004de88a  ffd5                 call ebp
// 004de88c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004de890  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004de894  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004de898  741d                 je 0x4de8b7
// 004de89a  8d4c2420             lea ecx, [esp + 0x20]
// 004de89e  e84df1ffff           call 0x4dd9f0
// 004de8a3  53                   push ebx
// 004de8a4  57                   push edi
// 004de8a5  8d442418             lea eax, [esp + 0x18]
// 004de8a9  50                   push eax
// 004de8aa  8bce                 mov ecx, esi
// 004de8ac  e8aff9ffff           call 0x4de260
// 004de8b1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004de8b5  ebc9                 jmp 0x4de880
// 004de8b7  8b36                 mov esi, dword ptr [esi]
// 004de8b9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004de8bd  5f                   pop edi
// 004de8be  8930                 mov dword ptr [eax], esi
// 004de8c0  5e                   pop esi
// 004de8c1  5d                   pop ebp
// 004de8c2  895804               mov dword ptr [eax + 4], ebx
// 004de8c5  5b                   pop ebx
// 004de8c6  83c408               add esp, 8
// 004de8c9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
