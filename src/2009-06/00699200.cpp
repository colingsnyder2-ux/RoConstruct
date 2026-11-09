// from server: 100% by auto
// roc 2009-06 00699200  unit: RBX::VVelocityMotor::?$FactoryProduct  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00699200
//
// 00699200  83ec0c               sub esp, 0xc
// 00699203  53                   push ebx
// 00699204  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00699208  55                   push ebp
// 00699209  56                   push esi
// 0069920a  57                   push edi
// 0069920b  8bf9                 mov edi, ecx
// 0069920d  8b7718               mov esi, dword ptr [edi + 0x18]
// 00699210  8b4604               mov eax, dword ptr [esi + 4]
// 00699213  80781500             cmp byte ptr [eax + 0x15], 0
// 00699217  b101                 mov cl, 1
// 00699219  884c2410             mov byte ptr [esp + 0x10], cl
// 0069921d  751f                 jne 0x69923e
// 0069921f  8b13                 mov edx, dword ptr [ebx]
// 00699221  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00699224  8bf0                 mov esi, eax
// 00699226  0f92c1               setb cl
// 00699229  884c2410             mov byte ptr [esp + 0x10], cl
// 0069922d  84c9                 test cl, cl
// 0069922f  7404                 je 0x699235
// 00699231  8b00                 mov eax, dword ptr [eax]
// 00699233  eb03                 jmp 0x699238
// 00699235  8b4008               mov eax, dword ptr [eax + 8]
// 00699238  80781500             cmp byte ptr [eax + 0x15], 0
// 0069923c  74e3                 je 0x699221
// 0069923e  8b17                 mov edx, dword ptr [edi]
// 00699240  8bee                 mov ebp, esi
// 00699242  896c2418             mov dword ptr [esp + 0x18], ebp
// 00699246  89542414             mov dword ptr [esp + 0x14], edx
// 0069924a  84c9                 test cl, cl
// 0069924c  7452                 je 0x6992a0
// 0069924e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00699251  8b28                 mov ebp, dword ptr [eax]
// 00699253  85d2                 test edx, edx
// 00699255  7404                 je 0x69925b
// 00699257  3bd2                 cmp edx, edx
// 00699259  7406                 je 0x699261
// 0069925b  ff15ace98900         call dword ptr [0x89e9ac]
// 00699261  8d4c2414             lea ecx, [esp + 0x14]
// 00699265  3bf5                 cmp esi, ebp
// 00699267  752a                 jne 0x699293
// 00699269  53                   push ebx
// 0069926a  56                   push esi
// 0069926b  6a01                 push 1
// 0069926d  51                   push ecx
// 0069926e  8bcf                 mov ecx, edi
// 00699270  e8abba0500           call 0x6f4d20
// 00699275  5f                   pop edi
// 00699276  8bc8                 mov ecx, eax
// 00699278  8b11                 mov edx, dword ptr [ecx]
// 0069927a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0069927e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00699281  5e                   pop esi
// 00699282  5d                   pop ebp
// 00699283  894804               mov dword ptr [eax + 4], ecx
// 00699286  c6400801             mov byte ptr [eax + 8], 1
// 0069928a  8910                 mov dword ptr [eax], edx
// 0069928c  5b                   pop ebx
// 0069928d  83c40c               add esp, 0xc
// 00699290  c20800               ret 8
// 00699293  e858c80000           call 0x6a5af0
// 00699298  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0069929c  8b542414             mov edx, dword ptr [esp + 0x14]
// 006992a0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006992a3  3b03                 cmp eax, dword ptr [ebx]
// 006992a5  7331                 jae 0x6992d8
// 006992a7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006992ab  53                   push ebx
// 006992ac  56                   push esi
// 006992ad  51                   push ecx
// 006992ae  8d542420             lea edx, [esp + 0x20]
// 006992b2  52                   push edx
// 006992b3  8bcf                 mov ecx, edi
// 006992b5  e866ba0500           call 0x6f4d20
// 006992ba  5f                   pop edi
// 006992bb  8bc8                 mov ecx, eax
// 006992bd  8b11                 mov edx, dword ptr [ecx]
// 006992bf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006992c3  8b4904               mov ecx, dword ptr [ecx + 4]
// 006992c6  5e                   pop esi
// 006992c7  5d                   pop ebp
// 006992c8  894804               mov dword ptr [eax + 4], ecx
// 006992cb  c6400801             mov byte ptr [eax + 8], 1
// 006992cf  8910                 mov dword ptr [eax], edx
// 006992d1  5b                   pop ebx
// 006992d2  83c40c               add esp, 0xc
// 006992d5  c20800               ret 8
// 006992d8  8b442420             mov eax, dword ptr [esp + 0x20]
// 006992dc  5f                   pop edi
// 006992dd  5e                   pop esi
// 006992de  896804               mov dword ptr [eax + 4], ebp
// 006992e1  5d                   pop ebp
// 006992e2  c6400800             mov byte ptr [eax + 8], 0
// 006992e6  8910                 mov dword ptr [eax], edx
// 006992e8  5b                   pop ebx
// 006992e9  83c40c               add esp, 0xc
// 006992ec  c20800               ret 8
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
