// from server: 100% by auto
// roc 2009-06 00433890  unit: IIHAAH::?$CMap  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00433890
//
// 00433890  83ec14               sub esp, 0x14
// 00433893  56                   push esi
// 00433894  8bf1                 mov esi, ecx
// 00433896  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0043389a  57                   push edi
// 0043389b  7521                 jne 0x4338be
// 0043389d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004338a1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004338a4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004338a8  50                   push eax
// 004338a9  51                   push ecx
// 004338aa  6a01                 push 1
// 004338ac  57                   push edi
// 004338ad  8bce                 mov ecx, esi
// 004338af  e8ecf1ffff           call 0x432aa0
// 004338b4  8bc7                 mov eax, edi
// 004338b6  5f                   pop edi
// 004338b7  5e                   pop esi
// 004338b8  83c414               add esp, 0x14
// 004338bb  c21000               ret 0x10
// 004338be  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004338c2  8b5618               mov edx, dword ptr [esi + 0x18]
// 004338c5  8b3a                 mov edi, dword ptr [edx]
// 004338c7  8b06                 mov eax, dword ptr [esi]
// 004338c9  53                   push ebx
// 004338ca  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 004338d0  85c9                 test ecx, ecx
// 004338d2  7404                 je 0x4338d8
// 004338d4  3bc8                 cmp ecx, eax
// 004338d6  7406                 je 0x4338de
// 004338d8  ffd3                 call ebx
// 004338da  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004338de  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004338e2  3bc7                 cmp eax, edi
// 004338e4  752a                 jne 0x433910
// 004338e6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 004338ea  8b0f                 mov ecx, dword ptr [edi]
// 004338ec  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 004338ef  0f834b010000         jae 0x433a40
// 004338f5  57                   push edi
// 004338f6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004338fa  50                   push eax
// 004338fb  6a01                 push 1
// 004338fd  57                   push edi
// 004338fe  8bce                 mov ecx, esi
// 00433900  e89bf1ffff           call 0x432aa0
// 00433905  5b                   pop ebx
// 00433906  8bc7                 mov eax, edi
// 00433908  5f                   pop edi
// 00433909  5e                   pop esi
// 0043390a  83c414               add esp, 0x14
// 0043390d  c21000               ret 0x10
// 00433910  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00433913  8b16                 mov edx, dword ptr [esi]
// 00433915  85c9                 test ecx, ecx
// 00433917  7404                 je 0x43391d
// 00433919  3bca                 cmp ecx, edx
// 0043391b  740a                 je 0x433927
// 0043391d  ffd3                 call ebx
// 0043391f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00433923  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00433927  3bc7                 cmp eax, edi
// 00433929  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0043392d  752c                 jne 0x43395b
// 0043392f  8b5618               mov edx, dword ptr [esi + 0x18]
// 00433932  8b4208               mov eax, dword ptr [edx + 8]
// 00433935  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00433938  3b0f                 cmp ecx, dword ptr [edi]
// 0043393a  0f8300010000         jae 0x433a40
// 00433940  57                   push edi
// 00433941  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00433945  50                   push eax
// 00433946  6a00                 push 0
// 00433948  57                   push edi
// 00433949  8bce                 mov ecx, esi
// 0043394b  e850f1ffff           call 0x432aa0
// 00433950  5b                   pop ebx
// 00433951  8bc7                 mov eax, edi
// 00433953  5f                   pop edi
// 00433954  5e                   pop esi
// 00433955  83c414               add esp, 0x14
// 00433958  c21000               ret 0x10
// 0043395b  8b17                 mov edx, dword ptr [edi]
// 0043395d  39500c               cmp dword ptr [eax + 0xc], edx
// 00433960  7663                 jbe 0x4339c5
// 00433962  894c240c             mov dword ptr [esp + 0xc], ecx
// 00433966  8d4c240c             lea ecx, [esp + 0xc]
// 0043396a  89442410             mov dword ptr [esp + 0x10], eax
// 0043396e  e83d050b00           call 0x4e3eb0
// 00433973  8b17                 mov edx, dword ptr [edi]
// 00433975  8b442410             mov eax, dword ptr [esp + 0x10]
// 00433979  39500c               cmp dword ptr [eax + 0xc], edx
// 0043397c  733c                 jae 0x4339ba
// 0043397e  8b5008               mov edx, dword ptr [eax + 8]
// 00433981  807a1900             cmp byte ptr [edx + 0x19], 0
// 00433985  57                   push edi
// 00433986  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0043398a  8bce                 mov ecx, esi
// 0043398c  7414                 je 0x4339a2
// 0043398e  50                   push eax
// 0043398f  6a00                 push 0
// 00433991  57                   push edi
// 00433992  e809f1ffff           call 0x432aa0
// 00433997  5b                   pop ebx
// 00433998  8bc7                 mov eax, edi
// 0043399a  5f                   pop edi
// 0043399b  5e                   pop esi
// 0043399c  83c414               add esp, 0x14
// 0043399f  c21000               ret 0x10
// 004339a2  8b442430             mov eax, dword ptr [esp + 0x30]
// 004339a6  50                   push eax
// 004339a7  6a01                 push 1
// 004339a9  57                   push edi
// 004339aa  e8f1f0ffff           call 0x432aa0
// 004339af  5b                   pop ebx
// 004339b0  8bc7                 mov eax, edi
// 004339b2  5f                   pop edi
// 004339b3  5e                   pop esi
// 004339b4  83c414               add esp, 0x14
// 004339b7  c21000               ret 0x10
// 004339ba  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004339be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004339c2  39500c               cmp dword ptr [eax + 0xc], edx
// 004339c5  7379                 jae 0x433a40
// 004339c7  8b16                 mov edx, dword ptr [esi]
// 004339c9  894c240c             mov dword ptr [esp + 0xc], ecx
// 004339cd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004339d0  894c2418             mov dword ptr [esp + 0x18], ecx
// 004339d4  8d4c240c             lea ecx, [esp + 0xc]
// 004339d8  89442410             mov dword ptr [esp + 0x10], eax
// 004339dc  89542414             mov dword ptr [esp + 0x14], edx
// 004339e0  e8dbe81e00           call 0x6222c0
// 004339e5  8d442414             lea eax, [esp + 0x14]
// 004339e9  50                   push eax
// 004339ea  8d4c2410             lea ecx, [esp + 0x10]
// 004339ee  e8adfa2000           call 0x6434a0
// 004339f3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004339f7  84c0                 test al, al
// 004339f9  7507                 jne 0x433a02
// 004339fb  8b17                 mov edx, dword ptr [edi]
// 004339fd  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00433a00  733e                 jae 0x433a40
// 00433a02  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00433a06  8b5008               mov edx, dword ptr [eax + 8]
// 00433a09  807a1900             cmp byte ptr [edx + 0x19], 0
// 00433a0d  57                   push edi
// 00433a0e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00433a12  7416                 je 0x433a2a
// 00433a14  50                   push eax
// 00433a15  6a00                 push 0
// 00433a17  57                   push edi
// 00433a18  8bce                 mov ecx, esi
// 00433a1a  e881f0ffff           call 0x432aa0
// 00433a1f  5b                   pop ebx
// 00433a20  8bc7                 mov eax, edi
// 00433a22  5f                   pop edi
// 00433a23  5e                   pop esi
// 00433a24  83c414               add esp, 0x14
// 00433a27  c21000               ret 0x10
// 00433a2a  51                   push ecx
// 00433a2b  6a01                 push 1
// 00433a2d  57                   push edi
// 00433a2e  8bce                 mov ecx, esi
// 00433a30  e86bf0ffff           call 0x432aa0
// 00433a35  5b                   pop ebx
// 00433a36  8bc7                 mov eax, edi
// 00433a38  5f                   pop edi
// 00433a39  5e                   pop esi
// 00433a3a  83c414               add esp, 0x14
// 00433a3d  c21000               ret 0x10
// 00433a40  57                   push edi
// 00433a41  8d442418             lea eax, [esp + 0x18]
// 00433a45  50                   push eax
// 00433a46  8bce                 mov ecx, esi
// 00433a48  e873f5ffff           call 0x432fc0
// 00433a4d  8b10                 mov edx, dword ptr [eax]
// 00433a4f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00433a53  5b                   pop ebx
// 00433a54  8911                 mov dword ptr [ecx], edx
// 00433a56  8b4004               mov eax, dword ptr [eax + 4]
// 00433a59  5f                   pop edi
// 00433a5a  894104               mov dword ptr [ecx + 4], eax
// 00433a5d  8bc1                 mov eax, ecx
// 00433a5f  5e                   pop esi
// 00433a60  83c414               add esp, 0x14
// 00433a63  c21000               ret 0x10
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
