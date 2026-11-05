// from server: 100% by auto
// roc 2009-06 00618e70  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00618e70
//
// 00618e70  83ec0c               sub esp, 0xc
// 00618e73  53                   push ebx
// 00618e74  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00618e78  55                   push ebp
// 00618e79  56                   push esi
// 00618e7a  57                   push edi
// 00618e7b  8bf9                 mov edi, ecx
// 00618e7d  8b7718               mov esi, dword ptr [edi + 0x18]
// 00618e80  8b4604               mov eax, dword ptr [esi + 4]
// 00618e83  80781900             cmp byte ptr [eax + 0x19], 0
// 00618e87  b101                 mov cl, 1
// 00618e89  884c2410             mov byte ptr [esp + 0x10], cl
// 00618e8d  751f                 jne 0x618eae
// 00618e8f  8b13                 mov edx, dword ptr [ebx]
// 00618e91  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00618e94  8bf0                 mov esi, eax
// 00618e96  0f92c1               setb cl
// 00618e99  884c2410             mov byte ptr [esp + 0x10], cl
// 00618e9d  84c9                 test cl, cl
// 00618e9f  7404                 je 0x618ea5
// 00618ea1  8b00                 mov eax, dword ptr [eax]
// 00618ea3  eb03                 jmp 0x618ea8
// 00618ea5  8b4008               mov eax, dword ptr [eax + 8]
// 00618ea8  80781900             cmp byte ptr [eax + 0x19], 0
// 00618eac  74e3                 je 0x618e91
// 00618eae  8b17                 mov edx, dword ptr [edi]
// 00618eb0  8bee                 mov ebp, esi
// 00618eb2  896c2418             mov dword ptr [esp + 0x18], ebp
// 00618eb6  89542414             mov dword ptr [esp + 0x14], edx
// 00618eba  84c9                 test cl, cl
// 00618ebc  7452                 je 0x618f10
// 00618ebe  8b4718               mov eax, dword ptr [edi + 0x18]
// 00618ec1  8b28                 mov ebp, dword ptr [eax]
// 00618ec3  85d2                 test edx, edx
// 00618ec5  7404                 je 0x618ecb
// 00618ec7  3bd2                 cmp edx, edx
// 00618ec9  7406                 je 0x618ed1
// 00618ecb  ff15ace98900         call dword ptr [0x89e9ac]
// 00618ed1  8d4c2414             lea ecx, [esp + 0x14]
// 00618ed5  3bf5                 cmp esi, ebp
// 00618ed7  752a                 jne 0x618f03
// 00618ed9  53                   push ebx
// 00618eda  56                   push esi
// 00618edb  6a01                 push 1
// 00618edd  51                   push ecx
// 00618ede  8bcf                 mov ecx, edi
// 00618ee0  e88bf9ffff           call 0x618870
// 00618ee5  5f                   pop edi
// 00618ee6  8bc8                 mov ecx, eax
// 00618ee8  8b11                 mov edx, dword ptr [ecx]
// 00618eea  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00618eee  8b4904               mov ecx, dword ptr [ecx + 4]
// 00618ef1  5e                   pop esi
// 00618ef2  5d                   pop ebp
// 00618ef3  894804               mov dword ptr [eax + 4], ecx
// 00618ef6  c6400801             mov byte ptr [eax + 8], 1
// 00618efa  8910                 mov dword ptr [eax], edx
// 00618efc  5b                   pop ebx
// 00618efd  83c40c               add esp, 0xc
// 00618f00  c20800               ret 8
// 00618f03  e8a8afecff           call 0x4e3eb0
// 00618f08  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00618f0c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00618f10  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00618f13  3b03                 cmp eax, dword ptr [ebx]
// 00618f15  7331                 jae 0x618f48
// 00618f17  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00618f1b  53                   push ebx
// 00618f1c  56                   push esi
// 00618f1d  51                   push ecx
// 00618f1e  8d542420             lea edx, [esp + 0x20]
// 00618f22  52                   push edx
// 00618f23  8bcf                 mov ecx, edi
// 00618f25  e846f9ffff           call 0x618870
// 00618f2a  5f                   pop edi
// 00618f2b  8bc8                 mov ecx, eax
// 00618f2d  8b11                 mov edx, dword ptr [ecx]
// 00618f2f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00618f33  8b4904               mov ecx, dword ptr [ecx + 4]
// 00618f36  5e                   pop esi
// 00618f37  5d                   pop ebp
// 00618f38  894804               mov dword ptr [eax + 4], ecx
// 00618f3b  c6400801             mov byte ptr [eax + 8], 1
// 00618f3f  8910                 mov dword ptr [eax], edx
// 00618f41  5b                   pop ebx
// 00618f42  83c40c               add esp, 0xc
// 00618f45  c20800               ret 8
// 00618f48  8b442420             mov eax, dword ptr [esp + 0x20]
// 00618f4c  5f                   pop edi
// 00618f4d  5e                   pop esi
// 00618f4e  896804               mov dword ptr [eax + 4], ebp
// 00618f51  5d                   pop ebp
// 00618f52  c6400800             mov byte ptr [eax + 8], 0
// 00618f56  8910                 mov dword ptr [eax], edx
// 00618f58  5b                   pop ebx
// 00618f59  83c40c               add esp, 0xc
// 00618f5c  c20800               ret 8
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
