// from server: 100% by auto
// roc 2009-12 0051f520  unit: RBX::Network::Players  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0051f520
//
// 0051f520  83ec0c               sub esp, 0xc
// 0051f523  53                   push ebx
// 0051f524  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0051f528  55                   push ebp
// 0051f529  56                   push esi
// 0051f52a  57                   push edi
// 0051f52b  8bf9                 mov edi, ecx
// 0051f52d  8b7718               mov esi, dword ptr [edi + 0x18]
// 0051f530  8b4604               mov eax, dword ptr [esi + 4]
// 0051f533  80783100             cmp byte ptr [eax + 0x31], 0
// 0051f537  b101                 mov cl, 1
// 0051f539  884c2410             mov byte ptr [esp + 0x10], cl
// 0051f53d  751f                 jne 0x51f55e
// 0051f53f  8b13                 mov edx, dword ptr [ebx]
// 0051f541  3b500c               cmp edx, dword ptr [eax + 0xc]
// 0051f544  8bf0                 mov esi, eax
// 0051f546  0f9cc1               setl cl
// 0051f549  884c2410             mov byte ptr [esp + 0x10], cl
// 0051f54d  84c9                 test cl, cl
// 0051f54f  7404                 je 0x51f555
// 0051f551  8b00                 mov eax, dword ptr [eax]
// 0051f553  eb03                 jmp 0x51f558
// 0051f555  8b4008               mov eax, dword ptr [eax + 8]
// 0051f558  80783100             cmp byte ptr [eax + 0x31], 0
// 0051f55c  74e3                 je 0x51f541
// 0051f55e  8b17                 mov edx, dword ptr [edi]
// 0051f560  8bee                 mov ebp, esi
// 0051f562  896c2418             mov dword ptr [esp + 0x18], ebp
// 0051f566  89542414             mov dword ptr [esp + 0x14], edx
// 0051f56a  84c9                 test cl, cl
// 0051f56c  7452                 je 0x51f5c0
// 0051f56e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0051f571  8b28                 mov ebp, dword ptr [eax]
// 0051f573  85d2                 test edx, edx
// 0051f575  7404                 je 0x51f57b
// 0051f577  3bd2                 cmp edx, edx
// 0051f579  7406                 je 0x51f581
// 0051f57b  ff1560b79800         call dword ptr [0x98b760]
// 0051f581  8d4c2414             lea ecx, [esp + 0x14]
// 0051f585  3bf5                 cmp esi, ebp
// 0051f587  752a                 jne 0x51f5b3
// 0051f589  53                   push ebx
// 0051f58a  56                   push esi
// 0051f58b  6a01                 push 1
// 0051f58d  51                   push ecx
// 0051f58e  8bcf                 mov ecx, edi
// 0051f590  e89bf3ffff           call 0x51e930
// 0051f595  5f                   pop edi
// 0051f596  8bc8                 mov ecx, eax
// 0051f598  8b11                 mov edx, dword ptr [ecx]
// 0051f59a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0051f59e  8b4904               mov ecx, dword ptr [ecx + 4]
// 0051f5a1  5e                   pop esi
// 0051f5a2  5d                   pop ebp
// 0051f5a3  894804               mov dword ptr [eax + 4], ecx
// 0051f5a6  c6400801             mov byte ptr [eax + 8], 1
// 0051f5aa  8910                 mov dword ptr [eax], edx
// 0051f5ac  5b                   pop ebx
// 0051f5ad  83c40c               add esp, 0xc
// 0051f5b0  c20800               ret 8
// 0051f5b3  e8a842ffff           call 0x513860
// 0051f5b8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0051f5bc  8b542414             mov edx, dword ptr [esp + 0x14]
// 0051f5c0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0051f5c3  3b03                 cmp eax, dword ptr [ebx]
// 0051f5c5  7d31                 jge 0x51f5f8
// 0051f5c7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0051f5cb  53                   push ebx
// 0051f5cc  56                   push esi
// 0051f5cd  51                   push ecx
// 0051f5ce  8d542420             lea edx, [esp + 0x20]
// 0051f5d2  52                   push edx
// 0051f5d3  8bcf                 mov ecx, edi
// 0051f5d5  e856f3ffff           call 0x51e930
// 0051f5da  5f                   pop edi
// 0051f5db  8bc8                 mov ecx, eax
// 0051f5dd  8b11                 mov edx, dword ptr [ecx]
// 0051f5df  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0051f5e3  8b4904               mov ecx, dword ptr [ecx + 4]
// 0051f5e6  5e                   pop esi
// 0051f5e7  5d                   pop ebp
// 0051f5e8  894804               mov dword ptr [eax + 4], ecx
// 0051f5eb  c6400801             mov byte ptr [eax + 8], 1
// 0051f5ef  8910                 mov dword ptr [eax], edx
// 0051f5f1  5b                   pop ebx
// 0051f5f2  83c40c               add esp, 0xc
// 0051f5f5  c20800               ret 8
// 0051f5f8  8b442420             mov eax, dword ptr [esp + 0x20]
// 0051f5fc  5f                   pop edi
// 0051f5fd  5e                   pop esi
// 0051f5fe  896804               mov dword ptr [eax + 4], ebp
// 0051f601  5d                   pop ebp
// 0051f602  c6400800             mov byte ptr [eax + 8], 0
// 0051f606  8910                 mov dword ptr [eax], edx
// 0051f608  5b                   pop ebx
// 0051f609  83c40c               add esp, 0xc
// 0051f60c  c20800               ret 8
// standard library map_int<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
