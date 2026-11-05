// from server: 100% by auto
// roc 2009-12 006adbc0  unit: RBX::Accoutrement  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006adbc0
//
// 006adbc0  83ec0c               sub esp, 0xc
// 006adbc3  53                   push ebx
// 006adbc4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006adbc8  55                   push ebp
// 006adbc9  56                   push esi
// 006adbca  57                   push edi
// 006adbcb  8bf9                 mov edi, ecx
// 006adbcd  8b7718               mov esi, dword ptr [edi + 0x18]
// 006adbd0  8b4604               mov eax, dword ptr [esi + 4]
// 006adbd3  80782100             cmp byte ptr [eax + 0x21], 0
// 006adbd7  b101                 mov cl, 1
// 006adbd9  884c2410             mov byte ptr [esp + 0x10], cl
// 006adbdd  751f                 jne 0x6adbfe
// 006adbdf  8b13                 mov edx, dword ptr [ebx]
// 006adbe1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 006adbe4  8bf0                 mov esi, eax
// 006adbe6  0f9cc1               setl cl
// 006adbe9  884c2410             mov byte ptr [esp + 0x10], cl
// 006adbed  84c9                 test cl, cl
// 006adbef  7404                 je 0x6adbf5
// 006adbf1  8b00                 mov eax, dword ptr [eax]
// 006adbf3  eb03                 jmp 0x6adbf8
// 006adbf5  8b4008               mov eax, dword ptr [eax + 8]
// 006adbf8  80782100             cmp byte ptr [eax + 0x21], 0
// 006adbfc  74e3                 je 0x6adbe1
// 006adbfe  8b17                 mov edx, dword ptr [edi]
// 006adc00  8bee                 mov ebp, esi
// 006adc02  896c2418             mov dword ptr [esp + 0x18], ebp
// 006adc06  89542414             mov dword ptr [esp + 0x14], edx
// 006adc0a  84c9                 test cl, cl
// 006adc0c  7452                 je 0x6adc60
// 006adc0e  8b4718               mov eax, dword ptr [edi + 0x18]
// 006adc11  8b28                 mov ebp, dword ptr [eax]
// 006adc13  85d2                 test edx, edx
// 006adc15  7404                 je 0x6adc1b
// 006adc17  3bd2                 cmp edx, edx
// 006adc19  7406                 je 0x6adc21
// 006adc1b  ff1560b79800         call dword ptr [0x98b760]
// 006adc21  8d4c2414             lea ecx, [esp + 0x14]
// 006adc25  3bf5                 cmp esi, ebp
// 006adc27  752a                 jne 0x6adc53
// 006adc29  53                   push ebx
// 006adc2a  56                   push esi
// 006adc2b  6a01                 push 1
// 006adc2d  51                   push ecx
// 006adc2e  8bcf                 mov ecx, edi
// 006adc30  e8ebf8ffff           call 0x6ad520
// 006adc35  5f                   pop edi
// 006adc36  8bc8                 mov ecx, eax
// 006adc38  8b11                 mov edx, dword ptr [ecx]
// 006adc3a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006adc3e  8b4904               mov ecx, dword ptr [ecx + 4]
// 006adc41  5e                   pop esi
// 006adc42  5d                   pop ebp
// 006adc43  894804               mov dword ptr [eax + 4], ecx
// 006adc46  c6400801             mov byte ptr [eax + 8], 1
// 006adc4a  8910                 mov dword ptr [eax], edx
// 006adc4c  5b                   pop ebx
// 006adc4d  83c40c               add esp, 0xc
// 006adc50  c20800               ret 8
// 006adc53  e878f6f1ff           call 0x5cd2d0
// 006adc58  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 006adc5c  8b542414             mov edx, dword ptr [esp + 0x14]
// 006adc60  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006adc63  3b03                 cmp eax, dword ptr [ebx]
// 006adc65  7d31                 jge 0x6adc98
// 006adc67  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006adc6b  53                   push ebx
// 006adc6c  56                   push esi
// 006adc6d  51                   push ecx
// 006adc6e  8d542420             lea edx, [esp + 0x20]
// 006adc72  52                   push edx
// 006adc73  8bcf                 mov ecx, edi
// 006adc75  e8a6f8ffff           call 0x6ad520
// 006adc7a  5f                   pop edi
// 006adc7b  8bc8                 mov ecx, eax
// 006adc7d  8b11                 mov edx, dword ptr [ecx]
// 006adc7f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006adc83  8b4904               mov ecx, dword ptr [ecx + 4]
// 006adc86  5e                   pop esi
// 006adc87  5d                   pop ebp
// 006adc88  894804               mov dword ptr [eax + 4], ecx
// 006adc8b  c6400801             mov byte ptr [eax + 8], 1
// 006adc8f  8910                 mov dword ptr [eax], edx
// 006adc91  5b                   pop ebx
// 006adc92  83c40c               add esp, 0xc
// 006adc95  c20800               ret 8
// 006adc98  8b442420             mov eax, dword ptr [esp + 0x20]
// 006adc9c  5f                   pop edi
// 006adc9d  5e                   pop esi
// 006adc9e  896804               mov dword ptr [eax + 4], ebp
// 006adca1  5d                   pop ebp
// 006adca2  c6400800             mov byte ptr [eax + 8], 0
// 006adca6  8910                 mov dword ptr [eax], edx
// 006adca8  5b                   pop ebx
// 006adca9  83c40c               add esp, 0xc
// 006adcac  c20800               ret 8
// standard library map_int<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
