// from server: 100% by auto
// roc 2010-06 00441ac0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00441ac0
//
// 00441ac0  83ec0c               sub esp, 0xc
// 00441ac3  53                   push ebx
// 00441ac4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00441ac8  55                   push ebp
// 00441ac9  56                   push esi
// 00441aca  57                   push edi
// 00441acb  8bf9                 mov edi, ecx
// 00441acd  8b7718               mov esi, dword ptr [edi + 0x18]
// 00441ad0  8b4604               mov eax, dword ptr [esi + 4]
// 00441ad3  80782900             cmp byte ptr [eax + 0x29], 0
// 00441ad7  b101                 mov cl, 1
// 00441ad9  884c2410             mov byte ptr [esp + 0x10], cl
// 00441add  751f                 jne 0x441afe
// 00441adf  8b13                 mov edx, dword ptr [ebx]
// 00441ae1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00441ae4  8bf0                 mov esi, eax
// 00441ae6  0f92c1               setb cl
// 00441ae9  884c2410             mov byte ptr [esp + 0x10], cl
// 00441aed  84c9                 test cl, cl
// 00441aef  7404                 je 0x441af5
// 00441af1  8b00                 mov eax, dword ptr [eax]
// 00441af3  eb03                 jmp 0x441af8
// 00441af5  8b4008               mov eax, dword ptr [eax + 8]
// 00441af8  80782900             cmp byte ptr [eax + 0x29], 0
// 00441afc  74e3                 je 0x441ae1
// 00441afe  8b17                 mov edx, dword ptr [edi]
// 00441b00  8bee                 mov ebp, esi
// 00441b02  896c2418             mov dword ptr [esp + 0x18], ebp
// 00441b06  89542414             mov dword ptr [esp + 0x14], edx
// 00441b0a  84c9                 test cl, cl
// 00441b0c  7452                 je 0x441b60
// 00441b0e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00441b11  8b28                 mov ebp, dword ptr [eax]
// 00441b13  85d2                 test edx, edx
// 00441b15  7404                 je 0x441b1b
// 00441b17  3bd2                 cmp edx, edx
// 00441b19  7406                 je 0x441b21
// 00441b1b  ff150ca99e00         call dword ptr [0x9ea90c]
// 00441b21  8d4c2414             lea ecx, [esp + 0x14]
// 00441b25  3bf5                 cmp esi, ebp
// 00441b27  752a                 jne 0x441b53
// 00441b29  53                   push ebx
// 00441b2a  56                   push esi
// 00441b2b  6a01                 push 1
// 00441b2d  51                   push ecx
// 00441b2e  8bcf                 mov ecx, edi
// 00441b30  e8dbeaffff           call 0x440610
// 00441b35  5f                   pop edi
// 00441b36  8bc8                 mov ecx, eax
// 00441b38  8b11                 mov edx, dword ptr [ecx]
// 00441b3a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00441b3e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00441b41  5e                   pop esi
// 00441b42  5d                   pop ebp
// 00441b43  894804               mov dword ptr [eax + 4], ecx
// 00441b46  c6400801             mov byte ptr [eax + 8], 1
// 00441b4a  8910                 mov dword ptr [eax], edx
// 00441b4c  5b                   pop ebx
// 00441b4d  83c40c               add esp, 0xc
// 00441b50  c20800               ret 8
// 00441b53  e868bd2400           call 0x68d8c0
// 00441b58  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00441b5c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00441b60  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00441b63  3b03                 cmp eax, dword ptr [ebx]
// 00441b65  7331                 jae 0x441b98
// 00441b67  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00441b6b  53                   push ebx
// 00441b6c  56                   push esi
// 00441b6d  51                   push ecx
// 00441b6e  8d542420             lea edx, [esp + 0x20]
// 00441b72  52                   push edx
// 00441b73  8bcf                 mov ecx, edi
// 00441b75  e896eaffff           call 0x440610
// 00441b7a  5f                   pop edi
// 00441b7b  8bc8                 mov ecx, eax
// 00441b7d  8b11                 mov edx, dword ptr [ecx]
// 00441b7f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00441b83  8b4904               mov ecx, dword ptr [ecx + 4]
// 00441b86  5e                   pop esi
// 00441b87  5d                   pop ebp
// 00441b88  894804               mov dword ptr [eax + 4], ecx
// 00441b8b  c6400801             mov byte ptr [eax + 8], 1
// 00441b8f  8910                 mov dword ptr [eax], edx
// 00441b91  5b                   pop ebx
// 00441b92  83c40c               add esp, 0xc
// 00441b95  c20800               ret 8
// 00441b98  8b442420             mov eax, dword ptr [esp + 0x20]
// 00441b9c  5f                   pop edi
// 00441b9d  5e                   pop esi
// 00441b9e  896804               mov dword ptr [eax + 4], ebp
// 00441ba1  5d                   pop ebp
// 00441ba2  c6400800             mov byte ptr [eax + 8], 0
// 00441ba6  8910                 mov dword ptr [eax], edx
// 00441ba8  5b                   pop ebx
// 00441ba9  83c40c               add esp, 0xc
// 00441bac  c20800               ret 8
// standard library map_ptr<pod24> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod24>
struct E { int v[6]; };
#include <map>
struct K; template class std::map<K*, E>;
