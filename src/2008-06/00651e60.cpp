// from server: 100% by auto
// roc 2008-06 00651e60  unit: RBX::ScoreHud  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00651e60
//
// 00651e60  83ec0c               sub esp, 0xc
// 00651e63  53                   push ebx
// 00651e64  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00651e68  55                   push ebp
// 00651e69  56                   push esi
// 00651e6a  57                   push edi
// 00651e6b  8bf9                 mov edi, ecx
// 00651e6d  8b7718               mov esi, dword ptr [edi + 0x18]
// 00651e70  8b4604               mov eax, dword ptr [esi + 4]
// 00651e73  80782900             cmp byte ptr [eax + 0x29], 0
// 00651e77  b101                 mov cl, 1
// 00651e79  884c2410             mov byte ptr [esp + 0x10], cl
// 00651e7d  751f                 jne 0x651e9e
// 00651e7f  8b13                 mov edx, dword ptr [ebx]
// 00651e81  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00651e84  8bf0                 mov esi, eax
// 00651e86  0f92c1               setb cl
// 00651e89  884c2410             mov byte ptr [esp + 0x10], cl
// 00651e8d  84c9                 test cl, cl
// 00651e8f  7404                 je 0x651e95
// 00651e91  8b00                 mov eax, dword ptr [eax]
// 00651e93  eb03                 jmp 0x651e98
// 00651e95  8b4008               mov eax, dword ptr [eax + 8]
// 00651e98  80782900             cmp byte ptr [eax + 0x29], 0
// 00651e9c  74e3                 je 0x651e81
// 00651e9e  8b17                 mov edx, dword ptr [edi]
// 00651ea0  8bee                 mov ebp, esi
// 00651ea2  896c2418             mov dword ptr [esp + 0x18], ebp
// 00651ea6  89542414             mov dword ptr [esp + 0x14], edx
// 00651eaa  84c9                 test cl, cl
// 00651eac  7452                 je 0x651f00
// 00651eae  8b4718               mov eax, dword ptr [edi + 0x18]
// 00651eb1  8b28                 mov ebp, dword ptr [eax]
// 00651eb3  85d2                 test edx, edx
// 00651eb5  7404                 je 0x651ebb
// 00651eb7  3bd2                 cmp edx, edx
// 00651eb9  7406                 je 0x651ec1
// 00651ebb  ff1590288000         call dword ptr [0x802890]
// 00651ec1  8d4c2414             lea ecx, [esp + 0x14]
// 00651ec5  3bf5                 cmp esi, ebp
// 00651ec7  752a                 jne 0x651ef3
// 00651ec9  53                   push ebx
// 00651eca  56                   push esi
// 00651ecb  6a01                 push 1
// 00651ecd  51                   push ecx
// 00651ece  8bcf                 mov ecx, edi
// 00651ed0  e86bfcffff           call 0x651b40
// 00651ed5  5f                   pop edi
// 00651ed6  8bc8                 mov ecx, eax
// 00651ed8  8b11                 mov edx, dword ptr [ecx]
// 00651eda  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00651ede  8b4904               mov ecx, dword ptr [ecx + 4]
// 00651ee1  5e                   pop esi
// 00651ee2  5d                   pop ebp
// 00651ee3  894804               mov dword ptr [eax + 4], ecx
// 00651ee6  c6400801             mov byte ptr [eax + 8], 1
// 00651eea  8910                 mov dword ptr [eax], edx
// 00651eec  5b                   pop ebx
// 00651eed  83c40c               add esp, 0xc
// 00651ef0  c20800               ret 8
// 00651ef3  e8e867deff           call 0x4386e0
// 00651ef8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00651efc  8b542414             mov edx, dword ptr [esp + 0x14]
// 00651f00  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00651f03  3b03                 cmp eax, dword ptr [ebx]
// 00651f05  7331                 jae 0x651f38
// 00651f07  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00651f0b  53                   push ebx
// 00651f0c  56                   push esi
// 00651f0d  51                   push ecx
// 00651f0e  8d542420             lea edx, [esp + 0x20]
// 00651f12  52                   push edx
// 00651f13  8bcf                 mov ecx, edi
// 00651f15  e826fcffff           call 0x651b40
// 00651f1a  5f                   pop edi
// 00651f1b  8bc8                 mov ecx, eax
// 00651f1d  8b11                 mov edx, dword ptr [ecx]
// 00651f1f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00651f23  8b4904               mov ecx, dword ptr [ecx + 4]
// 00651f26  5e                   pop esi
// 00651f27  5d                   pop ebp
// 00651f28  894804               mov dword ptr [eax + 4], ecx
// 00651f2b  c6400801             mov byte ptr [eax + 8], 1
// 00651f2f  8910                 mov dword ptr [eax], edx
// 00651f31  5b                   pop ebx
// 00651f32  83c40c               add esp, 0xc
// 00651f35  c20800               ret 8
// 00651f38  8b442420             mov eax, dword ptr [esp + 0x20]
// 00651f3c  5f                   pop edi
// 00651f3d  5e                   pop esi
// 00651f3e  896804               mov dword ptr [eax + 4], ebp
// 00651f41  5d                   pop ebp
// 00651f42  c6400800             mov byte ptr [eax + 8], 0
// 00651f46  8910                 mov dword ptr [eax], edx
// 00651f48  5b                   pop ebx
// 00651f49  83c40c               add esp, 0xc
// 00651f4c  c20800               ret 8
// standard library map_ptr<pod24> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod24>
struct E { int v[6]; };
#include <map>
struct K; template class std::map<K*, E>;
