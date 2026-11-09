// from server: 100% by auto
// roc 2009-12 006b5510  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b5510
//
// 006b5510  83ec0c               sub esp, 0xc
// 006b5513  53                   push ebx
// 006b5514  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006b5518  55                   push ebp
// 006b5519  56                   push esi
// 006b551a  57                   push edi
// 006b551b  8bf9                 mov edi, ecx
// 006b551d  8b7718               mov esi, dword ptr [edi + 0x18]
// 006b5520  8b4604               mov eax, dword ptr [esi + 4]
// 006b5523  80781900             cmp byte ptr [eax + 0x19], 0
// 006b5527  b101                 mov cl, 1
// 006b5529  884c2410             mov byte ptr [esp + 0x10], cl
// 006b552d  751f                 jne 0x6b554e
// 006b552f  8b13                 mov edx, dword ptr [ebx]
// 006b5531  3b500c               cmp edx, dword ptr [eax + 0xc]
// 006b5534  8bf0                 mov esi, eax
// 006b5536  0f9cc1               setl cl
// 006b5539  884c2410             mov byte ptr [esp + 0x10], cl
// 006b553d  84c9                 test cl, cl
// 006b553f  7404                 je 0x6b5545
// 006b5541  8b00                 mov eax, dword ptr [eax]
// 006b5543  eb03                 jmp 0x6b5548
// 006b5545  8b4008               mov eax, dword ptr [eax + 8]
// 006b5548  80781900             cmp byte ptr [eax + 0x19], 0
// 006b554c  74e3                 je 0x6b5531
// 006b554e  8b17                 mov edx, dword ptr [edi]
// 006b5550  8bee                 mov ebp, esi
// 006b5552  896c2418             mov dword ptr [esp + 0x18], ebp
// 006b5556  89542414             mov dword ptr [esp + 0x14], edx
// 006b555a  84c9                 test cl, cl
// 006b555c  7452                 je 0x6b55b0
// 006b555e  8b4718               mov eax, dword ptr [edi + 0x18]
// 006b5561  8b28                 mov ebp, dword ptr [eax]
// 006b5563  85d2                 test edx, edx
// 006b5565  7404                 je 0x6b556b
// 006b5567  3bd2                 cmp edx, edx
// 006b5569  7406                 je 0x6b5571
// 006b556b  ff1560b79800         call dword ptr [0x98b760]
// 006b5571  8d4c2414             lea ecx, [esp + 0x14]
// 006b5575  3bf5                 cmp esi, ebp
// 006b5577  752a                 jne 0x6b55a3
// 006b5579  53                   push ebx
// 006b557a  56                   push esi
// 006b557b  6a01                 push 1
// 006b557d  51                   push ecx
// 006b557e  8bcf                 mov ecx, edi
// 006b5580  e86b72e8ff           call 0x53c7f0
// 006b5585  5f                   pop edi
// 006b5586  8bc8                 mov ecx, eax
// 006b5588  8b11                 mov edx, dword ptr [ecx]
// 006b558a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006b558e  8b4904               mov ecx, dword ptr [ecx + 4]
// 006b5591  5e                   pop esi
// 006b5592  5d                   pop ebp
// 006b5593  894804               mov dword ptr [eax + 4], ecx
// 006b5596  c6400801             mov byte ptr [eax + 8], 1
// 006b559a  8910                 mov dword ptr [eax], edx
// 006b559c  5b                   pop ebx
// 006b559d  83c40c               add esp, 0xc
// 006b55a0  c20800               ret 8
// 006b55a3  e80819fcff           call 0x676eb0
// 006b55a8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 006b55ac  8b542414             mov edx, dword ptr [esp + 0x14]
// 006b55b0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006b55b3  3b03                 cmp eax, dword ptr [ebx]
// 006b55b5  7d31                 jge 0x6b55e8
// 006b55b7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006b55bb  53                   push ebx
// 006b55bc  56                   push esi
// 006b55bd  51                   push ecx
// 006b55be  8d542420             lea edx, [esp + 0x20]
// 006b55c2  52                   push edx
// 006b55c3  8bcf                 mov ecx, edi
// 006b55c5  e82672e8ff           call 0x53c7f0
// 006b55ca  5f                   pop edi
// 006b55cb  8bc8                 mov ecx, eax
// 006b55cd  8b11                 mov edx, dword ptr [ecx]
// 006b55cf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006b55d3  8b4904               mov ecx, dword ptr [ecx + 4]
// 006b55d6  5e                   pop esi
// 006b55d7  5d                   pop ebp
// 006b55d8  894804               mov dword ptr [eax + 4], ecx
// 006b55db  c6400801             mov byte ptr [eax + 8], 1
// 006b55df  8910                 mov dword ptr [eax], edx
// 006b55e1  5b                   pop ebx
// 006b55e2  83c40c               add esp, 0xc
// 006b55e5  c20800               ret 8
// 006b55e8  8b442420             mov eax, dword ptr [esp + 0x20]
// 006b55ec  5f                   pop edi
// 006b55ed  5e                   pop esi
// 006b55ee  896804               mov dword ptr [eax + 4], ebp
// 006b55f1  5d                   pop ebp
// 006b55f2  c6400800             mov byte ptr [eax + 8], 0
// 006b55f6  8910                 mov dword ptr [eax], edx
// 006b55f8  5b                   pop ebx
// 006b55f9  83c40c               add esp, 0xc
// 006b55fc  c20800               ret 8
// standard library map_int<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
