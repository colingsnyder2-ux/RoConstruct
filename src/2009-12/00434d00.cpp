// from server: 100% by auto
// roc 2009-12 00434d00  unit: IIHAAH::?$CMap  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00434d00
//
// 00434d00  83ec14               sub esp, 0x14
// 00434d03  56                   push esi
// 00434d04  8bf1                 mov esi, ecx
// 00434d06  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 00434d0a  57                   push edi
// 00434d0b  7521                 jne 0x434d2e
// 00434d0d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00434d11  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00434d14  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00434d18  50                   push eax
// 00434d19  51                   push ecx
// 00434d1a  6a01                 push 1
// 00434d1c  57                   push edi
// 00434d1d  8bce                 mov ecx, esi
// 00434d1f  e88c102c00           call 0x6f5db0
// 00434d24  8bc7                 mov eax, edi
// 00434d26  5f                   pop edi
// 00434d27  5e                   pop esi
// 00434d28  83c414               add esp, 0x14
// 00434d2b  c21000               ret 0x10
// 00434d2e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00434d32  8b5618               mov edx, dword ptr [esi + 0x18]
// 00434d35  8b3a                 mov edi, dword ptr [edx]
// 00434d37  8b06                 mov eax, dword ptr [esi]
// 00434d39  53                   push ebx
// 00434d3a  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 00434d40  85c9                 test ecx, ecx
// 00434d42  7404                 je 0x434d48
// 00434d44  3bc8                 cmp ecx, eax
// 00434d46  7406                 je 0x434d4e
// 00434d48  ffd3                 call ebx
// 00434d4a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00434d4e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00434d52  3bc7                 cmp eax, edi
// 00434d54  752a                 jne 0x434d80
// 00434d56  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00434d5a  8b0f                 mov ecx, dword ptr [edi]
// 00434d5c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 00434d5f  0f834b010000         jae 0x434eb0
// 00434d65  57                   push edi
// 00434d66  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00434d6a  50                   push eax
// 00434d6b  6a01                 push 1
// 00434d6d  57                   push edi
// 00434d6e  8bce                 mov ecx, esi
// 00434d70  e83b102c00           call 0x6f5db0
// 00434d75  5b                   pop ebx
// 00434d76  8bc7                 mov eax, edi
// 00434d78  5f                   pop edi
// 00434d79  5e                   pop esi
// 00434d7a  83c414               add esp, 0x14
// 00434d7d  c21000               ret 0x10
// 00434d80  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00434d83  8b16                 mov edx, dword ptr [esi]
// 00434d85  85c9                 test ecx, ecx
// 00434d87  7404                 je 0x434d8d
// 00434d89  3bca                 cmp ecx, edx
// 00434d8b  740a                 je 0x434d97
// 00434d8d  ffd3                 call ebx
// 00434d8f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00434d93  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00434d97  3bc7                 cmp eax, edi
// 00434d99  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00434d9d  752c                 jne 0x434dcb
// 00434d9f  8b5618               mov edx, dword ptr [esi + 0x18]
// 00434da2  8b4208               mov eax, dword ptr [edx + 8]
// 00434da5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00434da8  3b0f                 cmp ecx, dword ptr [edi]
// 00434daa  0f8300010000         jae 0x434eb0
// 00434db0  57                   push edi
// 00434db1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00434db5  50                   push eax
// 00434db6  6a00                 push 0
// 00434db8  57                   push edi
// 00434db9  8bce                 mov ecx, esi
// 00434dbb  e8f00f2c00           call 0x6f5db0
// 00434dc0  5b                   pop ebx
// 00434dc1  8bc7                 mov eax, edi
// 00434dc3  5f                   pop edi
// 00434dc4  5e                   pop esi
// 00434dc5  83c414               add esp, 0x14
// 00434dc8  c21000               ret 0x10
// 00434dcb  8b17                 mov edx, dword ptr [edi]
// 00434dcd  39500c               cmp dword ptr [eax + 0xc], edx
// 00434dd0  7663                 jbe 0x434e35
// 00434dd2  894c240c             mov dword ptr [esp + 0xc], ecx
// 00434dd6  8d4c240c             lea ecx, [esp + 0xc]
// 00434dda  89442410             mov dword ptr [esp + 0x10], eax
// 00434dde  e8cd202400           call 0x676eb0
// 00434de3  8b17                 mov edx, dword ptr [edi]
// 00434de5  8b442410             mov eax, dword ptr [esp + 0x10]
// 00434de9  39500c               cmp dword ptr [eax + 0xc], edx
// 00434dec  733c                 jae 0x434e2a
// 00434dee  8b5008               mov edx, dword ptr [eax + 8]
// 00434df1  807a1900             cmp byte ptr [edx + 0x19], 0
// 00434df5  57                   push edi
// 00434df6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00434dfa  8bce                 mov ecx, esi
// 00434dfc  7414                 je 0x434e12
// 00434dfe  50                   push eax
// 00434dff  6a00                 push 0
// 00434e01  57                   push edi
// 00434e02  e8a90f2c00           call 0x6f5db0
// 00434e07  5b                   pop ebx
// 00434e08  8bc7                 mov eax, edi
// 00434e0a  5f                   pop edi
// 00434e0b  5e                   pop esi
// 00434e0c  83c414               add esp, 0x14
// 00434e0f  c21000               ret 0x10
// 00434e12  8b442430             mov eax, dword ptr [esp + 0x30]
// 00434e16  50                   push eax
// 00434e17  6a01                 push 1
// 00434e19  57                   push edi
// 00434e1a  e8910f2c00           call 0x6f5db0
// 00434e1f  5b                   pop ebx
// 00434e20  8bc7                 mov eax, edi
// 00434e22  5f                   pop edi
// 00434e23  5e                   pop esi
// 00434e24  83c414               add esp, 0x14
// 00434e27  c21000               ret 0x10
// 00434e2a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00434e2e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00434e32  39500c               cmp dword ptr [eax + 0xc], edx
// 00434e35  7379                 jae 0x434eb0
// 00434e37  8b16                 mov edx, dword ptr [esi]
// 00434e39  894c240c             mov dword ptr [esp + 0xc], ecx
// 00434e3d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00434e40  894c2418             mov dword ptr [esp + 0x18], ecx
// 00434e44  8d4c240c             lea ecx, [esp + 0xc]
// 00434e48  89442410             mov dword ptr [esp + 0x10], eax
// 00434e4c  89542414             mov dword ptr [esp + 0x14], edx
// 00434e50  e82b371000           call 0x538580
// 00434e55  8d442414             lea eax, [esp + 0x14]
// 00434e59  50                   push eax
// 00434e5a  8d4c2410             lea ecx, [esp + 0x10]
// 00434e5e  e8fd741900           call 0x5cc360
// 00434e63  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00434e67  84c0                 test al, al
// 00434e69  7507                 jne 0x434e72
// 00434e6b  8b17                 mov edx, dword ptr [edi]
// 00434e6d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00434e70  733e                 jae 0x434eb0
// 00434e72  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00434e76  8b5008               mov edx, dword ptr [eax + 8]
// 00434e79  807a1900             cmp byte ptr [edx + 0x19], 0
// 00434e7d  57                   push edi
// 00434e7e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00434e82  7416                 je 0x434e9a
// 00434e84  50                   push eax
// 00434e85  6a00                 push 0
// 00434e87  57                   push edi
// 00434e88  8bce                 mov ecx, esi
// 00434e8a  e8210f2c00           call 0x6f5db0
// 00434e8f  5b                   pop ebx
// 00434e90  8bc7                 mov eax, edi
// 00434e92  5f                   pop edi
// 00434e93  5e                   pop esi
// 00434e94  83c414               add esp, 0x14
// 00434e97  c21000               ret 0x10
// 00434e9a  51                   push ecx
// 00434e9b  6a01                 push 1
// 00434e9d  57                   push edi
// 00434e9e  8bce                 mov ecx, esi
// 00434ea0  e80b0f2c00           call 0x6f5db0
// 00434ea5  5b                   pop ebx
// 00434ea6  8bc7                 mov eax, edi
// 00434ea8  5f                   pop edi
// 00434ea9  5e                   pop esi
// 00434eaa  83c414               add esp, 0x14
// 00434ead  c21000               ret 0x10
// 00434eb0  57                   push edi
// 00434eb1  8d442418             lea eax, [esp + 0x18]
// 00434eb5  50                   push eax
// 00434eb6  8bce                 mov ecx, esi
// 00434eb8  e873f8ffff           call 0x434730
// 00434ebd  8b10                 mov edx, dword ptr [eax]
// 00434ebf  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00434ec3  5b                   pop ebx
// 00434ec4  8911                 mov dword ptr [ecx], edx
// 00434ec6  8b4004               mov eax, dword ptr [eax + 4]
// 00434ec9  5f                   pop edi
// 00434eca  894104               mov dword ptr [ecx + 4], eax
// 00434ecd  8bc1                 mov eax, ecx
// 00434ecf  5e                   pop esi
// 00434ed0  83c414               add esp, 0x14
// 00434ed3  c21000               ret 0x10
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
