// from server: 100% by auto
// roc 2010-06 00435d10  unit: CPropGrid::UpdateItemsJob  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00435d10
//
// 00435d10  83ec0c               sub esp, 0xc
// 00435d13  53                   push ebx
// 00435d14  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00435d18  55                   push ebp
// 00435d19  56                   push esi
// 00435d1a  57                   push edi
// 00435d1b  8bf9                 mov edi, ecx
// 00435d1d  8b7718               mov esi, dword ptr [edi + 0x18]
// 00435d20  8b4604               mov eax, dword ptr [esi + 4]
// 00435d23  80781900             cmp byte ptr [eax + 0x19], 0
// 00435d27  b101                 mov cl, 1
// 00435d29  884c2410             mov byte ptr [esp + 0x10], cl
// 00435d2d  751f                 jne 0x435d4e
// 00435d2f  8b13                 mov edx, dword ptr [ebx]
// 00435d31  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00435d34  8bf0                 mov esi, eax
// 00435d36  0f92c1               setb cl
// 00435d39  884c2410             mov byte ptr [esp + 0x10], cl
// 00435d3d  84c9                 test cl, cl
// 00435d3f  7404                 je 0x435d45
// 00435d41  8b00                 mov eax, dword ptr [eax]
// 00435d43  eb03                 jmp 0x435d48
// 00435d45  8b4008               mov eax, dword ptr [eax + 8]
// 00435d48  80781900             cmp byte ptr [eax + 0x19], 0
// 00435d4c  74e3                 je 0x435d31
// 00435d4e  8b17                 mov edx, dword ptr [edi]
// 00435d50  8bee                 mov ebp, esi
// 00435d52  896c2418             mov dword ptr [esp + 0x18], ebp
// 00435d56  89542414             mov dword ptr [esp + 0x14], edx
// 00435d5a  84c9                 test cl, cl
// 00435d5c  7452                 je 0x435db0
// 00435d5e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00435d61  8b28                 mov ebp, dword ptr [eax]
// 00435d63  85d2                 test edx, edx
// 00435d65  7404                 je 0x435d6b
// 00435d67  3bd2                 cmp edx, edx
// 00435d69  7406                 je 0x435d71
// 00435d6b  ff150ca99e00         call dword ptr [0x9ea90c]
// 00435d71  8d4c2414             lea ecx, [esp + 0x14]
// 00435d75  3bf5                 cmp esi, ebp
// 00435d77  752a                 jne 0x435da3
// 00435d79  53                   push ebx
// 00435d7a  56                   push esi
// 00435d7b  6a01                 push 1
// 00435d7d  51                   push ecx
// 00435d7e  8bcf                 mov ecx, edi
// 00435d80  e8cbf6ffff           call 0x435450
// 00435d85  5f                   pop edi
// 00435d86  8bc8                 mov ecx, eax
// 00435d88  8b11                 mov edx, dword ptr [ecx]
// 00435d8a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00435d8e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00435d91  5e                   pop esi
// 00435d92  5d                   pop ebp
// 00435d93  894804               mov dword ptr [eax + 4], ecx
// 00435d96  c6400801             mov byte ptr [eax + 8], 1
// 00435d9a  8910                 mov dword ptr [eax], edx
// 00435d9c  5b                   pop ebx
// 00435d9d  83c40c               add esp, 0xc
// 00435da0  c20800               ret 8
// 00435da3  e818e5ffff           call 0x4342c0
// 00435da8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00435dac  8b542414             mov edx, dword ptr [esp + 0x14]
// 00435db0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00435db3  3b03                 cmp eax, dword ptr [ebx]
// 00435db5  7331                 jae 0x435de8
// 00435db7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00435dbb  53                   push ebx
// 00435dbc  56                   push esi
// 00435dbd  51                   push ecx
// 00435dbe  8d542420             lea edx, [esp + 0x20]
// 00435dc2  52                   push edx
// 00435dc3  8bcf                 mov ecx, edi
// 00435dc5  e886f6ffff           call 0x435450
// 00435dca  5f                   pop edi
// 00435dcb  8bc8                 mov ecx, eax
// 00435dcd  8b11                 mov edx, dword ptr [ecx]
// 00435dcf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00435dd3  8b4904               mov ecx, dword ptr [ecx + 4]
// 00435dd6  5e                   pop esi
// 00435dd7  5d                   pop ebp
// 00435dd8  894804               mov dword ptr [eax + 4], ecx
// 00435ddb  c6400801             mov byte ptr [eax + 8], 1
// 00435ddf  8910                 mov dword ptr [eax], edx
// 00435de1  5b                   pop ebx
// 00435de2  83c40c               add esp, 0xc
// 00435de5  c20800               ret 8
// 00435de8  8b442420             mov eax, dword ptr [esp + 0x20]
// 00435dec  5f                   pop edi
// 00435ded  5e                   pop esi
// 00435dee  896804               mov dword ptr [eax + 4], ebp
// 00435df1  5d                   pop ebp
// 00435df2  c6400800             mov byte ptr [eax + 8], 0
// 00435df6  8910                 mov dword ptr [eax], edx
// 00435df8  5b                   pop ebx
// 00435df9  83c40c               add esp, 0xc
// 00435dfc  c20800               ret 8
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
