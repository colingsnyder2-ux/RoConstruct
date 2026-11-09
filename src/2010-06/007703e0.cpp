// from server: 100% by auto
// roc 2010-06 007703e0  unit: RBX::ScoreHud  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007703e0
//
// 007703e0  83ec0c               sub esp, 0xc
// 007703e3  53                   push ebx
// 007703e4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007703e8  55                   push ebp
// 007703e9  56                   push esi
// 007703ea  57                   push edi
// 007703eb  8bf9                 mov edi, ecx
// 007703ed  8b7718               mov esi, dword ptr [edi + 0x18]
// 007703f0  8b4604               mov eax, dword ptr [esi + 4]
// 007703f3  80782900             cmp byte ptr [eax + 0x29], 0
// 007703f7  b101                 mov cl, 1
// 007703f9  884c2410             mov byte ptr [esp + 0x10], cl
// 007703fd  751f                 jne 0x77041e
// 007703ff  8b13                 mov edx, dword ptr [ebx]
// 00770401  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00770404  8bf0                 mov esi, eax
// 00770406  0f92c1               setb cl
// 00770409  884c2410             mov byte ptr [esp + 0x10], cl
// 0077040d  84c9                 test cl, cl
// 0077040f  7404                 je 0x770415
// 00770411  8b00                 mov eax, dword ptr [eax]
// 00770413  eb03                 jmp 0x770418
// 00770415  8b4008               mov eax, dword ptr [eax + 8]
// 00770418  80782900             cmp byte ptr [eax + 0x29], 0
// 0077041c  74e3                 je 0x770401
// 0077041e  8b17                 mov edx, dword ptr [edi]
// 00770420  8bee                 mov ebp, esi
// 00770422  896c2418             mov dword ptr [esp + 0x18], ebp
// 00770426  89542414             mov dword ptr [esp + 0x14], edx
// 0077042a  84c9                 test cl, cl
// 0077042c  7452                 je 0x770480
// 0077042e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00770431  8b28                 mov ebp, dword ptr [eax]
// 00770433  85d2                 test edx, edx
// 00770435  7404                 je 0x77043b
// 00770437  3bd2                 cmp edx, edx
// 00770439  7406                 je 0x770441
// 0077043b  ff150ca99e00         call dword ptr [0x9ea90c]
// 00770441  8d4c2414             lea ecx, [esp + 0x14]
// 00770445  3bf5                 cmp esi, ebp
// 00770447  752a                 jne 0x770473
// 00770449  53                   push ebx
// 0077044a  56                   push esi
// 0077044b  6a01                 push 1
// 0077044d  51                   push ecx
// 0077044e  8bcf                 mov ecx, edi
// 00770450  e83bfaffff           call 0x76fe90
// 00770455  5f                   pop edi
// 00770456  8bc8                 mov ecx, eax
// 00770458  8b11                 mov edx, dword ptr [ecx]
// 0077045a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0077045e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00770461  5e                   pop esi
// 00770462  5d                   pop ebp
// 00770463  894804               mov dword ptr [eax + 4], ecx
// 00770466  c6400801             mov byte ptr [eax + 8], 1
// 0077046a  8910                 mov dword ptr [eax], edx
// 0077046c  5b                   pop ebx
// 0077046d  83c40c               add esp, 0xc
// 00770470  c20800               ret 8
// 00770473  e848d4f1ff           call 0x68d8c0
// 00770478  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0077047c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00770480  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00770483  3b03                 cmp eax, dword ptr [ebx]
// 00770485  7331                 jae 0x7704b8
// 00770487  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0077048b  53                   push ebx
// 0077048c  56                   push esi
// 0077048d  51                   push ecx
// 0077048e  8d542420             lea edx, [esp + 0x20]
// 00770492  52                   push edx
// 00770493  8bcf                 mov ecx, edi
// 00770495  e8f6f9ffff           call 0x76fe90
// 0077049a  5f                   pop edi
// 0077049b  8bc8                 mov ecx, eax
// 0077049d  8b11                 mov edx, dword ptr [ecx]
// 0077049f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007704a3  8b4904               mov ecx, dword ptr [ecx + 4]
// 007704a6  5e                   pop esi
// 007704a7  5d                   pop ebp
// 007704a8  894804               mov dword ptr [eax + 4], ecx
// 007704ab  c6400801             mov byte ptr [eax + 8], 1
// 007704af  8910                 mov dword ptr [eax], edx
// 007704b1  5b                   pop ebx
// 007704b2  83c40c               add esp, 0xc
// 007704b5  c20800               ret 8
// 007704b8  8b442420             mov eax, dword ptr [esp + 0x20]
// 007704bc  5f                   pop edi
// 007704bd  5e                   pop esi
// 007704be  896804               mov dword ptr [eax + 4], ebp
// 007704c1  5d                   pop ebp
// 007704c2  c6400800             mov byte ptr [eax + 8], 0
// 007704c6  8910                 mov dword ptr [eax], edx
// 007704c8  5b                   pop ebx
// 007704c9  83c40c               add esp, 0xc
// 007704cc  c20800               ret 8
// standard library map_ptr<pod24> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod24>
struct E { int v[6]; };
#include <map>
struct K; template class std::map<K*, E>;
