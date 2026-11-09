// from server: 100% by auto
// roc 2010-06 0061b9c0  unit: RBX::Accoutrement  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0061b9c0
//
// 0061b9c0  83ec0c               sub esp, 0xc
// 0061b9c3  53                   push ebx
// 0061b9c4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0061b9c8  55                   push ebp
// 0061b9c9  56                   push esi
// 0061b9ca  57                   push edi
// 0061b9cb  8bf9                 mov edi, ecx
// 0061b9cd  8b7718               mov esi, dword ptr [edi + 0x18]
// 0061b9d0  8b4604               mov eax, dword ptr [esi + 4]
// 0061b9d3  80782100             cmp byte ptr [eax + 0x21], 0
// 0061b9d7  b101                 mov cl, 1
// 0061b9d9  884c2410             mov byte ptr [esp + 0x10], cl
// 0061b9dd  751f                 jne 0x61b9fe
// 0061b9df  8b13                 mov edx, dword ptr [ebx]
// 0061b9e1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 0061b9e4  8bf0                 mov esi, eax
// 0061b9e6  0f9cc1               setl cl
// 0061b9e9  884c2410             mov byte ptr [esp + 0x10], cl
// 0061b9ed  84c9                 test cl, cl
// 0061b9ef  7404                 je 0x61b9f5
// 0061b9f1  8b00                 mov eax, dword ptr [eax]
// 0061b9f3  eb03                 jmp 0x61b9f8
// 0061b9f5  8b4008               mov eax, dword ptr [eax + 8]
// 0061b9f8  80782100             cmp byte ptr [eax + 0x21], 0
// 0061b9fc  74e3                 je 0x61b9e1
// 0061b9fe  8b17                 mov edx, dword ptr [edi]
// 0061ba00  8bee                 mov ebp, esi
// 0061ba02  896c2418             mov dword ptr [esp + 0x18], ebp
// 0061ba06  89542414             mov dword ptr [esp + 0x14], edx
// 0061ba0a  84c9                 test cl, cl
// 0061ba0c  7452                 je 0x61ba60
// 0061ba0e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061ba11  8b28                 mov ebp, dword ptr [eax]
// 0061ba13  85d2                 test edx, edx
// 0061ba15  7404                 je 0x61ba1b
// 0061ba17  3bd2                 cmp edx, edx
// 0061ba19  7406                 je 0x61ba21
// 0061ba1b  ff150ca99e00         call dword ptr [0x9ea90c]
// 0061ba21  8d4c2414             lea ecx, [esp + 0x14]
// 0061ba25  3bf5                 cmp esi, ebp
// 0061ba27  752a                 jne 0x61ba53
// 0061ba29  53                   push ebx
// 0061ba2a  56                   push esi
// 0061ba2b  6a01                 push 1
// 0061ba2d  51                   push ecx
// 0061ba2e  8bcf                 mov ecx, edi
// 0061ba30  e8dbf7ffff           call 0x61b210
// 0061ba35  5f                   pop edi
// 0061ba36  8bc8                 mov ecx, eax
// 0061ba38  8b11                 mov edx, dword ptr [ecx]
// 0061ba3a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061ba3e  8b4904               mov ecx, dword ptr [ecx + 4]
// 0061ba41  5e                   pop esi
// 0061ba42  5d                   pop ebp
// 0061ba43  894804               mov dword ptr [eax + 4], ecx
// 0061ba46  c6400801             mov byte ptr [eax + 8], 1
// 0061ba4a  8910                 mov dword ptr [eax], edx
// 0061ba4c  5b                   pop ebx
// 0061ba4d  83c40c               add esp, 0xc
// 0061ba50  c20800               ret 8
// 0061ba53  e8c815f1ff           call 0x52d020
// 0061ba58  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0061ba5c  8b542414             mov edx, dword ptr [esp + 0x14]
// 0061ba60  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0061ba63  3b03                 cmp eax, dword ptr [ebx]
// 0061ba65  7d31                 jge 0x61ba98
// 0061ba67  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0061ba6b  53                   push ebx
// 0061ba6c  56                   push esi
// 0061ba6d  51                   push ecx
// 0061ba6e  8d542420             lea edx, [esp + 0x20]
// 0061ba72  52                   push edx
// 0061ba73  8bcf                 mov ecx, edi
// 0061ba75  e896f7ffff           call 0x61b210
// 0061ba7a  5f                   pop edi
// 0061ba7b  8bc8                 mov ecx, eax
// 0061ba7d  8b11                 mov edx, dword ptr [ecx]
// 0061ba7f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061ba83  8b4904               mov ecx, dword ptr [ecx + 4]
// 0061ba86  5e                   pop esi
// 0061ba87  5d                   pop ebp
// 0061ba88  894804               mov dword ptr [eax + 4], ecx
// 0061ba8b  c6400801             mov byte ptr [eax + 8], 1
// 0061ba8f  8910                 mov dword ptr [eax], edx
// 0061ba91  5b                   pop ebx
// 0061ba92  83c40c               add esp, 0xc
// 0061ba95  c20800               ret 8
// 0061ba98  8b442420             mov eax, dword ptr [esp + 0x20]
// 0061ba9c  5f                   pop edi
// 0061ba9d  5e                   pop esi
// 0061ba9e  896804               mov dword ptr [eax + 4], ebp
// 0061baa1  5d                   pop ebp
// 0061baa2  c6400800             mov byte ptr [eax + 8], 0
// 0061baa6  8910                 mov dword ptr [eax], edx
// 0061baa8  5b                   pop ebx
// 0061baa9  83c40c               add esp, 0xc
// 0061baac  c20800               ret 8
// standard library map_int<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
