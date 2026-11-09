// from server: 100% by auto
// roc 2010-06 006612f0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006612f0
//
// 006612f0  83ec14               sub esp, 0x14
// 006612f3  56                   push esi
// 006612f4  8bf1                 mov esi, ecx
// 006612f6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 006612fa  57                   push edi
// 006612fb  7521                 jne 0x66131e
// 006612fd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00661301  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00661304  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00661308  50                   push eax
// 00661309  51                   push ecx
// 0066130a  6a01                 push 1
// 0066130c  57                   push edi
// 0066130d  8bce                 mov ecx, esi
// 0066130f  e83c41ddff           call 0x435450
// 00661314  8bc7                 mov eax, edi
// 00661316  5f                   pop edi
// 00661317  5e                   pop esi
// 00661318  83c414               add esp, 0x14
// 0066131b  c21000               ret 0x10
// 0066131e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00661322  8b5618               mov edx, dword ptr [esi + 0x18]
// 00661325  8b3a                 mov edi, dword ptr [edx]
// 00661327  8b06                 mov eax, dword ptr [esi]
// 00661329  53                   push ebx
// 0066132a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00661330  85c9                 test ecx, ecx
// 00661332  7404                 je 0x661338
// 00661334  3bc8                 cmp ecx, eax
// 00661336  7406                 je 0x66133e
// 00661338  ffd3                 call ebx
// 0066133a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0066133e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00661342  3bc7                 cmp eax, edi
// 00661344  752a                 jne 0x661370
// 00661346  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0066134a  8b0f                 mov ecx, dword ptr [edi]
// 0066134c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0066134f  0f8d4b010000         jge 0x6614a0
// 00661355  57                   push edi
// 00661356  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0066135a  50                   push eax
// 0066135b  6a01                 push 1
// 0066135d  57                   push edi
// 0066135e  8bce                 mov ecx, esi
// 00661360  e8eb40ddff           call 0x435450
// 00661365  5b                   pop ebx
// 00661366  8bc7                 mov eax, edi
// 00661368  5f                   pop edi
// 00661369  5e                   pop esi
// 0066136a  83c414               add esp, 0x14
// 0066136d  c21000               ret 0x10
// 00661370  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00661373  8b16                 mov edx, dword ptr [esi]
// 00661375  85c9                 test ecx, ecx
// 00661377  7404                 je 0x66137d
// 00661379  3bca                 cmp ecx, edx
// 0066137b  740a                 je 0x661387
// 0066137d  ffd3                 call ebx
// 0066137f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00661383  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00661387  3bc7                 cmp eax, edi
// 00661389  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0066138d  752c                 jne 0x6613bb
// 0066138f  8b5618               mov edx, dword ptr [esi + 0x18]
// 00661392  8b4208               mov eax, dword ptr [edx + 8]
// 00661395  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00661398  3b0f                 cmp ecx, dword ptr [edi]
// 0066139a  0f8d00010000         jge 0x6614a0
// 006613a0  57                   push edi
// 006613a1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006613a5  50                   push eax
// 006613a6  6a00                 push 0
// 006613a8  57                   push edi
// 006613a9  8bce                 mov ecx, esi
// 006613ab  e8a040ddff           call 0x435450
// 006613b0  5b                   pop ebx
// 006613b1  8bc7                 mov eax, edi
// 006613b3  5f                   pop edi
// 006613b4  5e                   pop esi
// 006613b5  83c414               add esp, 0x14
// 006613b8  c21000               ret 0x10
// 006613bb  8b17                 mov edx, dword ptr [edi]
// 006613bd  39500c               cmp dword ptr [eax + 0xc], edx
// 006613c0  7e63                 jle 0x661425
// 006613c2  894c240c             mov dword ptr [esp + 0xc], ecx
// 006613c6  8d4c240c             lea ecx, [esp + 0xc]
// 006613ca  89442410             mov dword ptr [esp + 0x10], eax
// 006613ce  e8ed2eddff           call 0x4342c0
// 006613d3  8b17                 mov edx, dword ptr [edi]
// 006613d5  8b442410             mov eax, dword ptr [esp + 0x10]
// 006613d9  39500c               cmp dword ptr [eax + 0xc], edx
// 006613dc  7d3c                 jge 0x66141a
// 006613de  8b5008               mov edx, dword ptr [eax + 8]
// 006613e1  807a1900             cmp byte ptr [edx + 0x19], 0
// 006613e5  57                   push edi
// 006613e6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006613ea  8bce                 mov ecx, esi
// 006613ec  7414                 je 0x661402
// 006613ee  50                   push eax
// 006613ef  6a00                 push 0
// 006613f1  57                   push edi
// 006613f2  e85940ddff           call 0x435450
// 006613f7  5b                   pop ebx
// 006613f8  8bc7                 mov eax, edi
// 006613fa  5f                   pop edi
// 006613fb  5e                   pop esi
// 006613fc  83c414               add esp, 0x14
// 006613ff  c21000               ret 0x10
// 00661402  8b442430             mov eax, dword ptr [esp + 0x30]
// 00661406  50                   push eax
// 00661407  6a01                 push 1
// 00661409  57                   push edi
// 0066140a  e84140ddff           call 0x435450
// 0066140f  5b                   pop ebx
// 00661410  8bc7                 mov eax, edi
// 00661412  5f                   pop edi
// 00661413  5e                   pop esi
// 00661414  83c414               add esp, 0x14
// 00661417  c21000               ret 0x10
// 0066141a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0066141e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00661422  39500c               cmp dword ptr [eax + 0xc], edx
// 00661425  7d79                 jge 0x6614a0
// 00661427  8b16                 mov edx, dword ptr [esi]
// 00661429  894c240c             mov dword ptr [esp + 0xc], ecx
// 0066142d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00661430  894c2418             mov dword ptr [esp + 0x18], ecx
// 00661434  8d4c240c             lea ecx, [esp + 0xc]
// 00661438  89442410             mov dword ptr [esp + 0x10], eax
// 0066143c  89542414             mov dword ptr [esp + 0x14], edx
// 00661440  e8eb55e8ff           call 0x4e6a30
// 00661445  8d442414             lea eax, [esp + 0x14]
// 00661449  50                   push eax
// 0066144a  8d4c2410             lea ecx, [esp + 0x10]
// 0066144e  e82d5be0ff           call 0x466f80
// 00661453  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00661457  84c0                 test al, al
// 00661459  7507                 jne 0x661462
// 0066145b  8b17                 mov edx, dword ptr [edi]
// 0066145d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00661460  7d3e                 jge 0x6614a0
// 00661462  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00661466  8b5008               mov edx, dword ptr [eax + 8]
// 00661469  807a1900             cmp byte ptr [edx + 0x19], 0
// 0066146d  57                   push edi
// 0066146e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00661472  7416                 je 0x66148a
// 00661474  50                   push eax
// 00661475  6a00                 push 0
// 00661477  57                   push edi
// 00661478  8bce                 mov ecx, esi
// 0066147a  e8d13fddff           call 0x435450
// 0066147f  5b                   pop ebx
// 00661480  8bc7                 mov eax, edi
// 00661482  5f                   pop edi
// 00661483  5e                   pop esi
// 00661484  83c414               add esp, 0x14
// 00661487  c21000               ret 0x10
// 0066148a  51                   push ecx
// 0066148b  6a01                 push 1
// 0066148d  57                   push edi
// 0066148e  8bce                 mov ecx, esi
// 00661490  e8bb3fddff           call 0x435450
// 00661495  5b                   pop ebx
// 00661496  8bc7                 mov eax, edi
// 00661498  5f                   pop edi
// 00661499  5e                   pop esi
// 0066149a  83c414               add esp, 0x14
// 0066149d  c21000               ret 0x10
// 006614a0  57                   push edi
// 006614a1  8d442418             lea eax, [esp + 0x18]
// 006614a5  50                   push eax
// 006614a6  8bce                 mov ecx, esi
// 006614a8  e8c3f4ffff           call 0x660970
// 006614ad  8b10                 mov edx, dword ptr [eax]
// 006614af  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006614b3  5b                   pop ebx
// 006614b4  8911                 mov dword ptr [ecx], edx
// 006614b6  8b4004               mov eax, dword ptr [eax + 4]
// 006614b9  5f                   pop edi
// 006614ba  894104               mov dword ptr [ecx + 4], eax
// 006614bd  8bc1                 mov eax, ecx
// 006614bf  5e                   pop esi
// 006614c0  83c414               add esp, 0x14
// 006614c3  c21000               ret 0x10
// standard library map_int<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
