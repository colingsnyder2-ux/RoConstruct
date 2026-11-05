// from server: 100% by auto
// roc 2010-06 007a1bf0  unit: W4_D3DFORMAT::?$EnumDesc  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007a1bf0
//
// 007a1bf0  83ec14               sub esp, 0x14
// 007a1bf3  56                   push esi
// 007a1bf4  8bf1                 mov esi, ecx
// 007a1bf6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 007a1bfa  57                   push edi
// 007a1bfb  7521                 jne 0x7a1c1e
// 007a1bfd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007a1c01  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007a1c04  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007a1c08  50                   push eax
// 007a1c09  51                   push ecx
// 007a1c0a  6a01                 push 1
// 007a1c0c  57                   push edi
// 007a1c0d  8bce                 mov ecx, esi
// 007a1c0f  e89cfcffff           call 0x7a18b0
// 007a1c14  8bc7                 mov eax, edi
// 007a1c16  5f                   pop edi
// 007a1c17  5e                   pop esi
// 007a1c18  83c414               add esp, 0x14
// 007a1c1b  c21000               ret 0x10
// 007a1c1e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007a1c22  8b5618               mov edx, dword ptr [esi + 0x18]
// 007a1c25  8b3a                 mov edi, dword ptr [edx]
// 007a1c27  8b06                 mov eax, dword ptr [esi]
// 007a1c29  53                   push ebx
// 007a1c2a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 007a1c30  85c9                 test ecx, ecx
// 007a1c32  7404                 je 0x7a1c38
// 007a1c34  3bc8                 cmp ecx, eax
// 007a1c36  7406                 je 0x7a1c3e
// 007a1c38  ffd3                 call ebx
// 007a1c3a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007a1c3e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007a1c42  3bc7                 cmp eax, edi
// 007a1c44  752a                 jne 0x7a1c70
// 007a1c46  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 007a1c4a  8b0f                 mov ecx, dword ptr [edi]
// 007a1c4c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 007a1c4f  0f834b010000         jae 0x7a1da0
// 007a1c55  57                   push edi
// 007a1c56  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007a1c5a  50                   push eax
// 007a1c5b  6a01                 push 1
// 007a1c5d  57                   push edi
// 007a1c5e  8bce                 mov ecx, esi
// 007a1c60  e84bfcffff           call 0x7a18b0
// 007a1c65  5b                   pop ebx
// 007a1c66  8bc7                 mov eax, edi
// 007a1c68  5f                   pop edi
// 007a1c69  5e                   pop esi
// 007a1c6a  83c414               add esp, 0x14
// 007a1c6d  c21000               ret 0x10
// 007a1c70  8b7e18               mov edi, dword ptr [esi + 0x18]
// 007a1c73  8b16                 mov edx, dword ptr [esi]
// 007a1c75  85c9                 test ecx, ecx
// 007a1c77  7404                 je 0x7a1c7d
// 007a1c79  3bca                 cmp ecx, edx
// 007a1c7b  740a                 je 0x7a1c87
// 007a1c7d  ffd3                 call ebx
// 007a1c7f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007a1c83  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007a1c87  3bc7                 cmp eax, edi
// 007a1c89  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 007a1c8d  752c                 jne 0x7a1cbb
// 007a1c8f  8b5618               mov edx, dword ptr [esi + 0x18]
// 007a1c92  8b4208               mov eax, dword ptr [edx + 8]
// 007a1c95  8b480c               mov ecx, dword ptr [eax + 0xc]
// 007a1c98  3b0f                 cmp ecx, dword ptr [edi]
// 007a1c9a  0f8300010000         jae 0x7a1da0
// 007a1ca0  57                   push edi
// 007a1ca1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007a1ca5  50                   push eax
// 007a1ca6  6a00                 push 0
// 007a1ca8  57                   push edi
// 007a1ca9  8bce                 mov ecx, esi
// 007a1cab  e800fcffff           call 0x7a18b0
// 007a1cb0  5b                   pop ebx
// 007a1cb1  8bc7                 mov eax, edi
// 007a1cb3  5f                   pop edi
// 007a1cb4  5e                   pop esi
// 007a1cb5  83c414               add esp, 0x14
// 007a1cb8  c21000               ret 0x10
// 007a1cbb  8b17                 mov edx, dword ptr [edi]
// 007a1cbd  39500c               cmp dword ptr [eax + 0xc], edx
// 007a1cc0  7663                 jbe 0x7a1d25
// 007a1cc2  894c240c             mov dword ptr [esp + 0xc], ecx
// 007a1cc6  8d4c240c             lea ecx, [esp + 0xc]
// 007a1cca  89442410             mov dword ptr [esp + 0x10], eax
// 007a1cce  e86d7ff6ff           call 0x709c40
// 007a1cd3  8b17                 mov edx, dword ptr [edi]
// 007a1cd5  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a1cd9  39500c               cmp dword ptr [eax + 0xc], edx
// 007a1cdc  733c                 jae 0x7a1d1a
// 007a1cde  8b5008               mov edx, dword ptr [eax + 8]
// 007a1ce1  807a1500             cmp byte ptr [edx + 0x15], 0
// 007a1ce5  57                   push edi
// 007a1ce6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007a1cea  8bce                 mov ecx, esi
// 007a1cec  7414                 je 0x7a1d02
// 007a1cee  50                   push eax
// 007a1cef  6a00                 push 0
// 007a1cf1  57                   push edi
// 007a1cf2  e8b9fbffff           call 0x7a18b0
// 007a1cf7  5b                   pop ebx
// 007a1cf8  8bc7                 mov eax, edi
// 007a1cfa  5f                   pop edi
// 007a1cfb  5e                   pop esi
// 007a1cfc  83c414               add esp, 0x14
// 007a1cff  c21000               ret 0x10
// 007a1d02  8b442430             mov eax, dword ptr [esp + 0x30]
// 007a1d06  50                   push eax
// 007a1d07  6a01                 push 1
// 007a1d09  57                   push edi
// 007a1d0a  e8a1fbffff           call 0x7a18b0
// 007a1d0f  5b                   pop ebx
// 007a1d10  8bc7                 mov eax, edi
// 007a1d12  5f                   pop edi
// 007a1d13  5e                   pop esi
// 007a1d14  83c414               add esp, 0x14
// 007a1d17  c21000               ret 0x10
// 007a1d1a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007a1d1e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007a1d22  39500c               cmp dword ptr [eax + 0xc], edx
// 007a1d25  7379                 jae 0x7a1da0
// 007a1d27  8b16                 mov edx, dword ptr [esi]
// 007a1d29  894c240c             mov dword ptr [esp + 0xc], ecx
// 007a1d2d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007a1d30  894c2418             mov dword ptr [esp + 0x18], ecx
// 007a1d34  8d4c240c             lea ecx, [esp + 0xc]
// 007a1d38  89442410             mov dword ptr [esp + 0x10], eax
// 007a1d3c  89542414             mov dword ptr [esp + 0x14], edx
// 007a1d40  e89b5cf4ff           call 0x6e79e0
// 007a1d45  8d442414             lea eax, [esp + 0x14]
// 007a1d49  50                   push eax
// 007a1d4a  8d4c2410             lea ecx, [esp + 0x10]
// 007a1d4e  e82d52ccff           call 0x466f80
// 007a1d53  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007a1d57  84c0                 test al, al
// 007a1d59  7507                 jne 0x7a1d62
// 007a1d5b  8b17                 mov edx, dword ptr [edi]
// 007a1d5d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 007a1d60  733e                 jae 0x7a1da0
// 007a1d62  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007a1d66  8b5008               mov edx, dword ptr [eax + 8]
// 007a1d69  807a1500             cmp byte ptr [edx + 0x15], 0
// 007a1d6d  57                   push edi
// 007a1d6e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007a1d72  7416                 je 0x7a1d8a
// 007a1d74  50                   push eax
// 007a1d75  6a00                 push 0
// 007a1d77  57                   push edi
// 007a1d78  8bce                 mov ecx, esi
// 007a1d7a  e831fbffff           call 0x7a18b0
// 007a1d7f  5b                   pop ebx
// 007a1d80  8bc7                 mov eax, edi
// 007a1d82  5f                   pop edi
// 007a1d83  5e                   pop esi
// 007a1d84  83c414               add esp, 0x14
// 007a1d87  c21000               ret 0x10
// 007a1d8a  51                   push ecx
// 007a1d8b  6a01                 push 1
// 007a1d8d  57                   push edi
// 007a1d8e  8bce                 mov ecx, esi
// 007a1d90  e81bfbffff           call 0x7a18b0
// 007a1d95  5b                   pop ebx
// 007a1d96  8bc7                 mov eax, edi
// 007a1d98  5f                   pop edi
// 007a1d99  5e                   pop esi
// 007a1d9a  83c414               add esp, 0x14
// 007a1d9d  c21000               ret 0x10
// 007a1da0  57                   push edi
// 007a1da1  8d442418             lea eax, [esp + 0x18]
// 007a1da5  50                   push eax
// 007a1da6  8bce                 mov ecx, esi
// 007a1da8  e853fdffff           call 0x7a1b00
// 007a1dad  8b10                 mov edx, dword ptr [eax]
// 007a1daf  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007a1db3  5b                   pop ebx
// 007a1db4  8911                 mov dword ptr [ecx], edx
// 007a1db6  8b4004               mov eax, dword ptr [eax + 4]
// 007a1db9  5f                   pop edi
// 007a1dba  894104               mov dword ptr [ecx + 4], eax
// 007a1dbd  8bc1                 mov eax, ecx
// 007a1dbf  5e                   pop esi
// 007a1dc0  83c414               add esp, 0x14
// 007a1dc3  c21000               ret 0x10
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
