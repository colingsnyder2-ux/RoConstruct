// from server: 100% by auto
// roc 2007-08 004a2b70  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a2b70
//
// 004a2b70  83ec0c               sub esp, 0xc
// 004a2b73  55                   push ebp
// 004a2b74  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004a2b78  56                   push esi
// 004a2b79  57                   push edi
// 004a2b7a  8bf9                 mov edi, ecx
// 004a2b7c  8b7704               mov esi, dword ptr [edi + 4]
// 004a2b7f  8b4604               mov eax, dword ptr [esi + 4]
// 004a2b82  80782100             cmp byte ptr [eax + 0x21], 0
// 004a2b86  b101                 mov cl, 1
// 004a2b88  884c240c             mov byte ptr [esp + 0xc], cl
// 004a2b8c  7520                 jne 0x4a2bae
// 004a2b8e  8b5500               mov edx, dword ptr [ebp]
// 004a2b91  3b500c               cmp edx, dword ptr [eax + 0xc]
// 004a2b94  8bf0                 mov esi, eax
// 004a2b96  0f9cc1               setl cl
// 004a2b99  84c9                 test cl, cl
// 004a2b9b  884c240c             mov byte ptr [esp + 0xc], cl
// 004a2b9f  7404                 je 0x4a2ba5
// 004a2ba1  8b00                 mov eax, dword ptr [eax]
// 004a2ba3  eb03                 jmp 0x4a2ba8
// 004a2ba5  8b4008               mov eax, dword ptr [eax + 8]
// 004a2ba8  80782100             cmp byte ptr [eax + 0x21], 0
// 004a2bac  74e3                 je 0x4a2b91
// 004a2bae  84c9                 test cl, cl
// 004a2bb0  8bd6                 mov edx, esi
// 004a2bb2  89542414             mov dword ptr [esp + 0x14], edx
// 004a2bb6  897c2410             mov dword ptr [esp + 0x10], edi
// 004a2bba  743d                 je 0x4a2bf9
// 004a2bbc  8b4704               mov eax, dword ptr [edi + 4]
// 004a2bbf  3b30                 cmp esi, dword ptr [eax]
// 004a2bc1  8d4c2410             lea ecx, [esp + 0x10]
// 004a2bc5  7529                 jne 0x4a2bf0
// 004a2bc7  55                   push ebp
// 004a2bc8  56                   push esi
// 004a2bc9  6a01                 push 1
// 004a2bcb  51                   push ecx
// 004a2bcc  8bcf                 mov ecx, edi
// 004a2bce  e8adfdffff           call 0x4a2980
// 004a2bd3  8bc8                 mov ecx, eax
// 004a2bd5  8b11                 mov edx, dword ptr [ecx]
// 004a2bd7  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a2bdb  8b4904               mov ecx, dword ptr [ecx + 4]
// 004a2bde  5f                   pop edi
// 004a2bdf  5e                   pop esi
// 004a2be0  8910                 mov dword ptr [eax], edx
// 004a2be2  894804               mov dword ptr [eax + 4], ecx
// 004a2be5  c6400801             mov byte ptr [eax + 8], 1
// 004a2be9  5d                   pop ebp
// 004a2bea  83c40c               add esp, 0xc
// 004a2bed  c20800               ret 8
// 004a2bf0  e8bbd7ffff           call 0x4a03b0
// 004a2bf5  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a2bf9  8b420c               mov eax, dword ptr [edx + 0xc]
// 004a2bfc  3b4500               cmp eax, dword ptr [ebp]
// 004a2bff  7d0e                 jge 0x4a2c0f
// 004a2c01  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004a2c05  55                   push ebp
// 004a2c06  56                   push esi
// 004a2c07  51                   push ecx
// 004a2c08  8d54241c             lea edx, [esp + 0x1c]
// 004a2c0c  52                   push edx
// 004a2c0d  ebbd                 jmp 0x4a2bcc
// 004a2c0f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a2c13  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a2c17  5f                   pop edi
// 004a2c18  5e                   pop esi
// 004a2c19  8908                 mov dword ptr [eax], ecx
// 004a2c1b  895004               mov dword ptr [eax + 4], edx
// 004a2c1e  c6400800             mov byte ptr [eax + 8], 0
// 004a2c22  5d                   pop ebp
// 004a2c23  83c40c               add esp, 0xc
// 004a2c26  c20800               ret 8
// standard library map_int<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
