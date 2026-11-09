// from server: 100% by auto
// roc 2010-06 00446600  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00446600
//
// 00446600  51                   push ecx
// 00446601  53                   push ebx
// 00446602  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00446606  55                   push ebp
// 00446607  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0044660d  56                   push esi
// 0044660e  8bf1                 mov esi, ecx
// 00446610  57                   push edi
// 00446611  c70300000000         mov dword ptr [ebx], 0
// 00446617  85f6                 test esi, esi
// 00446619  740e                 je 0x446629
// 0044661b  8b442420             mov eax, dword ptr [esp + 0x20]
// 0044661f  39460c               cmp dword ptr [esi + 0xc], eax
// 00446622  7705                 ja 0x446629
// 00446624  3b4610               cmp eax, dword ptr [esi + 0x10]
// 00446627  7606                 jbe 0x44662f
// 00446629  ffd5                 call ebp
// 0044662b  8b442420             mov eax, dword ptr [esp + 0x20]
// 0044662f  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00446633  8b0e                 mov ecx, dword ptr [esi]
// 00446635  890b                 mov dword ptr [ebx], ecx
// 00446637  894304               mov dword ptr [ebx + 4], eax
// 0044663a  397e0c               cmp dword ptr [esi + 0xc], edi
// 0044663d  7705                 ja 0x446644
// 0044663f  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00446642  7606                 jbe 0x44664a
// 00446644  ffd5                 call ebp
// 00446646  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0044664a  8b03                 mov eax, dword ptr [ebx]
// 0044664c  8b0e                 mov ecx, dword ptr [esi]
// 0044664e  85c0                 test eax, eax
// 00446650  7404                 je 0x446656
// 00446652  3bc1                 cmp eax, ecx
// 00446654  7402                 je 0x446658
// 00446656  ffd5                 call ebp
// 00446658  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0044665b  3bcf                 cmp ecx, edi
// 0044665d  744f                 je 0x4466ae
// 0044665f  8b4610               mov eax, dword ptr [esi + 0x10]
// 00446662  c644241000           mov byte ptr [esp + 0x10], 0
// 00446667  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044666b  52                   push edx
// 0044666c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00446670  52                   push edx
// 00446671  8b542420             mov edx, dword ptr [esp + 0x20]
// 00446675  52                   push edx
// 00446676  51                   push ecx
// 00446677  50                   push eax
// 00446678  57                   push edi
// 00446679  e842f0ffff           call 0x4456c0
// 0044667e  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 00446681  8bd8                 mov ebx, eax
// 00446683  83c418               add esp, 0x18
// 00446686  8bfb                 mov edi, ebx
// 00446688  3bdd                 cmp ebx, ebp
// 0044668a  7413                 je 0x44669f
// 0044668c  8d642400             lea esp, [esp]
// 00446690  8bcf                 mov ecx, edi
// 00446692  ff1500a49e00         call dword ptr [0x9ea400]
// 00446698  83c71c               add edi, 0x1c
// 0044669b  3bfd                 cmp edi, ebp
// 0044669d  75f1                 jne 0x446690
// 0044669f  8b442418             mov eax, dword ptr [esp + 0x18]
// 004466a3  5f                   pop edi
// 004466a4  895e10               mov dword ptr [esi + 0x10], ebx
// 004466a7  5e                   pop esi
// 004466a8  5d                   pop ebp
// 004466a9  5b                   pop ebx
// 004466aa  59                   pop ecx
// 004466ab  c21400               ret 0x14
// 004466ae  5f                   pop edi
// 004466af  5e                   pop esi
// 004466b0  5d                   pop ebp
// 004466b1  8bc3                 mov eax, ebx
// 004466b3  5b                   pop ebx
// 004466b4  59                   pop ecx
// 004466b5  c21400               ret 0x14
// standard library vector<string> (function ?erase@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Vector_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@V?$_Vector_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@0@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
