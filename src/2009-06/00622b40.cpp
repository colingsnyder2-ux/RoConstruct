// from server: 100% by auto
// roc 2009-06 00622b40  unit: RBX::RootInstance  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00622b40
//
// 00622b40  83ec14               sub esp, 0x14
// 00622b43  56                   push esi
// 00622b44  8bf1                 mov esi, ecx
// 00622b46  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 00622b4a  57                   push edi
// 00622b4b  7521                 jne 0x622b6e
// 00622b4d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00622b51  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00622b54  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00622b58  50                   push eax
// 00622b59  51                   push ecx
// 00622b5a  6a01                 push 1
// 00622b5c  57                   push edi
// 00622b5d  8bce                 mov ecx, esi
// 00622b5f  e8ec1d0200           call 0x644950
// 00622b64  8bc7                 mov eax, edi
// 00622b66  5f                   pop edi
// 00622b67  5e                   pop esi
// 00622b68  83c414               add esp, 0x14
// 00622b6b  c21000               ret 0x10
// 00622b6e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00622b72  8b5618               mov edx, dword ptr [esi + 0x18]
// 00622b75  8b3a                 mov edi, dword ptr [edx]
// 00622b77  8b06                 mov eax, dword ptr [esi]
// 00622b79  53                   push ebx
// 00622b7a  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00622b80  85c9                 test ecx, ecx
// 00622b82  7404                 je 0x622b88
// 00622b84  3bc8                 cmp ecx, eax
// 00622b86  7406                 je 0x622b8e
// 00622b88  ffd3                 call ebx
// 00622b8a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00622b8e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00622b92  3bc7                 cmp eax, edi
// 00622b94  752a                 jne 0x622bc0
// 00622b96  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00622b9a  8b0f                 mov ecx, dword ptr [edi]
// 00622b9c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 00622b9f  0f834b010000         jae 0x622cf0
// 00622ba5  57                   push edi
// 00622ba6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00622baa  50                   push eax
// 00622bab  6a01                 push 1
// 00622bad  57                   push edi
// 00622bae  8bce                 mov ecx, esi
// 00622bb0  e89b1d0200           call 0x644950
// 00622bb5  5b                   pop ebx
// 00622bb6  8bc7                 mov eax, edi
// 00622bb8  5f                   pop edi
// 00622bb9  5e                   pop esi
// 00622bba  83c414               add esp, 0x14
// 00622bbd  c21000               ret 0x10
// 00622bc0  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00622bc3  8b16                 mov edx, dword ptr [esi]
// 00622bc5  85c9                 test ecx, ecx
// 00622bc7  7404                 je 0x622bcd
// 00622bc9  3bca                 cmp ecx, edx
// 00622bcb  740a                 je 0x622bd7
// 00622bcd  ffd3                 call ebx
// 00622bcf  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00622bd3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00622bd7  3bc7                 cmp eax, edi
// 00622bd9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00622bdd  752c                 jne 0x622c0b
// 00622bdf  8b5618               mov edx, dword ptr [esi + 0x18]
// 00622be2  8b4208               mov eax, dword ptr [edx + 8]
// 00622be5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00622be8  3b0f                 cmp ecx, dword ptr [edi]
// 00622bea  0f8300010000         jae 0x622cf0
// 00622bf0  57                   push edi
// 00622bf1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00622bf5  50                   push eax
// 00622bf6  6a00                 push 0
// 00622bf8  57                   push edi
// 00622bf9  8bce                 mov ecx, esi
// 00622bfb  e8501d0200           call 0x644950
// 00622c00  5b                   pop ebx
// 00622c01  8bc7                 mov eax, edi
// 00622c03  5f                   pop edi
// 00622c04  5e                   pop esi
// 00622c05  83c414               add esp, 0x14
// 00622c08  c21000               ret 0x10
// 00622c0b  8b17                 mov edx, dword ptr [edi]
// 00622c0d  39500c               cmp dword ptr [eax + 0xc], edx
// 00622c10  7663                 jbe 0x622c75
// 00622c12  894c240c             mov dword ptr [esp + 0xc], ecx
// 00622c16  8d4c240c             lea ecx, [esp + 0xc]
// 00622c1a  89442410             mov dword ptr [esp + 0x10], eax
// 00622c1e  e88d12ecff           call 0x4e3eb0
// 00622c23  8b17                 mov edx, dword ptr [edi]
// 00622c25  8b442410             mov eax, dword ptr [esp + 0x10]
// 00622c29  39500c               cmp dword ptr [eax + 0xc], edx
// 00622c2c  733c                 jae 0x622c6a
// 00622c2e  8b5008               mov edx, dword ptr [eax + 8]
// 00622c31  807a1900             cmp byte ptr [edx + 0x19], 0
// 00622c35  57                   push edi
// 00622c36  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00622c3a  8bce                 mov ecx, esi
// 00622c3c  7414                 je 0x622c52
// 00622c3e  50                   push eax
// 00622c3f  6a00                 push 0
// 00622c41  57                   push edi
// 00622c42  e8091d0200           call 0x644950
// 00622c47  5b                   pop ebx
// 00622c48  8bc7                 mov eax, edi
// 00622c4a  5f                   pop edi
// 00622c4b  5e                   pop esi
// 00622c4c  83c414               add esp, 0x14
// 00622c4f  c21000               ret 0x10
// 00622c52  8b442430             mov eax, dword ptr [esp + 0x30]
// 00622c56  50                   push eax
// 00622c57  6a01                 push 1
// 00622c59  57                   push edi
// 00622c5a  e8f11c0200           call 0x644950
// 00622c5f  5b                   pop ebx
// 00622c60  8bc7                 mov eax, edi
// 00622c62  5f                   pop edi
// 00622c63  5e                   pop esi
// 00622c64  83c414               add esp, 0x14
// 00622c67  c21000               ret 0x10
// 00622c6a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00622c6e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00622c72  39500c               cmp dword ptr [eax + 0xc], edx
// 00622c75  7379                 jae 0x622cf0
// 00622c77  8b16                 mov edx, dword ptr [esi]
// 00622c79  894c240c             mov dword ptr [esp + 0xc], ecx
// 00622c7d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00622c80  894c2418             mov dword ptr [esp + 0x18], ecx
// 00622c84  8d4c240c             lea ecx, [esp + 0xc]
// 00622c88  89442410             mov dword ptr [esp + 0x10], eax
// 00622c8c  89542414             mov dword ptr [esp + 0x14], edx
// 00622c90  e82bf6ffff           call 0x6222c0
// 00622c95  8d442414             lea eax, [esp + 0x14]
// 00622c99  50                   push eax
// 00622c9a  8d4c2410             lea ecx, [esp + 0x10]
// 00622c9e  e8fd070200           call 0x6434a0
// 00622ca3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00622ca7  84c0                 test al, al
// 00622ca9  7507                 jne 0x622cb2
// 00622cab  8b17                 mov edx, dword ptr [edi]
// 00622cad  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00622cb0  733e                 jae 0x622cf0
// 00622cb2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00622cb6  8b5008               mov edx, dword ptr [eax + 8]
// 00622cb9  807a1900             cmp byte ptr [edx + 0x19], 0
// 00622cbd  57                   push edi
// 00622cbe  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00622cc2  7416                 je 0x622cda
// 00622cc4  50                   push eax
// 00622cc5  6a00                 push 0
// 00622cc7  57                   push edi
// 00622cc8  8bce                 mov ecx, esi
// 00622cca  e8811c0200           call 0x644950
// 00622ccf  5b                   pop ebx
// 00622cd0  8bc7                 mov eax, edi
// 00622cd2  5f                   pop edi
// 00622cd3  5e                   pop esi
// 00622cd4  83c414               add esp, 0x14
// 00622cd7  c21000               ret 0x10
// 00622cda  51                   push ecx
// 00622cdb  6a01                 push 1
// 00622cdd  57                   push edi
// 00622cde  8bce                 mov ecx, esi
// 00622ce0  e86b1c0200           call 0x644950
// 00622ce5  5b                   pop ebx
// 00622ce6  8bc7                 mov eax, edi
// 00622ce8  5f                   pop edi
// 00622ce9  5e                   pop esi
// 00622cea  83c414               add esp, 0x14
// 00622ced  c21000               ret 0x10
// 00622cf0  57                   push edi
// 00622cf1  8d442418             lea eax, [esp + 0x18]
// 00622cf5  50                   push eax
// 00622cf6  8bce                 mov ecx, esi
// 00622cf8  e853fdffff           call 0x622a50
// 00622cfd  8b10                 mov edx, dword ptr [eax]
// 00622cff  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00622d03  5b                   pop ebx
// 00622d04  8911                 mov dword ptr [ecx], edx
// 00622d06  8b4004               mov eax, dword ptr [eax + 4]
// 00622d09  5f                   pop edi
// 00622d0a  894104               mov dword ptr [ecx + 4], eax
// 00622d0d  8bc1                 mov eax, ecx
// 00622d0f  5e                   pop esi
// 00622d10  83c414               add esp, 0x14
// 00622d13  c21000               ret 0x10
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
