// from server: 100% by auto
// roc 2010-06 004cd450  unit: RBX::Network::Players  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004cd450
//
// 004cd450  83ec0c               sub esp, 0xc
// 004cd453  53                   push ebx
// 004cd454  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004cd458  55                   push ebp
// 004cd459  56                   push esi
// 004cd45a  57                   push edi
// 004cd45b  8bf9                 mov edi, ecx
// 004cd45d  8b7718               mov esi, dword ptr [edi + 0x18]
// 004cd460  8b4604               mov eax, dword ptr [esi + 4]
// 004cd463  80783100             cmp byte ptr [eax + 0x31], 0
// 004cd467  b101                 mov cl, 1
// 004cd469  884c2410             mov byte ptr [esp + 0x10], cl
// 004cd46d  751f                 jne 0x4cd48e
// 004cd46f  8b13                 mov edx, dword ptr [ebx]
// 004cd471  3b500c               cmp edx, dword ptr [eax + 0xc]
// 004cd474  8bf0                 mov esi, eax
// 004cd476  0f9cc1               setl cl
// 004cd479  884c2410             mov byte ptr [esp + 0x10], cl
// 004cd47d  84c9                 test cl, cl
// 004cd47f  7404                 je 0x4cd485
// 004cd481  8b00                 mov eax, dword ptr [eax]
// 004cd483  eb03                 jmp 0x4cd488
// 004cd485  8b4008               mov eax, dword ptr [eax + 8]
// 004cd488  80783100             cmp byte ptr [eax + 0x31], 0
// 004cd48c  74e3                 je 0x4cd471
// 004cd48e  8b17                 mov edx, dword ptr [edi]
// 004cd490  8bee                 mov ebp, esi
// 004cd492  896c2418             mov dword ptr [esp + 0x18], ebp
// 004cd496  89542414             mov dword ptr [esp + 0x14], edx
// 004cd49a  84c9                 test cl, cl
// 004cd49c  7452                 je 0x4cd4f0
// 004cd49e  8b4718               mov eax, dword ptr [edi + 0x18]
// 004cd4a1  8b28                 mov ebp, dword ptr [eax]
// 004cd4a3  85d2                 test edx, edx
// 004cd4a5  7404                 je 0x4cd4ab
// 004cd4a7  3bd2                 cmp edx, edx
// 004cd4a9  7406                 je 0x4cd4b1
// 004cd4ab  ff150ca99e00         call dword ptr [0x9ea90c]
// 004cd4b1  8d4c2414             lea ecx, [esp + 0x14]
// 004cd4b5  3bf5                 cmp esi, ebp
// 004cd4b7  752a                 jne 0x4cd4e3
// 004cd4b9  53                   push ebx
// 004cd4ba  56                   push esi
// 004cd4bb  6a01                 push 1
// 004cd4bd  51                   push ecx
// 004cd4be  8bcf                 mov ecx, edi
// 004cd4c0  e85bf2ffff           call 0x4cc720
// 004cd4c5  5f                   pop edi
// 004cd4c6  8bc8                 mov ecx, eax
// 004cd4c8  8b11                 mov edx, dword ptr [ecx]
// 004cd4ca  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004cd4ce  8b4904               mov ecx, dword ptr [ecx + 4]
// 004cd4d1  5e                   pop esi
// 004cd4d2  5d                   pop ebp
// 004cd4d3  894804               mov dword ptr [eax + 4], ecx
// 004cd4d6  c6400801             mov byte ptr [eax + 8], 1
// 004cd4da  8910                 mov dword ptr [eax], edx
// 004cd4dc  5b                   pop ebx
// 004cd4dd  83c40c               add esp, 0xc
// 004cd4e0  c20800               ret 8
// 004cd4e3  e8f85ffaff           call 0x4734e0
// 004cd4e8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004cd4ec  8b542414             mov edx, dword ptr [esp + 0x14]
// 004cd4f0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004cd4f3  3b03                 cmp eax, dword ptr [ebx]
// 004cd4f5  7d31                 jge 0x4cd528
// 004cd4f7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004cd4fb  53                   push ebx
// 004cd4fc  56                   push esi
// 004cd4fd  51                   push ecx
// 004cd4fe  8d542420             lea edx, [esp + 0x20]
// 004cd502  52                   push edx
// 004cd503  8bcf                 mov ecx, edi
// 004cd505  e816f2ffff           call 0x4cc720
// 004cd50a  5f                   pop edi
// 004cd50b  8bc8                 mov ecx, eax
// 004cd50d  8b11                 mov edx, dword ptr [ecx]
// 004cd50f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004cd513  8b4904               mov ecx, dword ptr [ecx + 4]
// 004cd516  5e                   pop esi
// 004cd517  5d                   pop ebp
// 004cd518  894804               mov dword ptr [eax + 4], ecx
// 004cd51b  c6400801             mov byte ptr [eax + 8], 1
// 004cd51f  8910                 mov dword ptr [eax], edx
// 004cd521  5b                   pop ebx
// 004cd522  83c40c               add esp, 0xc
// 004cd525  c20800               ret 8
// 004cd528  8b442420             mov eax, dword ptr [esp + 0x20]
// 004cd52c  5f                   pop edi
// 004cd52d  5e                   pop esi
// 004cd52e  896804               mov dword ptr [eax + 4], ebp
// 004cd531  5d                   pop ebp
// 004cd532  c6400800             mov byte ptr [eax + 8], 0
// 004cd536  8910                 mov dword ptr [eax], edx
// 004cd538  5b                   pop ebx
// 004cd539  83c40c               add esp, 0xc
// 004cd53c  c20800               ret 8
// standard library map_int<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
