// from server: 100% by auto
// roc 2009-06 006e3140  unit: RBX::ScoreHud  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e3140
//
// 006e3140  83ec0c               sub esp, 0xc
// 006e3143  53                   push ebx
// 006e3144  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006e3148  55                   push ebp
// 006e3149  56                   push esi
// 006e314a  57                   push edi
// 006e314b  8bf9                 mov edi, ecx
// 006e314d  8b7718               mov esi, dword ptr [edi + 0x18]
// 006e3150  8b4604               mov eax, dword ptr [esi + 4]
// 006e3153  80782900             cmp byte ptr [eax + 0x29], 0
// 006e3157  b101                 mov cl, 1
// 006e3159  884c2410             mov byte ptr [esp + 0x10], cl
// 006e315d  751f                 jne 0x6e317e
// 006e315f  8b13                 mov edx, dword ptr [ebx]
// 006e3161  3b500c               cmp edx, dword ptr [eax + 0xc]
// 006e3164  8bf0                 mov esi, eax
// 006e3166  0f92c1               setb cl
// 006e3169  884c2410             mov byte ptr [esp + 0x10], cl
// 006e316d  84c9                 test cl, cl
// 006e316f  7404                 je 0x6e3175
// 006e3171  8b00                 mov eax, dword ptr [eax]
// 006e3173  eb03                 jmp 0x6e3178
// 006e3175  8b4008               mov eax, dword ptr [eax + 8]
// 006e3178  80782900             cmp byte ptr [eax + 0x29], 0
// 006e317c  74e3                 je 0x6e3161
// 006e317e  8b17                 mov edx, dword ptr [edi]
// 006e3180  8bee                 mov ebp, esi
// 006e3182  896c2418             mov dword ptr [esp + 0x18], ebp
// 006e3186  89542414             mov dword ptr [esp + 0x14], edx
// 006e318a  84c9                 test cl, cl
// 006e318c  7452                 je 0x6e31e0
// 006e318e  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e3191  8b28                 mov ebp, dword ptr [eax]
// 006e3193  85d2                 test edx, edx
// 006e3195  7404                 je 0x6e319b
// 006e3197  3bd2                 cmp edx, edx
// 006e3199  7406                 je 0x6e31a1
// 006e319b  ff15ace98900         call dword ptr [0x89e9ac]
// 006e31a1  8d4c2414             lea ecx, [esp + 0x14]
// 006e31a5  3bf5                 cmp esi, ebp
// 006e31a7  752a                 jne 0x6e31d3
// 006e31a9  53                   push ebx
// 006e31aa  56                   push esi
// 006e31ab  6a01                 push 1
// 006e31ad  51                   push ecx
// 006e31ae  8bcf                 mov ecx, edi
// 006e31b0  e83bfaffff           call 0x6e2bf0
// 006e31b5  5f                   pop edi
// 006e31b6  8bc8                 mov ecx, eax
// 006e31b8  8b11                 mov edx, dword ptr [ecx]
// 006e31ba  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006e31be  8b4904               mov ecx, dword ptr [ecx + 4]
// 006e31c1  5e                   pop esi
// 006e31c2  5d                   pop ebp
// 006e31c3  894804               mov dword ptr [eax + 4], ecx
// 006e31c6  c6400801             mov byte ptr [eax + 8], 1
// 006e31ca  8910                 mov dword ptr [eax], edx
// 006e31cc  5b                   pop ebx
// 006e31cd  83c40c               add esp, 0xc
// 006e31d0  c20800               ret 8
// 006e31d3  e82845e3ff           call 0x517700
// 006e31d8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 006e31dc  8b542414             mov edx, dword ptr [esp + 0x14]
// 006e31e0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006e31e3  3b03                 cmp eax, dword ptr [ebx]
// 006e31e5  7331                 jae 0x6e3218
// 006e31e7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006e31eb  53                   push ebx
// 006e31ec  56                   push esi
// 006e31ed  51                   push ecx
// 006e31ee  8d542420             lea edx, [esp + 0x20]
// 006e31f2  52                   push edx
// 006e31f3  8bcf                 mov ecx, edi
// 006e31f5  e8f6f9ffff           call 0x6e2bf0
// 006e31fa  5f                   pop edi
// 006e31fb  8bc8                 mov ecx, eax
// 006e31fd  8b11                 mov edx, dword ptr [ecx]
// 006e31ff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006e3203  8b4904               mov ecx, dword ptr [ecx + 4]
// 006e3206  5e                   pop esi
// 006e3207  5d                   pop ebp
// 006e3208  894804               mov dword ptr [eax + 4], ecx
// 006e320b  c6400801             mov byte ptr [eax + 8], 1
// 006e320f  8910                 mov dword ptr [eax], edx
// 006e3211  5b                   pop ebx
// 006e3212  83c40c               add esp, 0xc
// 006e3215  c20800               ret 8
// 006e3218  8b442420             mov eax, dword ptr [esp + 0x20]
// 006e321c  5f                   pop edi
// 006e321d  5e                   pop esi
// 006e321e  896804               mov dword ptr [eax + 4], ebp
// 006e3221  5d                   pop ebp
// 006e3222  c6400800             mov byte ptr [eax + 8], 0
// 006e3226  8910                 mov dword ptr [eax], edx
// 006e3228  5b                   pop ebx
// 006e3229  83c40c               add esp, 0xc
// 006e322c  c20800               ret 8
// standard library map_ptr<pod24> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod24>
struct E { int v[6]; };
#include <map>
struct K; template class std::map<K*, E>;
