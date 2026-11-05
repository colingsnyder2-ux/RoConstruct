// from server: 100% by auto
// roc 2009-12 006f6e40  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f6e40
//
// 006f6e40  83ec14               sub esp, 0x14
// 006f6e43  56                   push esi
// 006f6e44  8bf1                 mov esi, ecx
// 006f6e46  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 006f6e4a  57                   push edi
// 006f6e4b  7521                 jne 0x6f6e6e
// 006f6e4d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006f6e51  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006f6e54  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f6e58  50                   push eax
// 006f6e59  51                   push ecx
// 006f6e5a  6a01                 push 1
// 006f6e5c  57                   push edi
// 006f6e5d  8bce                 mov ecx, esi
// 006f6e5f  e84cefffff           call 0x6f5db0
// 006f6e64  8bc7                 mov eax, edi
// 006f6e66  5f                   pop edi
// 006f6e67  5e                   pop esi
// 006f6e68  83c414               add esp, 0x14
// 006f6e6b  c21000               ret 0x10
// 006f6e6e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006f6e72  8b5618               mov edx, dword ptr [esi + 0x18]
// 006f6e75  8b3a                 mov edi, dword ptr [edx]
// 006f6e77  8b06                 mov eax, dword ptr [esi]
// 006f6e79  53                   push ebx
// 006f6e7a  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 006f6e80  85c9                 test ecx, ecx
// 006f6e82  7404                 je 0x6f6e88
// 006f6e84  3bc8                 cmp ecx, eax
// 006f6e86  7406                 je 0x6f6e8e
// 006f6e88  ffd3                 call ebx
// 006f6e8a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006f6e8e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006f6e92  3bc7                 cmp eax, edi
// 006f6e94  752a                 jne 0x6f6ec0
// 006f6e96  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006f6e9a  8b0f                 mov ecx, dword ptr [edi]
// 006f6e9c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 006f6e9f  0f8d4b010000         jge 0x6f6ff0
// 006f6ea5  57                   push edi
// 006f6ea6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006f6eaa  50                   push eax
// 006f6eab  6a01                 push 1
// 006f6ead  57                   push edi
// 006f6eae  8bce                 mov ecx, esi
// 006f6eb0  e8fbeeffff           call 0x6f5db0
// 006f6eb5  5b                   pop ebx
// 006f6eb6  8bc7                 mov eax, edi
// 006f6eb8  5f                   pop edi
// 006f6eb9  5e                   pop esi
// 006f6eba  83c414               add esp, 0x14
// 006f6ebd  c21000               ret 0x10
// 006f6ec0  8b7e18               mov edi, dword ptr [esi + 0x18]
// 006f6ec3  8b16                 mov edx, dword ptr [esi]
// 006f6ec5  85c9                 test ecx, ecx
// 006f6ec7  7404                 je 0x6f6ecd
// 006f6ec9  3bca                 cmp ecx, edx
// 006f6ecb  740a                 je 0x6f6ed7
// 006f6ecd  ffd3                 call ebx
// 006f6ecf  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006f6ed3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006f6ed7  3bc7                 cmp eax, edi
// 006f6ed9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006f6edd  752c                 jne 0x6f6f0b
// 006f6edf  8b5618               mov edx, dword ptr [esi + 0x18]
// 006f6ee2  8b4208               mov eax, dword ptr [edx + 8]
// 006f6ee5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 006f6ee8  3b0f                 cmp ecx, dword ptr [edi]
// 006f6eea  0f8d00010000         jge 0x6f6ff0
// 006f6ef0  57                   push edi
// 006f6ef1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006f6ef5  50                   push eax
// 006f6ef6  6a00                 push 0
// 006f6ef8  57                   push edi
// 006f6ef9  8bce                 mov ecx, esi
// 006f6efb  e8b0eeffff           call 0x6f5db0
// 006f6f00  5b                   pop ebx
// 006f6f01  8bc7                 mov eax, edi
// 006f6f03  5f                   pop edi
// 006f6f04  5e                   pop esi
// 006f6f05  83c414               add esp, 0x14
// 006f6f08  c21000               ret 0x10
// 006f6f0b  8b17                 mov edx, dword ptr [edi]
// 006f6f0d  39500c               cmp dword ptr [eax + 0xc], edx
// 006f6f10  7e63                 jle 0x6f6f75
// 006f6f12  894c240c             mov dword ptr [esp + 0xc], ecx
// 006f6f16  8d4c240c             lea ecx, [esp + 0xc]
// 006f6f1a  89442410             mov dword ptr [esp + 0x10], eax
// 006f6f1e  e88dfff7ff           call 0x676eb0
// 006f6f23  8b17                 mov edx, dword ptr [edi]
// 006f6f25  8b442410             mov eax, dword ptr [esp + 0x10]
// 006f6f29  39500c               cmp dword ptr [eax + 0xc], edx
// 006f6f2c  7d3c                 jge 0x6f6f6a
// 006f6f2e  8b5008               mov edx, dword ptr [eax + 8]
// 006f6f31  807a1900             cmp byte ptr [edx + 0x19], 0
// 006f6f35  57                   push edi
// 006f6f36  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006f6f3a  8bce                 mov ecx, esi
// 006f6f3c  7414                 je 0x6f6f52
// 006f6f3e  50                   push eax
// 006f6f3f  6a00                 push 0
// 006f6f41  57                   push edi
// 006f6f42  e869eeffff           call 0x6f5db0
// 006f6f47  5b                   pop ebx
// 006f6f48  8bc7                 mov eax, edi
// 006f6f4a  5f                   pop edi
// 006f6f4b  5e                   pop esi
// 006f6f4c  83c414               add esp, 0x14
// 006f6f4f  c21000               ret 0x10
// 006f6f52  8b442430             mov eax, dword ptr [esp + 0x30]
// 006f6f56  50                   push eax
// 006f6f57  6a01                 push 1
// 006f6f59  57                   push edi
// 006f6f5a  e851eeffff           call 0x6f5db0
// 006f6f5f  5b                   pop ebx
// 006f6f60  8bc7                 mov eax, edi
// 006f6f62  5f                   pop edi
// 006f6f63  5e                   pop esi
// 006f6f64  83c414               add esp, 0x14
// 006f6f67  c21000               ret 0x10
// 006f6f6a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006f6f6e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006f6f72  39500c               cmp dword ptr [eax + 0xc], edx
// 006f6f75  7d79                 jge 0x6f6ff0
// 006f6f77  8b16                 mov edx, dword ptr [esi]
// 006f6f79  894c240c             mov dword ptr [esp + 0xc], ecx
// 006f6f7d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006f6f80  894c2418             mov dword ptr [esp + 0x18], ecx
// 006f6f84  8d4c240c             lea ecx, [esp + 0xc]
// 006f6f88  89442410             mov dword ptr [esp + 0x10], eax
// 006f6f8c  89542414             mov dword ptr [esp + 0x14], edx
// 006f6f90  e8eb15e4ff           call 0x538580
// 006f6f95  8d442414             lea eax, [esp + 0x14]
// 006f6f99  50                   push eax
// 006f6f9a  8d4c2410             lea ecx, [esp + 0x10]
// 006f6f9e  e8bd53edff           call 0x5cc360
// 006f6fa3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006f6fa7  84c0                 test al, al
// 006f6fa9  7507                 jne 0x6f6fb2
// 006f6fab  8b17                 mov edx, dword ptr [edi]
// 006f6fad  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 006f6fb0  7d3e                 jge 0x6f6ff0
// 006f6fb2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006f6fb6  8b5008               mov edx, dword ptr [eax + 8]
// 006f6fb9  807a1900             cmp byte ptr [edx + 0x19], 0
// 006f6fbd  57                   push edi
// 006f6fbe  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006f6fc2  7416                 je 0x6f6fda
// 006f6fc4  50                   push eax
// 006f6fc5  6a00                 push 0
// 006f6fc7  57                   push edi
// 006f6fc8  8bce                 mov ecx, esi
// 006f6fca  e8e1edffff           call 0x6f5db0
// 006f6fcf  5b                   pop ebx
// 006f6fd0  8bc7                 mov eax, edi
// 006f6fd2  5f                   pop edi
// 006f6fd3  5e                   pop esi
// 006f6fd4  83c414               add esp, 0x14
// 006f6fd7  c21000               ret 0x10
// 006f6fda  51                   push ecx
// 006f6fdb  6a01                 push 1
// 006f6fdd  57                   push edi
// 006f6fde  8bce                 mov ecx, esi
// 006f6fe0  e8cbedffff           call 0x6f5db0
// 006f6fe5  5b                   pop ebx
// 006f6fe6  8bc7                 mov eax, edi
// 006f6fe8  5f                   pop edi
// 006f6fe9  5e                   pop esi
// 006f6fea  83c414               add esp, 0x14
// 006f6fed  c21000               ret 0x10
// 006f6ff0  57                   push edi
// 006f6ff1  8d442418             lea eax, [esp + 0x18]
// 006f6ff5  50                   push eax
// 006f6ff6  8bce                 mov ecx, esi
// 006f6ff8  e863f5ffff           call 0x6f6560
// 006f6ffd  8b10                 mov edx, dword ptr [eax]
// 006f6fff  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006f7003  5b                   pop ebx
// 006f7004  8911                 mov dword ptr [ecx], edx
// 006f7006  8b4004               mov eax, dword ptr [eax + 4]
// 006f7009  5f                   pop edi
// 006f700a  894104               mov dword ptr [ecx + 4], eax
// 006f700d  8bc1                 mov eax, ecx
// 006f700f  5e                   pop esi
// 006f7010  83c414               add esp, 0x14
// 006f7013  c21000               ret 0x10
// standard library map_int<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
