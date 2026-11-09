// from server: 100% by auto
// roc 2009-12 007ed9c0  unit: W4_D3DFORMAT::?$EnumDesc  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007ed9c0
//
// 007ed9c0  83ec0c               sub esp, 0xc
// 007ed9c3  53                   push ebx
// 007ed9c4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007ed9c8  55                   push ebp
// 007ed9c9  56                   push esi
// 007ed9ca  57                   push edi
// 007ed9cb  8bf9                 mov edi, ecx
// 007ed9cd  8b7718               mov esi, dword ptr [edi + 0x18]
// 007ed9d0  8b4604               mov eax, dword ptr [esi + 4]
// 007ed9d3  80781500             cmp byte ptr [eax + 0x15], 0
// 007ed9d7  b101                 mov cl, 1
// 007ed9d9  884c2410             mov byte ptr [esp + 0x10], cl
// 007ed9dd  751f                 jne 0x7ed9fe
// 007ed9df  8b13                 mov edx, dword ptr [ebx]
// 007ed9e1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 007ed9e4  8bf0                 mov esi, eax
// 007ed9e6  0f92c1               setb cl
// 007ed9e9  884c2410             mov byte ptr [esp + 0x10], cl
// 007ed9ed  84c9                 test cl, cl
// 007ed9ef  7404                 je 0x7ed9f5
// 007ed9f1  8b00                 mov eax, dword ptr [eax]
// 007ed9f3  eb03                 jmp 0x7ed9f8
// 007ed9f5  8b4008               mov eax, dword ptr [eax + 8]
// 007ed9f8  80781500             cmp byte ptr [eax + 0x15], 0
// 007ed9fc  74e3                 je 0x7ed9e1
// 007ed9fe  8b17                 mov edx, dword ptr [edi]
// 007eda00  8bee                 mov ebp, esi
// 007eda02  896c2418             mov dword ptr [esp + 0x18], ebp
// 007eda06  89542414             mov dword ptr [esp + 0x14], edx
// 007eda0a  84c9                 test cl, cl
// 007eda0c  7452                 je 0x7eda60
// 007eda0e  8b4718               mov eax, dword ptr [edi + 0x18]
// 007eda11  8b28                 mov ebp, dword ptr [eax]
// 007eda13  85d2                 test edx, edx
// 007eda15  7404                 je 0x7eda1b
// 007eda17  3bd2                 cmp edx, edx
// 007eda19  7406                 je 0x7eda21
// 007eda1b  ff1560b79800         call dword ptr [0x98b760]
// 007eda21  8d4c2414             lea ecx, [esp + 0x14]
// 007eda25  3bf5                 cmp esi, ebp
// 007eda27  752a                 jne 0x7eda53
// 007eda29  53                   push ebx
// 007eda2a  56                   push esi
// 007eda2b  6a01                 push 1
// 007eda2d  51                   push ecx
// 007eda2e  8bcf                 mov ecx, edi
// 007eda30  e83bfdffff           call 0x7ed770
// 007eda35  5f                   pop edi
// 007eda36  8bc8                 mov ecx, eax
// 007eda38  8b11                 mov edx, dword ptr [ecx]
// 007eda3a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007eda3e  8b4904               mov ecx, dword ptr [ecx + 4]
// 007eda41  5e                   pop esi
// 007eda42  5d                   pop ebp
// 007eda43  894804               mov dword ptr [eax + 4], ecx
// 007eda46  c6400801             mov byte ptr [eax + 8], 1
// 007eda4a  8910                 mov dword ptr [eax], edx
// 007eda4c  5b                   pop ebx
// 007eda4d  83c40c               add esp, 0xc
// 007eda50  c20800               ret 8
// 007eda53  e8d867c5ff           call 0x444230
// 007eda58  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 007eda5c  8b542414             mov edx, dword ptr [esp + 0x14]
// 007eda60  8b450c               mov eax, dword ptr [ebp + 0xc]
// 007eda63  3b03                 cmp eax, dword ptr [ebx]
// 007eda65  7331                 jae 0x7eda98
// 007eda67  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007eda6b  53                   push ebx
// 007eda6c  56                   push esi
// 007eda6d  51                   push ecx
// 007eda6e  8d542420             lea edx, [esp + 0x20]
// 007eda72  52                   push edx
// 007eda73  8bcf                 mov ecx, edi
// 007eda75  e8f6fcffff           call 0x7ed770
// 007eda7a  5f                   pop edi
// 007eda7b  8bc8                 mov ecx, eax
// 007eda7d  8b11                 mov edx, dword ptr [ecx]
// 007eda7f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007eda83  8b4904               mov ecx, dword ptr [ecx + 4]
// 007eda86  5e                   pop esi
// 007eda87  5d                   pop ebp
// 007eda88  894804               mov dword ptr [eax + 4], ecx
// 007eda8b  c6400801             mov byte ptr [eax + 8], 1
// 007eda8f  8910                 mov dword ptr [eax], edx
// 007eda91  5b                   pop ebx
// 007eda92  83c40c               add esp, 0xc
// 007eda95  c20800               ret 8
// 007eda98  8b442420             mov eax, dword ptr [esp + 0x20]
// 007eda9c  5f                   pop edi
// 007eda9d  5e                   pop esi
// 007eda9e  896804               mov dword ptr [eax + 4], ebp
// 007edaa1  5d                   pop ebp
// 007edaa2  c6400800             mov byte ptr [eax + 8], 0
// 007edaa6  8910                 mov dword ptr [eax], edx
// 007edaa8  5b                   pop ebx
// 007edaa9  83c40c               add esp, 0xc
// 007edaac  c20800               ret 8
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
