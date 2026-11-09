// from server: 100% by auto
// roc 2009-06 00432fc0  unit: IIHAAH::?$CMap  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00432fc0
//
// 00432fc0  83ec0c               sub esp, 0xc
// 00432fc3  53                   push ebx
// 00432fc4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00432fc8  55                   push ebp
// 00432fc9  56                   push esi
// 00432fca  57                   push edi
// 00432fcb  8bf9                 mov edi, ecx
// 00432fcd  8b7718               mov esi, dword ptr [edi + 0x18]
// 00432fd0  8b4604               mov eax, dword ptr [esi + 4]
// 00432fd3  80781900             cmp byte ptr [eax + 0x19], 0
// 00432fd7  b101                 mov cl, 1
// 00432fd9  884c2410             mov byte ptr [esp + 0x10], cl
// 00432fdd  751f                 jne 0x432ffe
// 00432fdf  8b13                 mov edx, dword ptr [ebx]
// 00432fe1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00432fe4  8bf0                 mov esi, eax
// 00432fe6  0f92c1               setb cl
// 00432fe9  884c2410             mov byte ptr [esp + 0x10], cl
// 00432fed  84c9                 test cl, cl
// 00432fef  7404                 je 0x432ff5
// 00432ff1  8b00                 mov eax, dword ptr [eax]
// 00432ff3  eb03                 jmp 0x432ff8
// 00432ff5  8b4008               mov eax, dword ptr [eax + 8]
// 00432ff8  80781900             cmp byte ptr [eax + 0x19], 0
// 00432ffc  74e3                 je 0x432fe1
// 00432ffe  8b17                 mov edx, dword ptr [edi]
// 00433000  8bee                 mov ebp, esi
// 00433002  896c2418             mov dword ptr [esp + 0x18], ebp
// 00433006  89542414             mov dword ptr [esp + 0x14], edx
// 0043300a  84c9                 test cl, cl
// 0043300c  7452                 je 0x433060
// 0043300e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00433011  8b28                 mov ebp, dword ptr [eax]
// 00433013  85d2                 test edx, edx
// 00433015  7404                 je 0x43301b
// 00433017  3bd2                 cmp edx, edx
// 00433019  7406                 je 0x433021
// 0043301b  ff15ace98900         call dword ptr [0x89e9ac]
// 00433021  8d4c2414             lea ecx, [esp + 0x14]
// 00433025  3bf5                 cmp esi, ebp
// 00433027  752a                 jne 0x433053
// 00433029  53                   push ebx
// 0043302a  56                   push esi
// 0043302b  6a01                 push 1
// 0043302d  51                   push ecx
// 0043302e  8bcf                 mov ecx, edi
// 00433030  e86bfaffff           call 0x432aa0
// 00433035  5f                   pop edi
// 00433036  8bc8                 mov ecx, eax
// 00433038  8b11                 mov edx, dword ptr [ecx]
// 0043303a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0043303e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00433041  5e                   pop esi
// 00433042  5d                   pop ebp
// 00433043  894804               mov dword ptr [eax + 4], ecx
// 00433046  c6400801             mov byte ptr [eax + 8], 1
// 0043304a  8910                 mov dword ptr [eax], edx
// 0043304c  5b                   pop ebx
// 0043304d  83c40c               add esp, 0xc
// 00433050  c20800               ret 8
// 00433053  e8580e0b00           call 0x4e3eb0
// 00433058  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0043305c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00433060  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00433063  3b03                 cmp eax, dword ptr [ebx]
// 00433065  7331                 jae 0x433098
// 00433067  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043306b  53                   push ebx
// 0043306c  56                   push esi
// 0043306d  51                   push ecx
// 0043306e  8d542420             lea edx, [esp + 0x20]
// 00433072  52                   push edx
// 00433073  8bcf                 mov ecx, edi
// 00433075  e826faffff           call 0x432aa0
// 0043307a  5f                   pop edi
// 0043307b  8bc8                 mov ecx, eax
// 0043307d  8b11                 mov edx, dword ptr [ecx]
// 0043307f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00433083  8b4904               mov ecx, dword ptr [ecx + 4]
// 00433086  5e                   pop esi
// 00433087  5d                   pop ebp
// 00433088  894804               mov dword ptr [eax + 4], ecx
// 0043308b  c6400801             mov byte ptr [eax + 8], 1
// 0043308f  8910                 mov dword ptr [eax], edx
// 00433091  5b                   pop ebx
// 00433092  83c40c               add esp, 0xc
// 00433095  c20800               ret 8
// 00433098  8b442420             mov eax, dword ptr [esp + 0x20]
// 0043309c  5f                   pop edi
// 0043309d  5e                   pop esi
// 0043309e  896804               mov dword ptr [eax + 4], ebp
// 004330a1  5d                   pop ebp
// 004330a2  c6400800             mov byte ptr [eax + 8], 0
// 004330a6  8910                 mov dword ptr [eax], edx
// 004330a8  5b                   pop ebx
// 004330a9  83c40c               add esp, 0xc
// 004330ac  c20800               ret 8
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
