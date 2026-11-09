// from server: 100% by auto
// roc 2008-06 005b3a20  unit: RBX::VHat::?$FactoryProduct  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b3a20
//
// 005b3a20  83ec0c               sub esp, 0xc
// 005b3a23  53                   push ebx
// 005b3a24  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 005b3a28  55                   push ebp
// 005b3a29  56                   push esi
// 005b3a2a  57                   push edi
// 005b3a2b  8bf9                 mov edi, ecx
// 005b3a2d  8b7718               mov esi, dword ptr [edi + 0x18]
// 005b3a30  8b4604               mov eax, dword ptr [esi + 4]
// 005b3a33  80782100             cmp byte ptr [eax + 0x21], 0
// 005b3a37  b101                 mov cl, 1
// 005b3a39  884c2410             mov byte ptr [esp + 0x10], cl
// 005b3a3d  751f                 jne 0x5b3a5e
// 005b3a3f  8b13                 mov edx, dword ptr [ebx]
// 005b3a41  3b500c               cmp edx, dword ptr [eax + 0xc]
// 005b3a44  8bf0                 mov esi, eax
// 005b3a46  0f9cc1               setl cl
// 005b3a49  884c2410             mov byte ptr [esp + 0x10], cl
// 005b3a4d  84c9                 test cl, cl
// 005b3a4f  7404                 je 0x5b3a55
// 005b3a51  8b00                 mov eax, dword ptr [eax]
// 005b3a53  eb03                 jmp 0x5b3a58
// 005b3a55  8b4008               mov eax, dword ptr [eax + 8]
// 005b3a58  80782100             cmp byte ptr [eax + 0x21], 0
// 005b3a5c  74e3                 je 0x5b3a41
// 005b3a5e  8b17                 mov edx, dword ptr [edi]
// 005b3a60  8bee                 mov ebp, esi
// 005b3a62  896c2418             mov dword ptr [esp + 0x18], ebp
// 005b3a66  89542414             mov dword ptr [esp + 0x14], edx
// 005b3a6a  84c9                 test cl, cl
// 005b3a6c  7452                 je 0x5b3ac0
// 005b3a6e  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b3a71  8b28                 mov ebp, dword ptr [eax]
// 005b3a73  85d2                 test edx, edx
// 005b3a75  7404                 je 0x5b3a7b
// 005b3a77  3bd2                 cmp edx, edx
// 005b3a79  7406                 je 0x5b3a81
// 005b3a7b  ff1590288000         call dword ptr [0x802890]
// 005b3a81  8d4c2414             lea ecx, [esp + 0x14]
// 005b3a85  3bf5                 cmp esi, ebp
// 005b3a87  752a                 jne 0x5b3ab3
// 005b3a89  53                   push ebx
// 005b3a8a  56                   push esi
// 005b3a8b  6a01                 push 1
// 005b3a8d  51                   push ecx
// 005b3a8e  8bcf                 mov ecx, edi
// 005b3a90  e80bf6ffff           call 0x5b30a0
// 005b3a95  5f                   pop edi
// 005b3a96  8bc8                 mov ecx, eax
// 005b3a98  8b11                 mov edx, dword ptr [ecx]
// 005b3a9a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b3a9e  8b4904               mov ecx, dword ptr [ecx + 4]
// 005b3aa1  5e                   pop esi
// 005b3aa2  5d                   pop ebp
// 005b3aa3  894804               mov dword ptr [eax + 4], ecx
// 005b3aa6  c6400801             mov byte ptr [eax + 8], 1
// 005b3aaa  8910                 mov dword ptr [eax], edx
// 005b3aac  5b                   pop ebx
// 005b3aad  83c40c               add esp, 0xc
// 005b3ab0  c20800               ret 8
// 005b3ab3  e8b827f3ff           call 0x4e6270
// 005b3ab8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 005b3abc  8b542414             mov edx, dword ptr [esp + 0x14]
// 005b3ac0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005b3ac3  3b03                 cmp eax, dword ptr [ebx]
// 005b3ac5  7d31                 jge 0x5b3af8
// 005b3ac7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b3acb  53                   push ebx
// 005b3acc  56                   push esi
// 005b3acd  51                   push ecx
// 005b3ace  8d542420             lea edx, [esp + 0x20]
// 005b3ad2  52                   push edx
// 005b3ad3  8bcf                 mov ecx, edi
// 005b3ad5  e8c6f5ffff           call 0x5b30a0
// 005b3ada  5f                   pop edi
// 005b3adb  8bc8                 mov ecx, eax
// 005b3add  8b11                 mov edx, dword ptr [ecx]
// 005b3adf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b3ae3  8b4904               mov ecx, dword ptr [ecx + 4]
// 005b3ae6  5e                   pop esi
// 005b3ae7  5d                   pop ebp
// 005b3ae8  894804               mov dword ptr [eax + 4], ecx
// 005b3aeb  c6400801             mov byte ptr [eax + 8], 1
// 005b3aef  8910                 mov dword ptr [eax], edx
// 005b3af1  5b                   pop ebx
// 005b3af2  83c40c               add esp, 0xc
// 005b3af5  c20800               ret 8
// 005b3af8  8b442420             mov eax, dword ptr [esp + 0x20]
// 005b3afc  5f                   pop edi
// 005b3afd  5e                   pop esi
// 005b3afe  896804               mov dword ptr [eax + 4], ebp
// 005b3b01  5d                   pop ebp
// 005b3b02  c6400800             mov byte ptr [eax + 8], 0
// 005b3b06  8910                 mov dword ptr [eax], edx
// 005b3b08  5b                   pop ebx
// 005b3b09  83c40c               add esp, 0xc
// 005b3b0c  c20800               ret 8
// standard library map_int<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
