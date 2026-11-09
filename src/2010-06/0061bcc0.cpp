// from server: 100% by auto
// roc 2010-06 0061bcc0  unit: RBX::Accoutrement  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0061bcc0
//
// 0061bcc0  83ec14               sub esp, 0x14
// 0061bcc3  56                   push esi
// 0061bcc4  8bf1                 mov esi, ecx
// 0061bcc6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0061bcca  57                   push edi
// 0061bccb  7521                 jne 0x61bcee
// 0061bccd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0061bcd1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0061bcd4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0061bcd8  50                   push eax
// 0061bcd9  51                   push ecx
// 0061bcda  6a01                 push 1
// 0061bcdc  57                   push edi
// 0061bcdd  8bce                 mov ecx, esi
// 0061bcdf  e82cf5ffff           call 0x61b210
// 0061bce4  8bc7                 mov eax, edi
// 0061bce6  5f                   pop edi
// 0061bce7  5e                   pop esi
// 0061bce8  83c414               add esp, 0x14
// 0061bceb  c21000               ret 0x10
// 0061bcee  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0061bcf2  8b5618               mov edx, dword ptr [esi + 0x18]
// 0061bcf5  8b3a                 mov edi, dword ptr [edx]
// 0061bcf7  8b06                 mov eax, dword ptr [esi]
// 0061bcf9  53                   push ebx
// 0061bcfa  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 0061bd00  85c9                 test ecx, ecx
// 0061bd02  7404                 je 0x61bd08
// 0061bd04  3bc8                 cmp ecx, eax
// 0061bd06  7406                 je 0x61bd0e
// 0061bd08  ffd3                 call ebx
// 0061bd0a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0061bd0e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0061bd12  3bc7                 cmp eax, edi
// 0061bd14  752a                 jne 0x61bd40
// 0061bd16  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0061bd1a  8b0f                 mov ecx, dword ptr [edi]
// 0061bd1c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0061bd1f  0f8d4b010000         jge 0x61be70
// 0061bd25  57                   push edi
// 0061bd26  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0061bd2a  50                   push eax
// 0061bd2b  6a01                 push 1
// 0061bd2d  57                   push edi
// 0061bd2e  8bce                 mov ecx, esi
// 0061bd30  e8dbf4ffff           call 0x61b210
// 0061bd35  5b                   pop ebx
// 0061bd36  8bc7                 mov eax, edi
// 0061bd38  5f                   pop edi
// 0061bd39  5e                   pop esi
// 0061bd3a  83c414               add esp, 0x14
// 0061bd3d  c21000               ret 0x10
// 0061bd40  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0061bd43  8b16                 mov edx, dword ptr [esi]
// 0061bd45  85c9                 test ecx, ecx
// 0061bd47  7404                 je 0x61bd4d
// 0061bd49  3bca                 cmp ecx, edx
// 0061bd4b  740a                 je 0x61bd57
// 0061bd4d  ffd3                 call ebx
// 0061bd4f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0061bd53  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0061bd57  3bc7                 cmp eax, edi
// 0061bd59  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0061bd5d  752c                 jne 0x61bd8b
// 0061bd5f  8b5618               mov edx, dword ptr [esi + 0x18]
// 0061bd62  8b4208               mov eax, dword ptr [edx + 8]
// 0061bd65  8b480c               mov ecx, dword ptr [eax + 0xc]
// 0061bd68  3b0f                 cmp ecx, dword ptr [edi]
// 0061bd6a  0f8d00010000         jge 0x61be70
// 0061bd70  57                   push edi
// 0061bd71  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0061bd75  50                   push eax
// 0061bd76  6a00                 push 0
// 0061bd78  57                   push edi
// 0061bd79  8bce                 mov ecx, esi
// 0061bd7b  e890f4ffff           call 0x61b210
// 0061bd80  5b                   pop ebx
// 0061bd81  8bc7                 mov eax, edi
// 0061bd83  5f                   pop edi
// 0061bd84  5e                   pop esi
// 0061bd85  83c414               add esp, 0x14
// 0061bd88  c21000               ret 0x10
// 0061bd8b  8b17                 mov edx, dword ptr [edi]
// 0061bd8d  39500c               cmp dword ptr [eax + 0xc], edx
// 0061bd90  7e63                 jle 0x61bdf5
// 0061bd92  894c240c             mov dword ptr [esp + 0xc], ecx
// 0061bd96  8d4c240c             lea ecx, [esp + 0xc]
// 0061bd9a  89442410             mov dword ptr [esp + 0x10], eax
// 0061bd9e  e87d12f1ff           call 0x52d020
// 0061bda3  8b17                 mov edx, dword ptr [edi]
// 0061bda5  8b442410             mov eax, dword ptr [esp + 0x10]
// 0061bda9  39500c               cmp dword ptr [eax + 0xc], edx
// 0061bdac  7d3c                 jge 0x61bdea
// 0061bdae  8b5008               mov edx, dword ptr [eax + 8]
// 0061bdb1  807a2100             cmp byte ptr [edx + 0x21], 0
// 0061bdb5  57                   push edi
// 0061bdb6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0061bdba  8bce                 mov ecx, esi
// 0061bdbc  7414                 je 0x61bdd2
// 0061bdbe  50                   push eax
// 0061bdbf  6a00                 push 0
// 0061bdc1  57                   push edi
// 0061bdc2  e849f4ffff           call 0x61b210
// 0061bdc7  5b                   pop ebx
// 0061bdc8  8bc7                 mov eax, edi
// 0061bdca  5f                   pop edi
// 0061bdcb  5e                   pop esi
// 0061bdcc  83c414               add esp, 0x14
// 0061bdcf  c21000               ret 0x10
// 0061bdd2  8b442430             mov eax, dword ptr [esp + 0x30]
// 0061bdd6  50                   push eax
// 0061bdd7  6a01                 push 1
// 0061bdd9  57                   push edi
// 0061bdda  e831f4ffff           call 0x61b210
// 0061bddf  5b                   pop ebx
// 0061bde0  8bc7                 mov eax, edi
// 0061bde2  5f                   pop edi
// 0061bde3  5e                   pop esi
// 0061bde4  83c414               add esp, 0x14
// 0061bde7  c21000               ret 0x10
// 0061bdea  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0061bdee  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0061bdf2  39500c               cmp dword ptr [eax + 0xc], edx
// 0061bdf5  7d79                 jge 0x61be70
// 0061bdf7  8b16                 mov edx, dword ptr [esi]
// 0061bdf9  894c240c             mov dword ptr [esp + 0xc], ecx
// 0061bdfd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0061be00  894c2418             mov dword ptr [esp + 0x18], ecx
// 0061be04  8d4c240c             lea ecx, [esp + 0xc]
// 0061be08  89442410             mov dword ptr [esp + 0x10], eax
// 0061be0c  89542414             mov dword ptr [esp + 0x14], edx
// 0061be10  e8ebf2ffff           call 0x61b100
// 0061be15  8d442414             lea eax, [esp + 0x14]
// 0061be19  50                   push eax
// 0061be1a  8d4c2410             lea ecx, [esp + 0x10]
// 0061be1e  e85db1e4ff           call 0x466f80
// 0061be23  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0061be27  84c0                 test al, al
// 0061be29  7507                 jne 0x61be32
// 0061be2b  8b17                 mov edx, dword ptr [edi]
// 0061be2d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 0061be30  7d3e                 jge 0x61be70
// 0061be32  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0061be36  8b5008               mov edx, dword ptr [eax + 8]
// 0061be39  807a2100             cmp byte ptr [edx + 0x21], 0
// 0061be3d  57                   push edi
// 0061be3e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0061be42  7416                 je 0x61be5a
// 0061be44  50                   push eax
// 0061be45  6a00                 push 0
// 0061be47  57                   push edi
// 0061be48  8bce                 mov ecx, esi
// 0061be4a  e8c1f3ffff           call 0x61b210
// 0061be4f  5b                   pop ebx
// 0061be50  8bc7                 mov eax, edi
// 0061be52  5f                   pop edi
// 0061be53  5e                   pop esi
// 0061be54  83c414               add esp, 0x14
// 0061be57  c21000               ret 0x10
// 0061be5a  51                   push ecx
// 0061be5b  6a01                 push 1
// 0061be5d  57                   push edi
// 0061be5e  8bce                 mov ecx, esi
// 0061be60  e8abf3ffff           call 0x61b210
// 0061be65  5b                   pop ebx
// 0061be66  8bc7                 mov eax, edi
// 0061be68  5f                   pop edi
// 0061be69  5e                   pop esi
// 0061be6a  83c414               add esp, 0x14
// 0061be6d  c21000               ret 0x10
// 0061be70  57                   push edi
// 0061be71  8d442418             lea eax, [esp + 0x18]
// 0061be75  50                   push eax
// 0061be76  8bce                 mov ecx, esi
// 0061be78  e843fbffff           call 0x61b9c0
// 0061be7d  8b10                 mov edx, dword ptr [eax]
// 0061be7f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0061be83  5b                   pop ebx
// 0061be84  8911                 mov dword ptr [ecx], edx
// 0061be86  8b4004               mov eax, dword ptr [eax + 4]
// 0061be89  5f                   pop edi
// 0061be8a  894104               mov dword ptr [ecx + 4], eax
// 0061be8d  8bc1                 mov eax, ecx
// 0061be8f  5e                   pop esi
// 0061be90  83c414               add esp, 0x14
// 0061be93  c21000               ret 0x10
// standard library map_int<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
