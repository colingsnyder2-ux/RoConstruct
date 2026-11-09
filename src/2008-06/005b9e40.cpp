// from server: 100% by auto
// roc 2008-06 005b9e40  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b9e40
//
// 005b9e40  83ec0c               sub esp, 0xc
// 005b9e43  53                   push ebx
// 005b9e44  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 005b9e48  55                   push ebp
// 005b9e49  56                   push esi
// 005b9e4a  57                   push edi
// 005b9e4b  8bf9                 mov edi, ecx
// 005b9e4d  8b7718               mov esi, dword ptr [edi + 0x18]
// 005b9e50  8b4604               mov eax, dword ptr [esi + 4]
// 005b9e53  80781900             cmp byte ptr [eax + 0x19], 0
// 005b9e57  b101                 mov cl, 1
// 005b9e59  884c2410             mov byte ptr [esp + 0x10], cl
// 005b9e5d  751f                 jne 0x5b9e7e
// 005b9e5f  8b13                 mov edx, dword ptr [ebx]
// 005b9e61  3b500c               cmp edx, dword ptr [eax + 0xc]
// 005b9e64  8bf0                 mov esi, eax
// 005b9e66  0f9cc1               setl cl
// 005b9e69  884c2410             mov byte ptr [esp + 0x10], cl
// 005b9e6d  84c9                 test cl, cl
// 005b9e6f  7404                 je 0x5b9e75
// 005b9e71  8b00                 mov eax, dword ptr [eax]
// 005b9e73  eb03                 jmp 0x5b9e78
// 005b9e75  8b4008               mov eax, dword ptr [eax + 8]
// 005b9e78  80781900             cmp byte ptr [eax + 0x19], 0
// 005b9e7c  74e3                 je 0x5b9e61
// 005b9e7e  8b17                 mov edx, dword ptr [edi]
// 005b9e80  8bee                 mov ebp, esi
// 005b9e82  896c2418             mov dword ptr [esp + 0x18], ebp
// 005b9e86  89542414             mov dword ptr [esp + 0x14], edx
// 005b9e8a  84c9                 test cl, cl
// 005b9e8c  7452                 je 0x5b9ee0
// 005b9e8e  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b9e91  8b28                 mov ebp, dword ptr [eax]
// 005b9e93  85d2                 test edx, edx
// 005b9e95  7404                 je 0x5b9e9b
// 005b9e97  3bd2                 cmp edx, edx
// 005b9e99  7406                 je 0x5b9ea1
// 005b9e9b  ff1590288000         call dword ptr [0x802890]
// 005b9ea1  8d4c2414             lea ecx, [esp + 0x14]
// 005b9ea5  3bf5                 cmp esi, ebp
// 005b9ea7  752a                 jne 0x5b9ed3
// 005b9ea9  53                   push ebx
// 005b9eaa  56                   push esi
// 005b9eab  6a01                 push 1
// 005b9ead  51                   push ecx
// 005b9eae  8bcf                 mov ecx, edi
// 005b9eb0  e8bb44efff           call 0x4ae370
// 005b9eb5  5f                   pop edi
// 005b9eb6  8bc8                 mov ecx, eax
// 005b9eb8  8b11                 mov edx, dword ptr [ecx]
// 005b9eba  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b9ebe  8b4904               mov ecx, dword ptr [ecx + 4]
// 005b9ec1  5e                   pop esi
// 005b9ec2  5d                   pop ebp
// 005b9ec3  894804               mov dword ptr [eax + 4], ecx
// 005b9ec6  c6400801             mov byte ptr [eax + 8], 1
// 005b9eca  8910                 mov dword ptr [eax], edx
// 005b9ecc  5b                   pop ebx
// 005b9ecd  83c40c               add esp, 0xc
// 005b9ed0  c20800               ret 8
// 005b9ed3  e86820efff           call 0x4abf40
// 005b9ed8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 005b9edc  8b542414             mov edx, dword ptr [esp + 0x14]
// 005b9ee0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005b9ee3  3b03                 cmp eax, dword ptr [ebx]
// 005b9ee5  7d31                 jge 0x5b9f18
// 005b9ee7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b9eeb  53                   push ebx
// 005b9eec  56                   push esi
// 005b9eed  51                   push ecx
// 005b9eee  8d542420             lea edx, [esp + 0x20]
// 005b9ef2  52                   push edx
// 005b9ef3  8bcf                 mov ecx, edi
// 005b9ef5  e87644efff           call 0x4ae370
// 005b9efa  5f                   pop edi
// 005b9efb  8bc8                 mov ecx, eax
// 005b9efd  8b11                 mov edx, dword ptr [ecx]
// 005b9eff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b9f03  8b4904               mov ecx, dword ptr [ecx + 4]
// 005b9f06  5e                   pop esi
// 005b9f07  5d                   pop ebp
// 005b9f08  894804               mov dword ptr [eax + 4], ecx
// 005b9f0b  c6400801             mov byte ptr [eax + 8], 1
// 005b9f0f  8910                 mov dword ptr [eax], edx
// 005b9f11  5b                   pop ebx
// 005b9f12  83c40c               add esp, 0xc
// 005b9f15  c20800               ret 8
// 005b9f18  8b442420             mov eax, dword ptr [esp + 0x20]
// 005b9f1c  5f                   pop edi
// 005b9f1d  5e                   pop esi
// 005b9f1e  896804               mov dword ptr [eax + 4], ebp
// 005b9f21  5d                   pop ebp
// 005b9f22  c6400800             mov byte ptr [eax + 8], 0
// 005b9f26  8910                 mov dword ptr [eax], edx
// 005b9f28  5b                   pop ebx
// 005b9f29  83c40c               add esp, 0xc
// 005b9f2c  c20800               ret 8
// standard library map_int<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
