// from server: 100% by auto
// roc 2010-06 004ebbd0  unit: RBX::Network::DirectPhysicsReceiver  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ebbd0
//
// 004ebbd0  83ec0c               sub esp, 0xc
// 004ebbd3  53                   push ebx
// 004ebbd4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004ebbd8  55                   push ebp
// 004ebbd9  56                   push esi
// 004ebbda  57                   push edi
// 004ebbdb  8bf9                 mov edi, ecx
// 004ebbdd  8b7718               mov esi, dword ptr [edi + 0x18]
// 004ebbe0  8b4604               mov eax, dword ptr [esi + 4]
// 004ebbe3  80783500             cmp byte ptr [eax + 0x35], 0
// 004ebbe7  b101                 mov cl, 1
// 004ebbe9  884c2410             mov byte ptr [esp + 0x10], cl
// 004ebbed  751f                 jne 0x4ebc0e
// 004ebbef  8b13                 mov edx, dword ptr [ebx]
// 004ebbf1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 004ebbf4  8bf0                 mov esi, eax
// 004ebbf6  0f92c1               setb cl
// 004ebbf9  884c2410             mov byte ptr [esp + 0x10], cl
// 004ebbfd  84c9                 test cl, cl
// 004ebbff  7404                 je 0x4ebc05
// 004ebc01  8b00                 mov eax, dword ptr [eax]
// 004ebc03  eb03                 jmp 0x4ebc08
// 004ebc05  8b4008               mov eax, dword ptr [eax + 8]
// 004ebc08  80783500             cmp byte ptr [eax + 0x35], 0
// 004ebc0c  74e3                 je 0x4ebbf1
// 004ebc0e  8b17                 mov edx, dword ptr [edi]
// 004ebc10  8bee                 mov ebp, esi
// 004ebc12  896c2418             mov dword ptr [esp + 0x18], ebp
// 004ebc16  89542414             mov dword ptr [esp + 0x14], edx
// 004ebc1a  84c9                 test cl, cl
// 004ebc1c  7452                 je 0x4ebc70
// 004ebc1e  8b4718               mov eax, dword ptr [edi + 0x18]
// 004ebc21  8b28                 mov ebp, dword ptr [eax]
// 004ebc23  85d2                 test edx, edx
// 004ebc25  7404                 je 0x4ebc2b
// 004ebc27  3bd2                 cmp edx, edx
// 004ebc29  7406                 je 0x4ebc31
// 004ebc2b  ff150ca99e00         call dword ptr [0x9ea90c]
// 004ebc31  8d4c2414             lea ecx, [esp + 0x14]
// 004ebc35  3bf5                 cmp esi, ebp
// 004ebc37  752a                 jne 0x4ebc63
// 004ebc39  53                   push ebx
// 004ebc3a  56                   push esi
// 004ebc3b  6a01                 push 1
// 004ebc3d  51                   push ecx
// 004ebc3e  8bcf                 mov ecx, edi
// 004ebc40  e8abeeffff           call 0x4eaaf0
// 004ebc45  5f                   pop edi
// 004ebc46  8bc8                 mov ecx, eax
// 004ebc48  8b11                 mov edx, dword ptr [ecx]
// 004ebc4a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ebc4e  8b4904               mov ecx, dword ptr [ecx + 4]
// 004ebc51  5e                   pop esi
// 004ebc52  5d                   pop ebp
// 004ebc53  894804               mov dword ptr [eax + 4], ecx
// 004ebc56  c6400801             mov byte ptr [eax + 8], 1
// 004ebc5a  8910                 mov dword ptr [eax], edx
// 004ebc5c  5b                   pop ebx
// 004ebc5d  83c40c               add esp, 0xc
// 004ebc60  c20800               ret 8
// 004ebc63  e8383f1500           call 0x63fba0
// 004ebc68  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004ebc6c  8b542414             mov edx, dword ptr [esp + 0x14]
// 004ebc70  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004ebc73  3b03                 cmp eax, dword ptr [ebx]
// 004ebc75  7331                 jae 0x4ebca8
// 004ebc77  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004ebc7b  53                   push ebx
// 004ebc7c  56                   push esi
// 004ebc7d  51                   push ecx
// 004ebc7e  8d542420             lea edx, [esp + 0x20]
// 004ebc82  52                   push edx
// 004ebc83  8bcf                 mov ecx, edi
// 004ebc85  e866eeffff           call 0x4eaaf0
// 004ebc8a  5f                   pop edi
// 004ebc8b  8bc8                 mov ecx, eax
// 004ebc8d  8b11                 mov edx, dword ptr [ecx]
// 004ebc8f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ebc93  8b4904               mov ecx, dword ptr [ecx + 4]
// 004ebc96  5e                   pop esi
// 004ebc97  5d                   pop ebp
// 004ebc98  894804               mov dword ptr [eax + 4], ecx
// 004ebc9b  c6400801             mov byte ptr [eax + 8], 1
// 004ebc9f  8910                 mov dword ptr [eax], edx
// 004ebca1  5b                   pop ebx
// 004ebca2  83c40c               add esp, 0xc
// 004ebca5  c20800               ret 8
// 004ebca8  8b442420             mov eax, dword ptr [esp + 0x20]
// 004ebcac  5f                   pop edi
// 004ebcad  5e                   pop esi
// 004ebcae  896804               mov dword ptr [eax + 4], ebp
// 004ebcb1  5d                   pop ebp
// 004ebcb2  c6400800             mov byte ptr [eax + 8], 0
// 004ebcb6  8910                 mov dword ptr [eax], edx
// 004ebcb8  5b                   pop ebx
// 004ebcb9  83c40c               add esp, 0xc
// 004ebcbc  c20800               ret 8
// standard library map_ptr<pod36> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod36>
struct E { int v[9]; };
#include <map>
struct K; template class std::map<K*, E>;
