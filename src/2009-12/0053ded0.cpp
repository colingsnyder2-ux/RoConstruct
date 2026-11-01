// from server: 100% by auto
// roc 2009-12 0053ded0  unit: RBX::Network::DirectPhysicsReceiver  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053ded0
//
// 0053ded0  83ec0c               sub esp, 0xc
// 0053ded3  53                   push ebx
// 0053ded4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0053ded8  55                   push ebp
// 0053ded9  56                   push esi
// 0053deda  57                   push edi
// 0053dedb  8bf9                 mov edi, ecx
// 0053dedd  8b7718               mov esi, dword ptr [edi + 0x18]
// 0053dee0  8b4604               mov eax, dword ptr [esi + 4]
// 0053dee3  80781900             cmp byte ptr [eax + 0x19], 0
// 0053dee7  b101                 mov cl, 1
// 0053dee9  884c2410             mov byte ptr [esp + 0x10], cl
// 0053deed  751f                 jne 0x53df0e
// 0053deef  8b13                 mov edx, dword ptr [ebx]
// 0053def1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 0053def4  8bf0                 mov esi, eax
// 0053def6  0f92c1               setb cl
// 0053def9  884c2410             mov byte ptr [esp + 0x10], cl
// 0053defd  84c9                 test cl, cl
// 0053deff  7404                 je 0x53df05
// 0053df01  8b00                 mov eax, dword ptr [eax]
// 0053df03  eb03                 jmp 0x53df08
// 0053df05  8b4008               mov eax, dword ptr [eax + 8]
// 0053df08  80781900             cmp byte ptr [eax + 0x19], 0
// 0053df0c  74e3                 je 0x53def1
// 0053df0e  8b17                 mov edx, dword ptr [edi]
// 0053df10  8bee                 mov ebp, esi
// 0053df12  896c2418             mov dword ptr [esp + 0x18], ebp
// 0053df16  89542414             mov dword ptr [esp + 0x14], edx
// 0053df1a  84c9                 test cl, cl
// 0053df1c  7452                 je 0x53df70
// 0053df1e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053df21  8b28                 mov ebp, dword ptr [eax]
// 0053df23  85d2                 test edx, edx
// 0053df25  7404                 je 0x53df2b
// 0053df27  3bd2                 cmp edx, edx
// 0053df29  7406                 je 0x53df31
// 0053df2b  ff1560b79800         call dword ptr [0x98b760]
// 0053df31  8d4c2414             lea ecx, [esp + 0x14]
// 0053df35  3bf5                 cmp esi, ebp
// 0053df37  752a                 jne 0x53df63
// 0053df39  53                   push ebx
// 0053df3a  56                   push esi
// 0053df3b  6a01                 push 1
// 0053df3d  51                   push ecx
// 0053df3e  8bcf                 mov ecx, edi
// 0053df40  e8abe8ffff           call 0x53c7f0
// 0053df45  5f                   pop edi
// 0053df46  8bc8                 mov ecx, eax
// 0053df48  8b11                 mov edx, dword ptr [ecx]
// 0053df4a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053df4e  8b4904               mov ecx, dword ptr [ecx + 4]
// 0053df51  5e                   pop esi
// 0053df52  5d                   pop ebp
// 0053df53  894804               mov dword ptr [eax + 4], ecx
// 0053df56  c6400801             mov byte ptr [eax + 8], 1
// 0053df5a  8910                 mov dword ptr [eax], edx
// 0053df5c  5b                   pop ebx
// 0053df5d  83c40c               add esp, 0xc
// 0053df60  c20800               ret 8
// 0053df63  e8488f1300           call 0x676eb0
// 0053df68  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0053df6c  8b542414             mov edx, dword ptr [esp + 0x14]
// 0053df70  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0053df73  3b03                 cmp eax, dword ptr [ebx]
// 0053df75  7331                 jae 0x53dfa8
// 0053df77  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0053df7b  53                   push ebx
// 0053df7c  56                   push esi
// 0053df7d  51                   push ecx
// 0053df7e  8d542420             lea edx, [esp + 0x20]
// 0053df82  52                   push edx
// 0053df83  8bcf                 mov ecx, edi
// 0053df85  e866e8ffff           call 0x53c7f0
// 0053df8a  5f                   pop edi
// 0053df8b  8bc8                 mov ecx, eax
// 0053df8d  8b11                 mov edx, dword ptr [ecx]
// 0053df8f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053df93  8b4904               mov ecx, dword ptr [ecx + 4]
// 0053df96  5e                   pop esi
// 0053df97  5d                   pop ebp
// 0053df98  894804               mov dword ptr [eax + 4], ecx
// 0053df9b  c6400801             mov byte ptr [eax + 8], 1
// 0053df9f  8910                 mov dword ptr [eax], edx
// 0053dfa1  5b                   pop ebx
// 0053dfa2  83c40c               add esp, 0xc
// 0053dfa5  c20800               ret 8
// 0053dfa8  8b442420             mov eax, dword ptr [esp + 0x20]
// 0053dfac  5f                   pop edi
// 0053dfad  5e                   pop esi
// 0053dfae  896804               mov dword ptr [eax + 4], ebp
// 0053dfb1  5d                   pop ebp
// 0053dfb2  c6400800             mov byte ptr [eax + 8], 0
// 0053dfb6  8910                 mov dword ptr [eax], edx
// 0053dfb8  5b                   pop ebx
// 0053dfb9  83c40c               add esp, 0xc
// 0053dfbc  c20800               ret 8
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
