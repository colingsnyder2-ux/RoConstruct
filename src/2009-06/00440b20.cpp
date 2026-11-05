// from server: 100% by auto
// roc 2009-06 00440b20  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00440b20
//
// 00440b20  51                   push ecx
// 00440b21  53                   push ebx
// 00440b22  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00440b26  55                   push ebp
// 00440b27  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00440b2d  56                   push esi
// 00440b2e  8bf1                 mov esi, ecx
// 00440b30  57                   push edi
// 00440b31  c70300000000         mov dword ptr [ebx], 0
// 00440b37  85f6                 test esi, esi
// 00440b39  740e                 je 0x440b49
// 00440b3b  8b442420             mov eax, dword ptr [esp + 0x20]
// 00440b3f  39460c               cmp dword ptr [esi + 0xc], eax
// 00440b42  7705                 ja 0x440b49
// 00440b44  3b4610               cmp eax, dword ptr [esi + 0x10]
// 00440b47  7606                 jbe 0x440b4f
// 00440b49  ffd5                 call ebp
// 00440b4b  8b442420             mov eax, dword ptr [esp + 0x20]
// 00440b4f  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00440b53  8b0e                 mov ecx, dword ptr [esi]
// 00440b55  890b                 mov dword ptr [ebx], ecx
// 00440b57  894304               mov dword ptr [ebx + 4], eax
// 00440b5a  397e0c               cmp dword ptr [esi + 0xc], edi
// 00440b5d  7705                 ja 0x440b64
// 00440b5f  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00440b62  7606                 jbe 0x440b6a
// 00440b64  ffd5                 call ebp
// 00440b66  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00440b6a  8b03                 mov eax, dword ptr [ebx]
// 00440b6c  8b0e                 mov ecx, dword ptr [esi]
// 00440b6e  85c0                 test eax, eax
// 00440b70  7404                 je 0x440b76
// 00440b72  3bc1                 cmp eax, ecx
// 00440b74  7402                 je 0x440b78
// 00440b76  ffd5                 call ebp
// 00440b78  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00440b7b  3bcf                 cmp ecx, edi
// 00440b7d  744f                 je 0x440bce
// 00440b7f  8b4610               mov eax, dword ptr [esi + 0x10]
// 00440b82  c644241000           mov byte ptr [esp + 0x10], 0
// 00440b87  8b542410             mov edx, dword ptr [esp + 0x10]
// 00440b8b  52                   push edx
// 00440b8c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00440b90  52                   push edx
// 00440b91  8b542420             mov edx, dword ptr [esp + 0x20]
// 00440b95  52                   push edx
// 00440b96  51                   push ecx
// 00440b97  50                   push eax
// 00440b98  57                   push edi
// 00440b99  e842f0ffff           call 0x43fbe0
// 00440b9e  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 00440ba1  8bd8                 mov ebx, eax
// 00440ba3  83c418               add esp, 0x18
// 00440ba6  8bfb                 mov edi, ebx
// 00440ba8  3bdd                 cmp ebx, ebp
// 00440baa  7413                 je 0x440bbf
// 00440bac  8d642400             lea esp, [esp]
// 00440bb0  8bcf                 mov ecx, edi
// 00440bb2  ff15c4e48900         call dword ptr [0x89e4c4]
// 00440bb8  83c71c               add edi, 0x1c
// 00440bbb  3bfd                 cmp edi, ebp
// 00440bbd  75f1                 jne 0x440bb0
// 00440bbf  8b442418             mov eax, dword ptr [esp + 0x18]
// 00440bc3  5f                   pop edi
// 00440bc4  895e10               mov dword ptr [esi + 0x10], ebx
// 00440bc7  5e                   pop esi
// 00440bc8  5d                   pop ebp
// 00440bc9  5b                   pop ebx
// 00440bca  59                   pop ecx
// 00440bcb  c21400               ret 0x14
// 00440bce  5f                   pop edi
// 00440bcf  5e                   pop esi
// 00440bd0  5d                   pop ebp
// 00440bd1  8bc3                 mov eax, ebx
// 00440bd3  5b                   pop ebx
// 00440bd4  59                   pop ecx
// 00440bd5  c21400               ret 0x14
// standard library vector<string> (function ?erase@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Vector_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@V?$_Vector_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@0@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
