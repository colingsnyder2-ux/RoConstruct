// from server: 100% by auto
// roc 2010-06 004ec140  unit: RBX::Network::DirectPhysicsReceiver  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ec140
//
// 004ec140  83ec0c               sub esp, 0xc
// 004ec143  53                   push ebx
// 004ec144  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004ec148  55                   push ebp
// 004ec149  56                   push esi
// 004ec14a  57                   push edi
// 004ec14b  8bf9                 mov edi, ecx
// 004ec14d  8b7718               mov esi, dword ptr [edi + 0x18]
// 004ec150  8b4604               mov eax, dword ptr [esi + 4]
// 004ec153  80781900             cmp byte ptr [eax + 0x19], 0
// 004ec157  b101                 mov cl, 1
// 004ec159  884c2410             mov byte ptr [esp + 0x10], cl
// 004ec15d  751f                 jne 0x4ec17e
// 004ec15f  8b13                 mov edx, dword ptr [ebx]
// 004ec161  3b500c               cmp edx, dword ptr [eax + 0xc]
// 004ec164  8bf0                 mov esi, eax
// 004ec166  0f92c1               setb cl
// 004ec169  884c2410             mov byte ptr [esp + 0x10], cl
// 004ec16d  84c9                 test cl, cl
// 004ec16f  7404                 je 0x4ec175
// 004ec171  8b00                 mov eax, dword ptr [eax]
// 004ec173  eb03                 jmp 0x4ec178
// 004ec175  8b4008               mov eax, dword ptr [eax + 8]
// 004ec178  80781900             cmp byte ptr [eax + 0x19], 0
// 004ec17c  74e3                 je 0x4ec161
// 004ec17e  8b17                 mov edx, dword ptr [edi]
// 004ec180  8bee                 mov ebp, esi
// 004ec182  896c2418             mov dword ptr [esp + 0x18], ebp
// 004ec186  89542414             mov dword ptr [esp + 0x14], edx
// 004ec18a  84c9                 test cl, cl
// 004ec18c  7452                 je 0x4ec1e0
// 004ec18e  8b4718               mov eax, dword ptr [edi + 0x18]
// 004ec191  8b28                 mov ebp, dword ptr [eax]
// 004ec193  85d2                 test edx, edx
// 004ec195  7404                 je 0x4ec19b
// 004ec197  3bd2                 cmp edx, edx
// 004ec199  7406                 je 0x4ec1a1
// 004ec19b  ff150ca99e00         call dword ptr [0x9ea90c]
// 004ec1a1  8d4c2414             lea ecx, [esp + 0x14]
// 004ec1a5  3bf5                 cmp esi, ebp
// 004ec1a7  752a                 jne 0x4ec1d3
// 004ec1a9  53                   push ebx
// 004ec1aa  56                   push esi
// 004ec1ab  6a01                 push 1
// 004ec1ad  51                   push ecx
// 004ec1ae  8bcf                 mov ecx, edi
// 004ec1b0  e83bebffff           call 0x4eacf0
// 004ec1b5  5f                   pop edi
// 004ec1b6  8bc8                 mov ecx, eax
// 004ec1b8  8b11                 mov edx, dword ptr [ecx]
// 004ec1ba  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ec1be  8b4904               mov ecx, dword ptr [ecx + 4]
// 004ec1c1  5e                   pop esi
// 004ec1c2  5d                   pop ebp
// 004ec1c3  894804               mov dword ptr [eax + 4], ecx
// 004ec1c6  c6400801             mov byte ptr [eax + 8], 1
// 004ec1ca  8910                 mov dword ptr [eax], edx
// 004ec1cc  5b                   pop ebx
// 004ec1cd  83c40c               add esp, 0xc
// 004ec1d0  c20800               ret 8
// 004ec1d3  e8e880f4ff           call 0x4342c0
// 004ec1d8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004ec1dc  8b542414             mov edx, dword ptr [esp + 0x14]
// 004ec1e0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004ec1e3  3b03                 cmp eax, dword ptr [ebx]
// 004ec1e5  7331                 jae 0x4ec218
// 004ec1e7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004ec1eb  53                   push ebx
// 004ec1ec  56                   push esi
// 004ec1ed  51                   push ecx
// 004ec1ee  8d542420             lea edx, [esp + 0x20]
// 004ec1f2  52                   push edx
// 004ec1f3  8bcf                 mov ecx, edi
// 004ec1f5  e8f6eaffff           call 0x4eacf0
// 004ec1fa  5f                   pop edi
// 004ec1fb  8bc8                 mov ecx, eax
// 004ec1fd  8b11                 mov edx, dword ptr [ecx]
// 004ec1ff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ec203  8b4904               mov ecx, dword ptr [ecx + 4]
// 004ec206  5e                   pop esi
// 004ec207  5d                   pop ebp
// 004ec208  894804               mov dword ptr [eax + 4], ecx
// 004ec20b  c6400801             mov byte ptr [eax + 8], 1
// 004ec20f  8910                 mov dword ptr [eax], edx
// 004ec211  5b                   pop ebx
// 004ec212  83c40c               add esp, 0xc
// 004ec215  c20800               ret 8
// 004ec218  8b442420             mov eax, dword ptr [esp + 0x20]
// 004ec21c  5f                   pop edi
// 004ec21d  5e                   pop esi
// 004ec21e  896804               mov dword ptr [eax + 4], ebp
// 004ec221  5d                   pop ebp
// 004ec222  c6400800             mov byte ptr [eax + 8], 0
// 004ec226  8910                 mov dword ptr [eax], edx
// 004ec228  5b                   pop ebx
// 004ec229  83c40c               add esp, 0xc
// 004ec22c  c20800               ret 8
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
