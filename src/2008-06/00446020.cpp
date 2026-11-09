// from server: 100% by auto
// roc 2008-06 00446020  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00446020
//
// 00446020  51                   push ecx
// 00446021  53                   push ebx
// 00446022  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00446026  55                   push ebp
// 00446027  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0044602d  56                   push esi
// 0044602e  8bf1                 mov esi, ecx
// 00446030  57                   push edi
// 00446031  c70300000000         mov dword ptr [ebx], 0
// 00446037  85f6                 test esi, esi
// 00446039  740e                 je 0x446049
// 0044603b  8b442420             mov eax, dword ptr [esp + 0x20]
// 0044603f  39460c               cmp dword ptr [esi + 0xc], eax
// 00446042  7705                 ja 0x446049
// 00446044  3b4610               cmp eax, dword ptr [esi + 0x10]
// 00446047  7606                 jbe 0x44604f
// 00446049  ffd5                 call ebp
// 0044604b  8b442420             mov eax, dword ptr [esp + 0x20]
// 0044604f  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00446053  8b0e                 mov ecx, dword ptr [esi]
// 00446055  890b                 mov dword ptr [ebx], ecx
// 00446057  894304               mov dword ptr [ebx + 4], eax
// 0044605a  397e0c               cmp dword ptr [esi + 0xc], edi
// 0044605d  7705                 ja 0x446064
// 0044605f  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00446062  7606                 jbe 0x44606a
// 00446064  ffd5                 call ebp
// 00446066  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0044606a  8b03                 mov eax, dword ptr [ebx]
// 0044606c  8b0e                 mov ecx, dword ptr [esi]
// 0044606e  85c0                 test eax, eax
// 00446070  7404                 je 0x446076
// 00446072  3bc1                 cmp eax, ecx
// 00446074  7402                 je 0x446078
// 00446076  ffd5                 call ebp
// 00446078  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0044607b  3bcf                 cmp ecx, edi
// 0044607d  744f                 je 0x4460ce
// 0044607f  8b4610               mov eax, dword ptr [esi + 0x10]
// 00446082  c644241000           mov byte ptr [esp + 0x10], 0
// 00446087  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044608b  52                   push edx
// 0044608c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00446090  52                   push edx
// 00446091  8b542420             mov edx, dword ptr [esp + 0x20]
// 00446095  52                   push edx
// 00446096  51                   push ecx
// 00446097  50                   push eax
// 00446098  57                   push edi
// 00446099  e872f2ffff           call 0x445310
// 0044609e  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 004460a1  8bd8                 mov ebx, eax
// 004460a3  83c418               add esp, 0x18
// 004460a6  8bfb                 mov edi, ebx
// 004460a8  3bdd                 cmp ebx, ebp
// 004460aa  7413                 je 0x4460bf
// 004460ac  8d642400             lea esp, [esp]
// 004460b0  8bcf                 mov ecx, edi
// 004460b2  ff1568248000         call dword ptr [0x802468]
// 004460b8  83c71c               add edi, 0x1c
// 004460bb  3bfd                 cmp edi, ebp
// 004460bd  75f1                 jne 0x4460b0
// 004460bf  8b442418             mov eax, dword ptr [esp + 0x18]
// 004460c3  5f                   pop edi
// 004460c4  895e10               mov dword ptr [esi + 0x10], ebx
// 004460c7  5e                   pop esi
// 004460c8  5d                   pop ebp
// 004460c9  5b                   pop ebx
// 004460ca  59                   pop ecx
// 004460cb  c21400               ret 0x14
// 004460ce  5f                   pop edi
// 004460cf  5e                   pop esi
// 004460d0  5d                   pop ebp
// 004460d1  8bc3                 mov eax, ebx
// 004460d3  5b                   pop ebx
// 004460d4  59                   pop ecx
// 004460d5  c21400               ret 0x14
// standard library vector<string> (function ?erase@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Vector_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@V?$_Vector_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@0@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
